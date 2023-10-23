#pragma once
class Select
{
private:
	Music SelectinMusic;
	RectangleShape selectBox;
	bool Pressed;
public:
	Vector2f boxPosition;
	int unit;
	Select();
	void initBox();
	void update();
	void renderBox(RenderTarget& target);
};

