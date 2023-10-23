#pragma once

class Shooter
{
private:
	Music dead;
	void initMusic();
	Texture shooterTexture;
	Sprite shooter;
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
	vector<Sprite> shooters;
	const Sprite& getSprite(int i) const;
	Shooter();
	virtual ~Shooter();
	void spawnShooter(Vector2f postion);
	void reduceHP(int i);
	void deletion(Vector2f position);
	void update();
	void updateShooters();
	void render(RenderTarget& target);
};

