#pragma once
class Factory
{
private:
	Music dead;
	void initMusic();
	Texture factoryTexture;
	Sprite factory;
	IntRect rectSource;
	int maxHP;
	int maxlvl;
	int num;
	
	Font font;
	Text lvlText;
	vector<Text> lvlDisplay;
	Vector2f lvlLocation;
	void initText();

	Clock Rect;
	Time RectElapsed;

	void initVariable();
	void initTexture();
	void initSprite();
public:
	int table[11][6];
	
	vector<int> currentHP;
	vector<int> lvl;
	vector<Sprite> factories;
	const Sprite& getSprite(int i) const;
	Factory();
	virtual ~Factory();
	void spawnFactory(Vector2f postion);
	int MakeMoney();
	void reduceHP(int i);
	void deletion(Vector2f position);
	void update();
	void updateFactories();
	void render(RenderTarget& target);
};

