#include "stdafx.h"
#include "Enemy.h"

void Enemy::initVariable()
{   
    this->wave = 1;
    this->point = 0;
    this->enemySpawnTimer;
    this->maxEnemies = wave * 6;
    this->maxHP = 4;
    this->nEnemies = 0;
    this->nSpawn = 1;
    this->rectSource = IntRect(0, 0, 27, 24);
    this->over = 0;
    this->goldState = 0;
    this->wavesound = 1;
}

void Enemy::initMusic()
{
    if (!boost.openFromFile("Music/boost.mp3"))
    {
        cout << "boost-ERROR" << endl;
    }
    boost.setVolume(100);
    for (int i = 0; i < 40; i++)
    {
        if (!hitMusic[i].openFromFile("Music/hit.mp3"))
        {
            cout << "boost-ERROR" << endl;
        }
        hitMusic[i].setVolume(50);
        if (!deadMusic[i].openFromFile("Music/dead.mp3"))
        {
            cout << "boost-ERROR" << endl;
        }
        deadMusic[i].setVolume(50);
    }
    

    if (!waveMusic.openFromFile("Music/wave.wav"))
    {
        cout << "boost-ERROR" << endl;
    }

}

void Enemy::initTexture()
{
    if (!this->enemyTexture.loadFromFile("Texture/enemy.png"))
    {
        cout << "enemy-ERROR";
    }
    if (!this->goldenTexture.loadFromFile("Texture/golden.png"))
    {
        cout << "enemy-ERROR";
    }
    if (!this->feverTexture.loadFromFile("Texture/fever.png"))
    {
        cout << "enemy-ERROR";
    }
}

void Enemy::initSprite()
{   
    this->enemy.setTexture(this->enemyTexture);
    this->enemy.setTextureRect(rectSource);
    this->feverEf.setTexture(this->feverTexture);
}


const Sprite& Enemy::getSprite(int i) const
{
    return this->enemies[i];
}

Enemy::Enemy()
{
    this->initMusic();
    this->initVariable();
    this->initTexture();
    this->initSprite();
}

Enemy::~Enemy()
{

}

void Enemy::enemySpawn()
{
    //Location
    int yLocation[5] = { 954,808,662,516,375 };
    int slow = rand() % 80;
    this->enemy.setPosition(

        1920.f + slow,
        static_cast<float>(yLocation[rand() % (sizeof(yLocation) / sizeof(yLocation[0]))])
    );
    
    // Increase the width while maintaining aspect ratio
    float scaleFactor = 3.0f; // Increase width by a factor of 2
    enemy.setScale(sf::Vector2f(scaleFactor, scaleFactor));
    this->enemies.push_back(this->enemy);
    this->nEnemies += 1;
    this->points.push_back(this->wave);
    this->unmove.push_back(0);
    
    //golden random
    if (rand() % 20 == 0)
    {
        this->enemies[enemies.size() - 1].setTexture(this->goldenTexture);
        this->currentHP.push_back(this->maxHP + wave);
        this->gold.push_back(1);
    }
    else
    {   
        this->currentHP.push_back(this->maxHP);
        this->gold.push_back(0);
    }
}

void Enemy::reduceHP(int i,int damage)
{       
    if (damage >= 4)
    {
        currentHP[i] -= 4;
    }
    else
    {
        currentHP[i] -= damage;
    }
    if (currentHP[i] <= 0)
    {   
        this->deadMusic[i].play();
        deletion(this->enemies[i].getPosition());
    }
    else
    {
        this->hitMusic[i].play();
    }

}


void Enemy::deletion(Vector2f position)
{
    for (int i = 0; i < this->enemies.size(); i++)
    {
        if (this->enemies[i].getPosition() == position)
        {
            if (this->gold[i] == 1 && over == 0)
            {
                goldState = 1;
                boost.play();
                this->feverElapsed = fever.getElapsedTime();
            }
            this->currentHP.erase(this->currentHP.begin() + i);
            this->enemies.erase(this->enemies.begin() + i);
            this->gold.erase(this->gold.begin() + i);
            if (over == 0)
            {
                if(goldState == 0) this->point += this->points[i];
                else this->point += this->points[i] * 2;
            }
            this->points.erase(this->points.begin() + i);
            break;
        }
    }
}


void Enemy::updateVariable()
{
    
    //Wave timer
    elapsed = clock.getElapsedTime();
    if (elapsed.asMilliseconds() > 70000.f)
    {
        clock.restart();
        wavesound = 1;
        wave += 1;
        maxHP = 4 + (wave * wave);
        nEnemies = 0;
        this->maxEnemies = wave * 6;
        this->nSpawn = wave;
    }
    //Enemy timer
    this->enemySpawnTimer = enemyclock.getElapsedTime().asMilliseconds();
    if (this->wavesound == 1)
    {
        this->wavesound = 0;
        this->waveMusic.play();
    }


    //Animation timer
    RectElapsed = Rect.getElapsedTime();
    
    if (goldState == 1 && fever.getElapsedTime().asSeconds() - feverElapsed.asSeconds() >= 10.f)
    {
        goldState = 0;
    }
    
}

void Enemy::updateEnemies()
{   
    //Update Timer
    if (this->nEnemies < this->maxEnemies)
    {
        
        if (enemySpawnTimer >= 10000.f)
        {
            enemyclock.restart();
            for (int i = 1; i <= nSpawn; i++)
            {
                enemySpawn();
            }
        }

    }
    //Animation
    if (RectElapsed.asMilliseconds() >= 200.f)
    {

        if (rectSource.left == 81)
        {
            rectSource.left = 0;
        }
        else
        {
            rectSource.left += 27;
        }
        Rect.restart();
    }
    //Updating Enemy
    for (int i = 0; i < this->enemies.size(); i++)
    {
        bool deleted = false;

        enemies[i].setTextureRect(rectSource);
        
        //Move
        if (this->unmove[i] == 0)
        {
            this->enemies[i].move(-2.f, 0.f);
        }

        //Delete
        if (this->enemies[i].getPosition().x < 0)
        {   
            over = 1;
        }
    }
}


void Enemy::update()
{
    this->updateEnemies();
    this->updateVariable();
}

void Enemy::renderEnemies(RenderTarget& target)
{   
    
    for (auto& e : this->enemies)
    {   
        target.draw(e);
    }
    if (goldState == 1)
    {
        target.draw(feverEf);
    }
}


