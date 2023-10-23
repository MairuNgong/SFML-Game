#include "Game.h"
void Game::initMenu()
{
    this->menu = new Menu();
}
//Functions
void Game::initBackground()
{
    this->background = new Background();
}

void Game::initSound()
{
    if (!main.openFromFile("Music/main.mp3")) {
        cout << "Main-ERROR" << endl;
    }
    main.setVolume(50);
    main.setLoop(true);
    main.play();
    

    if (!gameMusic.openFromFile("Music/game.mp3")) {
        cout << "Game-ERROR" << endl;
    }
    gameMusic.setVolume(30);
    gameMusic.setLoop(true);

    if (!SelectinMusic.openFromFile("Music/selecting.mp3")) {
        cout << "Game-ERROR" << endl;
    }
    

    if (!betterMusic.openFromFile("Music/playS.mp3")) {
        cout << "Game-ERROR" << endl;
    }
    

    if (!cashMusic.openFromFile("Music/cash.mp3")) {
        cout << "Game-ERROR" << endl;
    }

    if (!explodeMusic.openFromFile("Music/explode.mp3")) {
        cout << "Game-ERROR" << endl;
    }
    explodeMusic.setVolume(50);
    if (!overMusic.openFromFile("Music/over.wav")) {
        cout << "Game-ERROR" << endl;
    }
    if (!shootMusic.openFromFile("Music/shoot.wav")) {
        cout << "Game-ERROR" << endl;
    }
    shootMusic.setVolume(50);
    
    if (!Maxshoot.openFromFile("Music/shoot.wav")) {
        cout << "Game-ERROR" << endl;
    }
    Maxshoot.setVolume(50);
    Maxshoot.setPitch(0.5f);
   
    
}

void Game::initText()
{
    if (!font.loadFromFile("Font/pixel.ttf"))
    {
        cout << "FontError" << endl;
    }
    Nameheader.setFont(font);
    Nameheader.setCharacterSize(90);
    Nameheader.setPosition(960, 200);
    Nameheader.setString("ENTER YOUR NAME");
    textBounds = Nameheader.getLocalBounds();
    Nameheader.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    name.setFont(font);
    name.setCharacterSize(60);
    name.setPosition(960, 600);
    Space.setFont(font);
    Leaderheader.setFont(font);
    Leaderheader.setCharacterSize(90);
    Leaderheader.setPosition(960, 200);
    Leaderheader.setString("LEADERBOARD");
    textBounds = Leaderheader.getLocalBounds();
    Leaderheader.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    Scoreboard.setFont(font);
    Scoreboard.setCharacterSize(45);
    Scoreboard.setPosition(960, 600);
    Scoreboard.setString("");
    textBounds = Scoreboard.getLocalBounds();
    Scoreboard.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    moneyText.setFont(font);
    moneyText.setFillColor(Color::White);
    moneyText.setCharacterSize(45);
    moneyText.setPosition(50,90);
    creditHeader.setFont(font);
    creditHeader.setCharacterSize(90);
    creditHeader.setPosition(960, 200);
    creditHeader.setString("CREDITS");
    textBounds = creditHeader.getLocalBounds();
    creditHeader.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    myName.setFont(font);
    myName.setCharacterSize(45);
    myName.setPosition(960, 500);
    myName.setString("66010873 Supawech Sepsirisuk");
    textBounds = myName.getLocalBounds();
    myName.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    gameOver.setFont(font);
    gameOver.setCharacterSize(120);
    gameOver.setPosition(960, 250);
    gameOver.setString("GAME OVER");
    textBounds = gameOver.getLocalBounds();
    gameOver.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    Score.setFont(font);
    Score.setCharacterSize(45);
    Score.setPosition(1300, 90);
    Wave.setFont(font);
    Wave.setCharacterSize(90);
    Wave.setFillColor(Color::Red);
    Wave.setOutlineThickness(5.f);
    Wave.setOutlineColor(Color::Black);
    unit[0].setString("50");
    unit[1].setString("100");
    unit[2].setString("50");
    unit[3].setString("100");
    unit[0].setPosition(495, 140);
    unit[1].setPosition(655, 140);
    unit[2].setPosition(837, 140);
    unit[3].setPosition(1000, 140);
    for (int i = 0; i < 4; i++)
    {
        unit[i].setFont(font);
        unit[i].setCharacterSize(20);
    }
}

void Game::initTexture()
{
    if (!this->Tcooldown.loadFromFile("Texture/cooldown.png"))
    {
        cout << "barricade-ERROR";
    }
}

void Game::initSprite()
{   
    for (int i = 0; i < 4; i++)
    {
        this->cooldown[i].setTexture(this->Tcooldown);
        this->cooldown[i].setTexture(this->Tcooldown);
        cooldown[i].scale(3.7, 3.7);
        if (i == 0) cooldown[i].setPosition(460, 67);
        else if (i == 1) cooldown[i].setPosition(634, 66);
        else if (i == 2) cooldown[i].setPosition(806, 66);
        else if (i == 3) cooldown[i].setPosition(978, 66);
    }
}

void Game::initEnemy()
{
    this->enemy = new Enemy();
}

void Game::initSelect()
{
    this->select = new Select();
}


void Game::initFactory()
{
    this->factory = new Factory();
}

void Game::initShooter()
{
    this->shooter = new Shooter();
}

void Game::initBarricade()
{
    this->barricade = new Barricade();
}

void Game::initBullet()
{
    this->bullet = new Bullet();
}

void Game::initBomb()
{
    this->bomb = new Bomb();
}

//Private Function
void Game::initVariable1()
{   

    this->space = false;
    this->escape = false;
    this->screen = 0;
	this->window = nullptr;

}



void Game::initVariable2()
{   
    this->main.stop();
    this->gameMusic.play();
    this->enemyAttackCooldown.restart();
    this->world.restart();
    this->enemy->enemyclock.restart();
    this->enemy->clock.restart();
    this->enemy->initVariable();
    this->money = 400;
    this->cooldownTime = milliseconds(1000);
    this->Unit1Cooldown = seconds(-30);
    this->Unit2Cooldown = seconds(-30);
    this->Unit3Cooldown = seconds(-30);
    this->Unit4Cooldown = seconds(-30);
    this->MakeMoneyElapsed = world.getElapsedTime();
    this->NormalBulletElapsed = world.getElapsedTime();
    this->MaxNormalBulletElapsed = world.getElapsedTime();
    this->screen = 2;
    this->Score.setPosition(1300, 90);
    textBounds = Score.getLocalBounds();
    Score.setOrigin(0, 0);
}

void Game::initName()
{
    this->name.setString("");
    this->playerName = "";
    this->Space.setPosition(960, 900);
    Space.setCharacterSize(45);
    Space.setString("Press SPACE to continue");
    textBounds = Space.getLocalBounds();
    Space.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    screen = 1;
}

void Game::initLeader()
{
    Scoreboard.setString("");
    ifstream inFile("score.txt");
    vector<PlayerScore> topScore;
    PlayerScore temp;
    while (inFile >> temp.Player >> temp.Score) 
    {
        topScore.push_back(temp);
    }
    int playerNum = min(5, static_cast<int>(topScore.size()));
    for (int i = 0; i < playerNum; i++)
    {   
        Scoreboard.setString(Scoreboard.getString() + to_string(i + 1) + ". " + topScore[i].Player + " : " + to_string(topScore[i].Score) + "\n\n");
    }
    textBounds = Scoreboard.getLocalBounds();
    Scoreboard.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    this->Space.setPosition(960, 950);
    this->Space.setCharacterSize(45);
    Space.setString("Press SPACE to return");
    textBounds = Space.getLocalBounds();
    Space.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    screen = 4;
}

void Game::restart()
{   
    this->gameMusic.stop();
    this->overMusic.play();
    for (size_t i = 0; i < enemy->enemies.size(); i++)
    {   
        this->enemy->deletion(this->enemy->enemies[i].getPosition());
        i = -1;
    }
    for (size_t i = 0; i < factory->factories.size(); i++)
    {   
        this->factory->deletion(this->factory->factories[i].getPosition());
        i = -1;
    }
    for (size_t i = 0; i < shooter->shooters.size(); i++)
    {
        this->shooter->deletion(this->shooter->shooters[i].getPosition());
        i = -1;
    }
    for (size_t i = 0; i < barricade->barricades.size(); i++)
    {
        this->barricade->deletion(this->barricade->barricades[i].getPosition());
        i = -1;
    }
    for (size_t i = 0; i < bullet->bullets.size(); i++)
    {
        this->bullet->deletion(i);
        i = -1;
    }
    this->screen = 3;
    ofstream outFile("score.txt", ios::app);
    if (outFile.is_open()) {
        PlayerScore currentPlayer;
        currentPlayer.Player = playerName;
        currentPlayer.Score = enemy->point;
        outFile << currentPlayer.Player << " " << currentPlayer.Score << endl;
        outFile.close();
    }
    else {
        cout << "Unable to open output.txt for writing." << endl;
    }

    ifstream inFile("score.txt");
    vector<PlayerScore> topScore;
    PlayerScore temp;
    while (inFile >> temp.Player >> temp.Score)
    {
        topScore.push_back(temp);
    }
    int r = topScore.size();
    while (r--)
    {
        for (int i = 0; i < r; i++)
        {
            if (topScore[i].Score < topScore[i + 1].Score)
            {
                PlayerScore temp = topScore[i + 1];
                topScore[i + 1] = topScore[i];
                topScore[i] = temp;
            }
        }
    }
    int playerNum = min(5, static_cast<int>(topScore.size()));
    ofstream outFile2("score.txt", ios::out);
    if (outFile2.is_open())
    {
        for (int i = 0; i < playerNum; i++)
        {
            outFile2 << topScore[i].Player << " " << topScore[i].Score << endl;
        }
    }
    this->Score.setFillColor(Color::White);
    this->Score.setPosition(960, 600);
    this->Score.setCharacterSize(80);
    textBounds = Score.getLocalBounds();
    Score.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    this->Space.setPosition(960, 950);
    this->Space.setCharacterSize(45);
    Space.setString("Press SPACE to return");
    textBounds = Space.getLocalBounds();
    Space.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
}

void Game::initWindow()
{
	this->videoMode.height = 1080;
	this->videoMode.width = 2000;
	this->window = new RenderWindow(this->videoMode, "SFML works!", Style::Fullscreen);
    this->window->setFramerateLimit(60);


}



Game::Game()
{   
    this->initMenu();
    this->initSound();
    this->initText();
    this->initTexture();
    this->initSprite();
    this->initBackground();
	this->initVariable1();
	this->initWindow();
    this->initEnemy();
    this->initSelect();
    this->initFactory();
    this->initShooter();
    this->initBarricade();
    this->initBullet();
    this->initBomb();
}

Game::~Game()
{   
    delete this->menu;
	delete this->window;
    delete this->background;
    delete this->enemy;
    delete this->factory;
    delete this->shooter;
    delete this->barricade;
    delete this->bullet;
    delete this->bomb;
}

//Accessor
const bool Game::running() const
{
	return this->window->isOpen();
}


void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {   
        if (this->event.type == Event::Closed)
        {
            this->window->close();
        }
        if (!Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            escape = false;
        }
        if (!Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            space = false;
        }
        if (screen == 0)
        {   
            if (event.type == Event::KeyPressed)
            {   
                SelectinMusic.play();
                if (Keyboard::isKeyPressed(Keyboard::Up) && this->menu->screenselect > 1)
                {   
                    
                    this->menu->screenselect -= 1;
                }
                if (Keyboard::isKeyPressed(Keyboard::Down) && this->menu->screenselect < 5)
                {   
                    
                    this->menu->screenselect += 1;
                }
                if (this->event.key.scancode == Keyboard::Scan::Space && space == false)
                {   
                    space = true;
                    if (this->menu->screenselect == 1)
                    {   
                        
                        initName();
                    }
                    else if (this->menu->screenselect == 2)
                    {
                        screen = 5;
                        this->Space.setPosition(960, 1050);
                        this->Space.setCharacterSize(25);
                        Space.setString("Press SPACE to return");
                        textBounds = Space.getLocalBounds();
                        Space.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
                    }
                    else if (this->menu->screenselect == 3)
                    {
                        initLeader();
                    }
                    else if (this->menu->screenselect == 4)
                    {
                        this->screen = 6;
                        this->Space.setPosition(960, 950);
                        this->Space.setCharacterSize(45);
                        Space.setString("Press SPACE to return");
                        textBounds = Space.getLocalBounds();
                        Space.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
                    }

                    else if (this->menu->screenselect == 5)
                    {
                        this->window->close();
                    }
                    
                }
                if (escape == false && Keyboard::isKeyPressed(Keyboard::Escape))
                {
                    this->window->close();
                }
            }

        }
        if (screen == 1)
        {
            if (event.type == sf::Event::TextEntered)
            {

                if (event.text.unicode == 32 && !playerName.empty())
                {
                    if(space == false)
                    {   
                        betterMusic.play();
                        space = true;
                        initVariable2();
                    }
                }
                else if (event.text.unicode > 32 && event.text.unicode < 127)
                {
                    this->playerName += static_cast<char>(event.text.unicode);
                    name.setString(playerName);
                }
                else if (event.text.unicode == 8 && !playerName.empty())
                {
                    playerName.pop_back();
                    name.setString(playerName);
                }
                textBounds = name.getLocalBounds();
                name.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
            
            }
        }
        if (screen == 2)
        {
            if (this->event.type == Event::KeyPressed)
            {   
                
                if (escape == false && Keyboard::isKeyPressed(Keyboard::Escape))
                {   
                    SelectinMusic.play();
                    escape = true;
                    enemy->over = 1;
                }

                this->deleteShooter.x = this->select->boxPosition.x + 81.f;
                this->deleteShooter.y = this->select->boxPosition.y;

                this->deleteFactory.x = this->select->boxPosition.x + 64.f;
                this->deleteFactory.y = this->select->boxPosition.y - 42.f;

                this->deleteBarricade.x = this->select->boxPosition.x + 76.25f;
                this->deleteBarricade.y = this->select->boxPosition.y + 32.5f;



                if (this->event.key.scancode == Keyboard::Scan::Num1 && money >= 50 && world.getElapsedTime().asSeconds() - Unit1Cooldown.asSeconds() >= 5)
                {
                    betterMusic.play();
                    this->shooter->deletion(deleteShooter);
                    this->barricade->deletion(deleteBarricade);


                    this->factory->spawnFactory(this->select->boxPosition);
                    for (int i = 0; i < this->factory->factories.size(); i++)
                    {
                        if (this->factory->factories[i].getPosition() == deleteFactory && this->factory->lvl[i] <= 5)
                        {
                            this->money -= 50;
                            Unit1Cooldown = world.getElapsedTime();
                            if(this->factory->lvl[i] == 5) this->factory->lvl[i] = 6;
                            break;
                        }
                    }


                }
                if (this->event.key.scancode == Keyboard::Scan::Num2 && money >= 100 && world.getElapsedTime().asSeconds() - Unit2Cooldown.asSeconds() >= 5)
                {

                    betterMusic.play();
                    this->factory->deletion(deleteFactory);
                    this->barricade->deletion(deleteBarricade);

                    this->shooter->spawnShooter(this->select->boxPosition);
                    for (int i = 0; i < this->shooter->shooters.size(); i++)
                    {
                        if (this->shooter->shooters[i].getPosition() == deleteShooter && this->shooter->lvl[i] <= 5)
                        {
                            this->money -= 100;
                            Unit2Cooldown = world.getElapsedTime();
                            if (this->shooter->lvl[i] == 5) this->shooter->lvl[i] = 6;
                            break;
                        }
                    }



                }
                if (this->event.key.scancode == Keyboard::Scan::Num3 && money >= 50 && world.getElapsedTime().asSeconds() - Unit3Cooldown.asSeconds() >= 10)
                {

                    betterMusic.play();
                    this->shooter->deletion(deleteShooter);
                    this->factory->deletion(deleteFactory);

                    this->barricade->spawnBarricade(this->select->boxPosition);
                    for (int i = 0; i < this->barricade->barricades.size(); i++)
                    {
                        if (this->barricade->barricades[i].getPosition() == deleteBarricade && this->barricade->lvl[i] <= 5)
                        {
                            this->money -= 50;
                            Unit3Cooldown = world.getElapsedTime();
                            if (this->barricade->lvl[i] == 5) this->barricade->lvl[i] = 6;
                            break;
                        }
                    }


                }
                if (this->event.key.scancode == Keyboard::Scan::Num4 && money >= 100 && world.getElapsedTime().asSeconds() - Unit4Cooldown.asSeconds() >= 30)
                {
                    betterMusic.play();
                    explodeMusic.play();
                    this->shooter->deletion(deleteShooter);
                    this->factory->deletion(deleteFactory);
                    this->barricade->deletion(deleteBarricade);

                    this->bomb->created(this->select->boxPosition);

                    for (int i = 0; i < this->enemy->enemies.size(); i++)
                    {
                        if (this->enemy->enemies[i].getPosition().x >= this->select->boxPosition.x - 10.f && this->enemy->enemies[i].getPosition().x <= this->select->boxPosition.x + 192.f
                            && this->enemy->enemies[i].getPosition().y >= this->select->boxPosition.y && this->enemy->enemies[i].getPosition().y <= this->select->boxPosition.y + 20.f)
                        {
                            this->enemy->deletion(this->enemy->enemies[i].getPosition());
                            i = -1;
                        }
                    }

                    this->money -= 100;
                    Unit4Cooldown = world.getElapsedTime();
                }


            }
        }
        if (screen == 3)
        {
            if (space == false && Keyboard::isKeyPressed(Keyboard::Space))
            {   
                SelectinMusic.play();
                space = true;
                this->Score.setString("");
                this->Score.setCharacterSize(45);
                this->overMusic.stop();
                this->main.play();
                this->screen = 0;
            }
        }
        if (screen == 4)
        {
            if (space == false && Keyboard::isKeyPressed(Keyboard::Space))
            {
                SelectinMusic.play();
                space = true;
                this->screen = 0;
            }
        }
        if (screen == 5)
        {
            if (space == false && Keyboard::isKeyPressed(Keyboard::Space))
            {   
                SelectinMusic.play();
                space = true;
                this->screen = 0;
            }
        }
        if (screen == 6)
        {
            if (space == false && Keyboard::isKeyPressed(Keyboard::Space))
            {
                SelectinMusic.play();
                space = true;
                this->screen = 0;
            }
        }
    }


}

void Game::updateMoney()
{   
    this->moneyText.setString("Cash:" + to_string(money));
    if (world.getElapsedTime().asSeconds() - MakeMoneyElapsed.asSeconds() >= 20.f)
    {   
        
        this->money += this->factory->MakeMoney();
        if (this->factory->MakeMoney() > 0)
        {
            this->moneyText.setFillColor(Color::Green);
            this->moneyText.setCharacterSize(47);
            cashMusic.play();
        }
        MakeMoneyElapsed = world.getElapsedTime();
    }
    else if (world.getElapsedTime().asSeconds() - MakeMoneyElapsed.asSeconds() >= 1.f)
    {
        this->moneyText.setFillColor(Color::White);
        this->moneyText.setCharacterSize(45);
    }
}

void Game::updateBullet()
{
    int shootcheck = 0;
    if (world.getElapsedTime().asSeconds() - NormalBulletElapsed.asSeconds() >= 2.f)
    {
        
        for (int i = 0; i < this->shooter->shooters.size(); i++)
        {   
            if (this->shooter->lvl[i] < 5)
            {
                this->bullet->bulletSpawn(this->shooter->shooters[i].getPosition(), this->shooter->lvl[i]);
                if (shootcheck == 0)
                {
                    shootcheck = 1;
                    this->shootMusic.play();
                }
            }
        }
        NormalBulletElapsed = world.getElapsedTime();
    }
    int shootcheck2 = 0;
    if (world.getElapsedTime().asSeconds() - MaxNormalBulletElapsed.asSeconds() >= 1.f)
    {
        for (int i = 0; i < this->shooter->shooters.size(); i++)
        {   
            if (this->shooter->lvl[i] == 6)
            {
                this->bullet->bulletSpawn(this->shooter->shooters[i].getPosition(), this->shooter->lvl[i]);
                if (shootcheck2 == 0)
                {
                    shootcheck2 = 1;
                    this->Maxshoot.play();
                }
            }
        }
        MaxNormalBulletElapsed = world.getElapsedTime();
    }
}

void Game::updateVariable()
{   
    ElapsedEnemyAttack = enemyAttackCooldown.getElapsedTime();
    if (this->enemy->over == 1)
    {   
        restart();
    }
    this->Score.setString("Score:" + to_string(this->enemy->point));
    if (this->enemy->clock.getElapsedTime().asSeconds() < 5)
    {
        this->Wave.setString("WAVE " + to_string(enemy->wave));
        textBounds = Wave.getLocalBounds();
        Wave.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
        Wave.setPosition(960, 600);
    }
    else
    {
        this->Wave.setString("");
    }
    if (this->enemy->goldState == 1 && this->enemy->over == 0)
    {
        this->Score.setFillColor(Color(250, 178, 21));
    }
    else
    {
        this->Score.setFillColor(Color::White);
    }
}


void Game::updateCollision()
{
    for (size_t i = 0; i < enemy->enemies.size(); i++)
    {   
        this->enemy->unmove[i] = 0;
        for (size_t j = 0; j < this->factory->factories.size(); j++)
        {   
            
            if (this->factory->getSprite(j).getGlobalBounds().intersects(this->enemy->getSprite(i).getGlobalBounds()))
            {   

                this->enemy->unmove[i] = 1;
                if (this->ElapsedEnemyAttack >= this->cooldownTime)
                {   
                    this->factory->reduceHP(j);
                    enemyAttackCooldown.restart();
                }
                break;
            }
        }

        for (size_t j = 0; j < this->shooter->shooters.size(); j++)
        {   
            
            if (this->shooter->getSprite(j).getGlobalBounds().intersects(this->enemy->getSprite(i).getGlobalBounds()))
            {

                this->enemy->unmove[i] = 1;
                if (this->ElapsedEnemyAttack >= this->cooldownTime)
                {
                    this->shooter->reduceHP(j);
                    enemyAttackCooldown.restart();
                }
                break;
            }
        }

        for (size_t j = 0; j < this->barricade->barricades.size(); j++)
        {

            if (this->barricade->getSprite(j).getGlobalBounds().intersects(this->enemy->getSprite(i).getGlobalBounds()))
            {

                this->enemy->unmove[i] = 1;
                if (this->ElapsedEnemyAttack >= this->cooldownTime)
                {
                    this->barricade->reduceHP(j);
                    enemyAttackCooldown.restart();
                }
                break;
            }
        }
        for (size_t j = 0; j < this->bullet->bullets.size(); j++)
        {

            if (this->bullet->getSprite(j).getGlobalBounds().intersects(this->enemy->getSprite(i).getGlobalBounds()))
            {   
                this->enemy->reduceHP(i,this->bullet->lvl[j]);
                this->bullet->deletion(j);
                break;
            }
        }
    }
}




//Functions
void Game::update()
{   
    this->pollEvents();
    this->updateMoney();
    this->updateBullet();
    this->updateVariable();
    this->enemy->update();
    this->select->update();
    this->factory->update();
    this->shooter->update();
    this->bullet->update();
    this->bomb->update();
    this->updateCollision();
    
}


void Game::render()
{   
    this->window->clear();
        this->background->render(*this->window);
        this->window->draw(moneyText);
        this->window->draw(Score);
        for (int i = 0; i < 4; i++)
        {
            this->window->draw(unit[i]);
        }
        if (world.getElapsedTime().asSeconds() - Unit1Cooldown.asSeconds() < 5 || money < 50)
        {
            this->window->draw(cooldown[0]);
        }
        if (world.getElapsedTime().asSeconds() - Unit2Cooldown.asSeconds() < 5|| money < 100)
        {
            this->window->draw(cooldown[1]);
        }
        if (world.getElapsedTime().asSeconds() - Unit3Cooldown.asSeconds() < 10 || money < 50)
        {
            this->window->draw(cooldown[2]);
        }
        if (world.getElapsedTime().asSeconds() - Unit4Cooldown.asSeconds() < 30 || money < 100)
        {
            this->window->draw(cooldown[3]);
        }
        
        this->select->renderBox(*this->window);
        this->factory->render(*this->window);
        this->shooter->render(*this->window);
        this->barricade->render(*this->window);
        this->bullet->renderBullet(*this->window);
        this->bomb->renderBomb(*this->window);
        this->enemy->renderEnemies(*this->window);
        this->window->draw(Wave);
        this->window->display();
}

void Game::menuUpdate()
{   
    this->menu->update();
    this->pollEvents();
}

void Game::menuRender()
{
    this->window->clear();
    this->menu->render(*this->window);
    this->window->display();
}

void Game::nameUpdate()
{
    this->pollEvents();
}

void Game::nameRender()
{
    this->window->clear();
    this->window->draw(Nameheader);
    this->window->draw(name);
    this->window->draw(Space);
    this->window->display();
}

void Game::overUpdate()
{
    this->pollEvents();
    

}

void Game::overRender()
{
    this->window->clear();
    this->window->draw(gameOver);
    this->window->draw(Score);
    this->window->draw(Space);
    this->window->display();
}

void Game::leaderUpdate()
{
    this->pollEvents();
}

void Game::leaderRender()
{
    this->window->clear();
    this->window->draw(Leaderheader);
    this->window->draw(Scoreboard);
    this->window->draw(Space);
    this->window->display();
}

void Game::tutoUpdate()
{
    this->pollEvents();
}

void Game::tutoRender()
{
    this->window->clear();
    this->background->Tutorender(*this->window);
    this->window->draw(Space);
    this->window->display();
}

void Game::creditUpdate()
{
    this->pollEvents();
}

void Game::creditRender()
{
    this->window->clear();
    this->window->draw(creditHeader);
    this->window->draw(myName);
    this->window->draw(Space);
    this->window->display();
}

