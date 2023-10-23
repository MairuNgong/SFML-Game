#include "stdafx.h"
#include "Factory.h"


void Factory::initMusic()
{
	if (!dead.openFromFile("Music/hurt.mp3"))
	{
		cout << "Hurt-ERROR" << endl;
	}
}

void Factory::initText()
{
	if (!font.loadFromFile("Font/pixel.ttf"))
	{
		cout << "FontError" << endl;
	}
	lvlText.setFont(font);
	lvlText.setString("1");
	lvlText.setCharacterSize(30);
}

void Factory::initVariable()
{
	this->rectSource = IntRect(0, 0, 32, 48);
	this->maxHP = 5;
	this->maxlvl = 5;
}

void Factory::initTexture()
{
	if (!this->factoryTexture.loadFromFile("Texture/trap.png"))
	{
		cout << "factory-ERROR";
	}
}

void Factory::initSprite()
{
	this->factory.setTexture(this->factoryTexture);
	this->factory.setTextureRect(rectSource);
}

const Sprite& Factory::getSprite(int i) const
{
	return this->factories[i];
}

Factory::Factory()
{	
	this->initMusic();
	this->initText();
	this->initVariable();
	this->initTexture();
	this->initSprite();
}

Factory::~Factory()
{
}

void Factory::spawnFactory(Vector2f position)
{	
	if (this->table[static_cast<int>((position.x) / 192)][static_cast<int>((position.y - 369) / 142)] != 1)
	{
		this->factory.setPosition(position.x + 64.f, position.y - 42.f);
		//Fill the table with factory
		this->table[static_cast<int>((position.x) / 192)][static_cast<int>((position.y - 369) / 142)] = 1;
		// Increase the width while maintaining aspect ratio
		float scaleFactor = 2.5f; // Increase width by a factor of 2
		factory.setScale(Vector2f(scaleFactor, scaleFactor));

		this->lvlLocation.x = position.x + 10.f;
		this->lvlLocation.y = position.y + 80.f;

		this->lvlText.setPosition(this->lvlLocation);
		this->lvlDisplay.push_back(this->lvlText);

		
		this->currentHP.push_back(maxHP);
		this->lvl.push_back(1);
		this->factories.push_back(this->factory);
	}
	else
	{
		for (int i = 0; i < this->factories.size(); i++)
		{	
			if (this->factories[i].getPosition().x == position.x + 64.f && this->factories[i].getPosition().y == position.y - 42.f && this->lvl[i] < 5)
			{	
				this->lvl[i] += 1;
				this->lvlDisplay[i].setString(to_string(this->lvl[i]));
				break;
			}
		}
	}
}

int Factory::MakeMoney()
{
	int sum = 0;
	for (int i = 0; i < factories.size(); i++)
	{	
		if (lvl[i] == 1)
			sum += 50;
		else if(lvl[i] == 6)
			sum += 40 + 5 * 10;
		else 
			sum +=  40 + lvl[i] * 10;
	}
	return sum;
}

void Factory::reduceHP(int i)
{
	currentHP[i] -= 1;
	if (currentHP[i] <= 0)
	{
		this->dead.play();
		deletion(this->factories[i].getPosition());
	}


}

void Factory::deletion(Vector2f position)
{
	this->num -= 1;
	for (int i = 0; i < this->factories.size(); i++)
	{
		if (this->factories[i].getPosition() == position)
		{	
			this->table[static_cast<int>((position.x - 64.f) / 192)][static_cast<int>((position.y - 327) / 142)] = 0;
			this->currentHP.erase(this->currentHP.begin() + i);
			this->lvl.erase(this->lvl.begin() + i);
			this->lvlDisplay.erase(this->lvlDisplay.begin() + i);
			this->factories.erase(this->factories.begin() + i);
			break;
		}
	}
}


void Factory::update()
{
	//Animation timer
	RectElapsed = Rect.getElapsedTime();
	updateFactories();
}

void Factory::updateFactories()
{
	//Animation
	if (RectElapsed.asMilliseconds() >= 200.f)
	{

		if (rectSource.left == 96)
		{
			rectSource.left = 0;
		}
		else
		{
			rectSource.left += 32;
		}
		Rect.restart();
	}
	for (int i = 0; i < this->factories.size(); i++)
	{

		factories[i].setTextureRect(rectSource);


		
	}
}


void Factory::render(RenderTarget& target)
{
	for (auto& e : this->factories)
	{
		target.draw(e);
	}
	for (auto& e : this->lvlDisplay)
	{
		target.draw(e);
	}
}
