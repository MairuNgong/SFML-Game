#pragma once
class Bullet
{
private:
	Texture bulletTexture;
	Sprite bullet;

	
	void initTexture();
	void initSprite();
public:
	vector<Sprite> bullets;
	vector<int> lvl;
	const Sprite& getSprite(int i) const;

	Bullet();
	virtual ~Bullet();
	void bulletSpawn(Vector2f,int);
	void deletion(int);
	void updateBullet();
	void update();

	void renderBullet(RenderTarget& target);
};

