#include "stdafx.h"
#include "Barricade.h"

void Barricade::initMusic()
{
	if (!dead.openFromFile("Music/hurt.mp3"))
	{
		cout << "Hurt-ERROR" << endl;
	}
}

void Barricade::initText()
{
	if (!font.loadFromFile("Font/pixel.ttf"))
	{
		cout << "FontError" << endl;
	}
	lvlText.setFont(font);
	lvlText.setString("1");
	lvlText.setCharacterSize(30);
}

void Barricade::initVariable()
{
	this->rectSource = IntRect(0, 0, 13, 22);
	this->maxHP = 15;
	this->maxlvl = 5;
}

void Barricade::initTexture()
{
	if (!this->barricadeTexture.loadFromFile("Texture/Barricade.png"))
	{
		cout << "barricade-ERROR";
	}
}

void Barricade::initSprite()
{
	this->barricade.setTexture(this->barricadeTexture);
	this->barricade.setTextureRect(rectSource);
}

const Sprite& Barricade::getSprite(int i) const
{
	return this->barricades[i];
}

Barricade::Barricade()
{	
	this->initMusic();
	this->initText();
	this->initVariable();
	this->initTexture();
	this->initSprite();
}

Barricade::~Barricade()
{
}

void Barricade::spawnBarricade(Vector2f position)
{
	if (this->table[static_cast<int>((position.x) / 192)][static_cast<int>((position.y - 369) / 142)] != 1)
	{

		this->barricade.setPosition(position.x + 76.25f , position.y + 32.5f);
		//Fill the table with factory
		this->table[static_cast<int>((position.x) / 192)][static_cast<int>((position.y - 369) / 142)] = 1;
		// Increase the width while maintaining aspect ratio
		float scaleFactor = 2.5f; // Increase width by a factor of 2
		barricade.setScale(Vector2f(scaleFactor, scaleFactor));

		this->lvlLocation.x = position.x + 10.f;
		this->lvlLocation.y = position.y + 80.f;

		this->lvlText.setPosition(this->lvlLocation);
		this->lvlDisplay.push_back(this->lvlText);

		this->currentHP.push_back(maxHP);
		this->lvl.push_back(1);
		this->barricades.push_back(this->barricade);
	}
	else
	{
		for (int i = 0; i < this->barricades.size(); i++)
		{
			if (this->barricades[i].getPosition().x == position.x + 76.25f && this->barricades[i].getPosition().y == position.y + 32.5f && this->lvl[i] < 5)
			{
				
				this->lvl[i] += 1;
				this->lvlDisplay[i].setString(to_string(this->lvl[i]));
				if (this->lvl[i] < 5)
				{
					this->currentHP[i] = 12 + 3 * this->lvl[i];
				}
				else
				{
					this->currentHP[i] = 30;
				}
				cout << this->currentHP[i] << endl;
				break;
			}
		}
	}
}

void Barricade::reduceHP(int i)
{
	currentHP[i] -= 1;
	if (currentHP[i] <= 0)
	{
		this->dead.play();
		deletion(this->barricades[i].getPosition());
	}

}

void Barricade::deletion(Vector2f position)
{
	this->num -= 1;
	for (int i = 0; i < this->barricades.size(); i++)
	{
		if (this->barricades[i].getPosition() == position)
		{
			this->table[static_cast<int>((position.x - 76.25f) / 192)][static_cast<int>((position.y - 401.5f) / 142)] = 0;
			this->currentHP.erase(this->currentHP.begin() + i);
			this->lvl.erase(this->lvl.begin() + i);
			this->lvlDisplay.erase(this->lvlDisplay.begin() + i);
			this->barricades.erase(this->barricades.begin() + i);
			break;
		}
	}
}

void Barricade::update()
{
	updateBarricades();
}

void Barricade::updateBarricades()
{
	for (int i = 0; i < this->barricades.size(); i++)
	{

		barricades[i].setTextureRect(rectSource);

	}
}

void Barricade::render(RenderTarget& target)
{
	for (auto& e : this->barricades)
	{
		target.draw(e);
	}
	for (auto& e : this->lvlDisplay)
	{
		target.draw(e);
	}
}
