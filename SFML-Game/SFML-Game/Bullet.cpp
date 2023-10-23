#include "stdafx.h"
#include "Bullet.h"

void Bullet::initTexture()
{
    if (!this->bulletTexture.loadFromFile("Texture/bullet.png"))
    {
        cout << "bullet-ERROR";
    }
}

void Bullet::initSprite()
{
    this->bullet.setTexture(this->bulletTexture);
}

const Sprite& Bullet::getSprite(int i) const
{
    return this->bullets[i];
}

Bullet::Bullet()
{
    initTexture();
    initSprite();
}

Bullet::~Bullet()
{
}

void Bullet::bulletSpawn(Vector2f position, int lvl)
{   
    if (lvl > 5)
    {
        lvl = 5;
    }
    float scaleFactor = 5.f; 
    bullet.setScale(Vector2f(scaleFactor, scaleFactor));
    bullet.setPosition(position.x + 70.f,position.y + 15.f);
    this->lvl.push_back(lvl);
    bullets.push_back(bullet);
}

void Bullet::deletion(int i)
{
    this->bullets.erase(this->bullets.begin() + i);
    this->lvl.erase(this->lvl.begin() + i);
}

void Bullet::updateBullet()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].move(10.f, 0.f);
        if (bullets[i].getPosition().x >= 1980)
        {
            deletion(i);
        }
    }
}

void Bullet::update()
{
    updateBullet();
}

void Bullet::renderBullet(RenderTarget& target)
{
    for (auto& e : this->bullets)
    {
        target.draw(e);
    }
}
