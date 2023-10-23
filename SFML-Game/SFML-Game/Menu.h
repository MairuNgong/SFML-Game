#pragma once
class Menu
{
private:
	Sprite Sbackground;
	Texture Tbackground;

	Sprite SPlay;
	Texture TPlay;

	Sprite STuto;
	Texture TTuto;

	Sprite SLeader;
	Texture TLeader;

	Sprite SCredit;
	Texture TCredit;

	Sprite SExit;
	Texture TExit;
	void initTexture();
	void initSprite();
	void initVar();

public:
	int screenselect;
	Menu();
	void update();
	void render(RenderTarget& target);
};

