#include "stdafx.h"
#include "Background.h"

void Background::initTexture()
{	
	rectFactory = IntRect(0, 0, 32, 48);
	rectShooter = IntRect(0, 0, 29, 34);
	if (!this->Tbackground.loadFromFile("Texture/background.png"))
	{
		cout << "BG-ERROR";
	}
	if (!this->TTuto.loadFromFile("Texture/howto.png"))
	{
		cout << "BG-ERROR";
	}
	if (!this->ui1.loadFromFile("Texture/ui1.png"))
	{
		cout << "ui1-ERROR";
	}
	if (!this->ui2.loadFromFile("Texture/ui2.png"))
	{
		cout << "ui1-ERROR";
	}
	if (!this->TFactory.loadFromFile("Texture/trap.png"))
	{
		cout << "factory-ERROR";
	}
	if (!this->TShooter.loadFromFile("Texture/Shooter.png"))
	{
		cout << "factory-ERROR";
	}

	if (!this->TBarricade.loadFromFile("Texture/Barricade.png"))
	{
		cout << "barricade-ERROR";
	}
	if (!this->TBomb.loadFromFile("Texture/Explosion_3.png"))
	{
		cout << "bullet-ERROR";
	}
}

void Background::initSprite()
{
	this->Sbackground.setTexture(this->Tbackground);
	this->STuto.setTexture(this->TTuto);
	this->Sui1.setTexture(this->ui1);
	Sui1.scale(4,4);
	Sui1.setPosition(30, 50);
	this->Sui2.setTexture(this->ui2);
	Sui2.scale(4, 4);
	Sui2.setPosition(1250, 50);
	this->SFactory.setTexture(this->TFactory);
	this->SFactory.setTextureRect(rectFactory);
	SFactory.scale(1.8, 1.8);
	SFactory.setPosition(485, 68);

	this->SShooter.setTexture(this->TShooter);
	this->SShooter.setTextureRect(rectShooter);
	SShooter.scale(2.2, 2.2);
	SShooter.setPosition(660, 80);

	this->SBarricade.setTexture(this->TBarricade);
	SBarricade.scale(3, 3);
	SBarricade.setPosition(835, 80);

	this->SBomb.setTexture(this->TBomb);
	SBomb.scale(0.4, 0.4);
	SBomb.setPosition(920, -50);
}

Background::Background()
{
	this->initTexture();
	this->initSprite();
}

void Background::update()
{
}

void Background::render(RenderTarget& target)
{
	target.draw(this->Sbackground);
	target.draw(this->Sui1);
	target.draw(this->Sui2);
	target.draw(this->SFactory);
	target.draw(this->SShooter);
	target.draw(this->SBarricade);
	target.draw(this->SBomb);
}

void Background::Tutorender(RenderTarget& target)
{
	target.draw(this->STuto);
}
