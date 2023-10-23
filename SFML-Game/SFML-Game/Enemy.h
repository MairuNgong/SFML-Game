#pragma once
class Enemy
{
private:
	
	float enemySpawnTimer;
	int maxHP;
	int maxEnemies;
	int nEnemies;
	int nSpawn;
	int wavesound;

	Music boost;
	Music hitMusic[40];
	Music deadMusic[40];
	Music waveMusic;
	Clock Rect;
	Time elapsed;
	Time RectElapsed;
	Time feverElapsed;
	Texture enemyTexture;
	Texture goldenTexture;
	Texture feverTexture;
	Sprite feverEf;
	Sprite enemy;
	IntRect rectSource;
	
	void initMusic();
	void initTexture();
	void initSprite();


public:

	int wave;
	Clock enemyclock;
	Clock clock;
	Clock fever;
	void initVariable();
	vector<Sprite> enemies;
	vector<int> currentHP;
	vector<int> unmove;
	vector<int> gold;
	const Sprite& getSprite(int i) const;
	int over;
	int point;
	vector<int> points;
	int goldState;
	Enemy();
	virtual ~Enemy();
	void enemySpawn();

	void reduceHP(int,int);
	void deletion(Vector2f);
	void updateVariable();
	void updateEnemies();
	void update();

	void renderEnemies(RenderTarget& target);
};

