#pragma once
class Bomb
{
private:
	Texture bomb1;
	Texture bomb2;
	Texture bomb3;
	Sprite bomb;

	void initBomb();
	Clock Rect;
	Time RectElapsed;
	
public:
	Bomb();
	virtual ~Bomb();
	
	void created(Vector2f);
	int boom;
	void update();
	void renderBomb(RenderTarget& target);
	
};

