#include "stdafx.h"
#include "Bomb.h"

void Bomb::initBomb()
{
    if (!this->bomb1.loadFromFile("Texture/Explosion_3.png"))
    {
        cout << "bullet-ERROR";
    }
    if (!this->bomb2.loadFromFile("Texture/Explosion_6.png"))
    {
        cout << "bullet-ERROR";
    }
    if (!this->bomb3.loadFromFile("Texture/Explosion_9.png"))
    {
        cout << "bullet-ERROR";
    }
    boom = 0;
    RectElapsed = Rect.getElapsedTime();
}

Bomb::Bomb()
{
    initBomb();
}

Bomb::~Bomb()
{
}

void Bomb::created(Vector2f position)
{   
    bomb.setPosition(position.x - 10.f,position.y - 149.f);
    float scaleFactor = 0.5f;
    bomb.setScale(Vector2f(scaleFactor, scaleFactor));
    boom = 1;
    bomb.setTexture(bomb1);
    RectElapsed = Rect.getElapsedTime();
}

void Bomb::update()
{
    
    if (boom != 0)
    {   
        if (this->Rect.getElapsedTime().asMilliseconds() - RectElapsed.asMilliseconds() >= 150.f)
        {
            boom++;
            if (boom == 2)
            {
                bomb.setTexture(bomb2);
            }
            else if (boom == 3)
            {
                bomb.setTexture(bomb3);
            }
            else
            {   
                boom = 0;
            }
            RectElapsed = Rect.getElapsedTime();
        }

    }
   
}

void Bomb::renderBomb(RenderTarget& target)
{
    if(boom != 0)
    {
        target.draw(bomb);
    }
}
