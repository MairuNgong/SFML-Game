#pragma once

class Barricade
{
private:
	Music dead;
	void initMusic();
	Texture barricadeTexture;
	Sprite barricade;
	IntRect rectSource;
	int maxHP;
	int maxlvl;
	int num;
	Font font;
	Text lvlText;
	vector<Text> lvlDisplay;
	Vector2f lvlLocation;
	void initText();
	void initVariable();
	void initTexture();
	void initSprite();
public:
	int table[11][6];
	vector<int> currentHP;
	vector<int> lvl;
	vector<Sprite> barricades;
	const Sprite& getSprite(int i) const;
	Barricade();
	virtual ~Barricade();
	void spawnBarricade(Vector2f postion);
	void reduceHP(int i);
	void deletion(Vector2f position);
	void update();
	void updateBarricades();
	void render(RenderTarget& target);
};

