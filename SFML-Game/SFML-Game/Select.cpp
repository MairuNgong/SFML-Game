#include "stdafx.h"
#include "Select.h"



void Select::initBox()
{
    this->Pressed = false;
    this->unit = 0;
    this->selectBox.setSize(sf::Vector2f(192, 142));
    this->selectBox.setFillColor(sf::Color::Transparent);
    this->selectBox.setOutlineColor(sf::Color::Red);
    this->selectBox.setOutlineThickness(2.0f);

    this->boxPosition = Vector2f(0, 369);
    this->selectBox.setPosition(boxPosition);

    if (!SelectinMusic.openFromFile("Music/selecting.mp3")) {
        cout << "Game-ERROR" << endl;
    }
    SelectinMusic.setVolume(100);
    
}

Select::Select()
{
    this->initBox();
}


void Select::update()
{   
    //Move box
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        Pressed = false;
    }

    else if (Pressed == false)
    {   
        if (Keyboard::isKeyPressed(Keyboard::Left) && boxPosition.x >= 192) {
            SelectinMusic.play();
            this->boxPosition.x -= 192.0f;
            this->Pressed = true;
            
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && boxPosition.x <= 1536) {
            SelectinMusic.play();
            this->boxPosition.x += 192.0f;
            this->Pressed = true;
            
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && boxPosition.y >= 511) {
            SelectinMusic.play();
            this->boxPosition.y -= 142.0f;
            this->Pressed = true;
            
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && boxPosition.y <= 796) {
            SelectinMusic.play();
            this->boxPosition.y += 142.0f;
            this->Pressed = true;
            
        }
        this->selectBox.setPosition(boxPosition);

    }


}

void Select::renderBox(RenderTarget& target)
{
    target.draw(this->selectBox);
}
