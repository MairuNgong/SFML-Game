#include "stdafx.h"
#include "Menu.h"

void Menu::initTexture()
{
	if (!this->Tbackground.loadFromFile("Texture/menu.png"))
	{
		cout << "BG-ERROR";
	}
	if (!this->TPlay.loadFromFile("Texture/play.png"))
	{
		cout << "BG-ERROR";
	}
	if (!this->TTuto.loadFromFile("Texture/tutorial.png"))
	{
		cout << "BG-ERROR";
	}
	if (!this->TLeader.loadFromFile("Texture/leader.png"))
	{
		cout << "BG-ERROR";
	}
	if (!this->TCredit.loadFromFile("Texture/credit.png"))
	{
		cout << "BG-ERROR";
	}
	if (!this->TExit.loadFromFile("Texture/exit.png"))
	{
		cout << "BG-ERROR";
	}
}

void Menu::initSprite()
{
	this->Sbackground.setTexture(this->Tbackground);
	this->Sbackground.setOrigin(Vector2f(0, 0));
	this->Sbackground.scale(1.6, 1.6);


}

void Menu::initVar()
{
	screenselect = 1;
}

Menu::Menu()
{
	initTexture();
	initSprite();
	initVar();
}

void Menu::update()
{	
	if (screenselect == 1)
	{
		if (!this->TPlay.loadFromFile("Texture/played.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TTuto.loadFromFile("Texture/tutorial.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TLeader.loadFromFile("Texture/leader.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TCredit.loadFromFile("Texture/credit.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TExit.loadFromFile("Texture/exit.png"))
		{
			cout << "BG-ERROR";
		}
	}
	if (screenselect == 2)
	{
		if (!this->TPlay.loadFromFile("Texture/play.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TTuto.loadFromFile("Texture/tutorialed.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TLeader.loadFromFile("Texture/leader.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TCredit.loadFromFile("Texture/credit.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TExit.loadFromFile("Texture/exit.png"))
		{
			cout << "BG-ERROR";
		}
	}
	if (screenselect == 3)
	{
		if (!this->TPlay.loadFromFile("Texture/play.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TTuto.loadFromFile("Texture/tutorial.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TLeader.loadFromFile("Texture/leaderred.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TCredit.loadFromFile("Texture/credit.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TExit.loadFromFile("Texture/exit.png"))
		{
			cout << "BG-ERROR";
		}
	}
	if (screenselect == 4)
	{	
		if (!this->TPlay.loadFromFile("Texture/play.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TTuto.loadFromFile("Texture/tutorial.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TLeader.loadFromFile("Texture/leader.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TCredit.loadFromFile("Texture/creditted.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TExit.loadFromFile("Texture/exit.png"))
		{
			cout << "BG-ERROR";
		}
	}
	if (screenselect == 5)
	{
		if (!this->TPlay.loadFromFile("Texture/play.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TTuto.loadFromFile("Texture/tutorial.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TLeader.loadFromFile("Texture/leader.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TCredit.loadFromFile("Texture/credit.png"))
		{
			cout << "BG-ERROR";
		}
		if (!this->TExit.loadFromFile("Texture/exited.png"))
		{
			cout << "BG-ERROR";
		}
	}
	this->SPlay.setTexture(this->TPlay);
	this->SPlay.setPosition(960, 420);
	SPlay.setOrigin(SPlay.getGlobalBounds().width / 2, SPlay.getGlobalBounds().height / 2);

	this->STuto.setTexture(this->TTuto);
	this->STuto.setPosition(960, 540);
	STuto.setOrigin(STuto.getGlobalBounds().width / 2, SPlay.getGlobalBounds().height / 2);

	this->SLeader.setTexture(this->TLeader);
	this->SLeader.setPosition(960, 660);
	SLeader.setOrigin(SLeader.getGlobalBounds().width / 2, SLeader.getGlobalBounds().height / 2);

	this->SCredit.setTexture(this->TCredit);
	this->SCredit.setPosition(960, 780);
	SCredit.setOrigin(SCredit.getGlobalBounds().width / 2, SLeader.getGlobalBounds().height / 2);

	this->SExit.setTexture(this->TExit);
	this->SExit.setPosition(960, 900);
	SExit.setOrigin(SExit.getGlobalBounds().width / 2, SLeader.getGlobalBounds().height / 2);
}

void Menu::render(RenderTarget& target)
{
	target.draw(this->Sbackground);
	target.draw(this->SPlay);
	target.draw(this->STuto);
	target.draw(this->SExit);
	target.draw(this->SLeader);
	target.draw(this->SCredit);
}
