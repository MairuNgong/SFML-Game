#include "stdafx.h"
#include "Shooter.h"


void Shooter::initMusic()
{
	if (!dead.openFromFile("Music/hurt.mp3"))
	{
		cout << "Hurt-ERROR" << endl;
	}
}

void Shooter::initText()
{
	if (!font.loadFromFile("Font/pixel.ttf"))
	{
		cout << "FontError" << endl;
	}
	lvlText.setFont(font);
	lvlText.setString("1");
	lvlText.setCharacterSize(30);
}

void Shooter::initVariable()
{
	this->rectSource = IntRect(0, 0, 29, 34);
	this->maxHP = 3;
	this->maxlvl = 5;
}

void Shooter::initTexture()
{
	if (!this->shooterTexture.loadFromFile("Texture/Shooter.png"))
	{
		cout << "factory-ERROR";
	}
}

void Shooter::initSprite()
{
	this->shooter.setTexture(this->shooterTexture);
	this->shooter.setTextureRect(rectSource);
}

const Sprite& Shooter::getSprite(int i) const
{
	return this->shooters[i];
}

Shooter::Shooter()
{	
	this->initMusic();
	this->initText();
	this->initVariable();
	this->initTexture();
	this->initSprite();
}

Shooter::~Shooter()
{
}

void Shooter::spawnShooter(Vector2f position)
{
	if (this->table[static_cast<int>((position.x) / 192)][static_cast<int>((position.y - 369) / 142)] != 1)
	{

		this->shooter.setPosition(position.x + 81.f, position.y);
		//Fill the table with factory
		this->table[static_cast<int>((position.x) / 192)][static_cast<int>((position.y - 369) / 142)] = 1;
		// Increase the width while maintaining aspect ratio
		float scaleFactor = 2.5f; // Increase width by a factor of 2
		shooter.setScale(Vector2f(scaleFactor, scaleFactor));

		this->lvlLocation.x = position.x + 10.f;
		this->lvlLocation.y = position.y + 80.f;

		this->lvlText.setPosition(this->lvlLocation);
		this->lvlDisplay.push_back(this->lvlText);

		this->currentHP.push_back(maxHP);
		this->lvl.push_back(1);
		this->shooters.push_back(this->shooter);
	}
	else
	{
		for (int i = 0; i < this->shooters.size(); i++)
		{
			if (this->shooters[i].getPosition().x == position.x + 81.f && this->shooters[i].getPosition().y == position.y && this->lvl[i] < 5)
			{
				this->lvl[i] += 1;
				this->lvlDisplay[i].setString(to_string(this->lvl[i]));
				
				break;
			}
		}
	}
}

void Shooter::reduceHP(int i)
{
	currentHP[i] -= 1;
	if (currentHP[i] <= 0)
	{
		dead.play();
		deletion(this->shooters[i].getPosition());
	}


}

void Shooter::deletion(Vector2f position)
{
	for (int i = 0; i < this->shooters.size(); i++)
	{
		if (this->shooters[i].getPosition() == position)
		{
			this->table[static_cast<int>((position.x - 81.f) / 192)][static_cast<int>((position.y - 369.f) / 142)] = 0;
			this->currentHP.erase(this->currentHP.begin() + i);
			this->lvlDisplay.erase(this->lvlDisplay.begin() + i);
			this->lvl.erase(this->lvl.begin() + i);
			this->shooters.erase(this->shooters.begin() + i);
			break;
		}
	}
}


void Shooter::update()
{
	//Animation timer
	RectElapsed = Rect.getElapsedTime();
	updateShooters();
}

void Shooter::updateShooters()
{
	//Animation
	if (RectElapsed.asMilliseconds() >= 200.f)
	{

		if (rectSource.left >= 89)
		{
			rectSource.left = 0;
		}
		else
		{
			rectSource.left += 30;
		}
		Rect.restart();
	}
	for (int i = 0; i < this->shooters.size(); i++)
	{

		shooters[i].setTextureRect(rectSource);

	}
}


void Shooter::render(RenderTarget& target)
{
	for (auto& e : this->shooters)
	{
		target.draw(e);
	}
	for (auto& e : this->lvlDisplay)
	{
		target.draw(e);
	}
}

