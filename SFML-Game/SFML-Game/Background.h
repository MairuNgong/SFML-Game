#pragma once

class Background
{
private:
	//Background
	Sprite Sbackground;
	Texture Tbackground;

	Sprite STuto;
	Texture TTuto;

	Sprite Sui1;
	Texture ui1;

	Sprite Sui2;
	Texture ui2;

	Sprite SFactory;
	Texture TFactory;
	IntRect rectFactory;

	Sprite SShooter;
	Texture TShooter;
	IntRect rectShooter;

	Sprite SBarricade;
	Texture TBarricade;

	Sprite SBomb;
	Texture TBomb;
	void initTexture();
	void initSprite();
public:
	Background();
	void update();
	void render(RenderTarget& target);
	void Tutorender(RenderTarget& target);
};

