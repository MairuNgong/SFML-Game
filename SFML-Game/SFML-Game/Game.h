#pragma once
#include "stdafx.h"
#include "Background.h"
#include "Enemy.h"
#include "Select.h"
#include "Factory.h"
#include "Shooter.h"
#include "Barricade.h"
#include "Bullet.h"
#include "Bomb.h"
#include "Menu.h"
class Game
{
private:
	//Variable
	//Window
	RenderWindow* window;
	VideoMode videoMode;
	Event event;

	//Menu
	Menu* menu;
	void initMenu();
	//Background
	Background* background;
	void initBackground();
	//Sound
	void initSound();
	Music main;
	Music gameMusic;
	Music SelectinMusic;
	Music betterMusic;
	Music cashMusic;
	Music explodeMusic;
	Music overMusic;
	Music shootMusic;
	Music Maxshoot;

	//Enemy
	Enemy* enemy;
	void initEnemy();
	//Box
	Select* select;
	void initSelect();
	//Game Logic
	bool escape;
	bool space;
	void updateCollision();
	Vector2f deleteFactory;
	Vector2f deleteShooter;
	Vector2f deleteBarricade;
	struct PlayerScore
	{
		string Player;
		int Score;
	};
	//Text
	int money;
	Font font;
	Text Nameheader;
	Text name;
	Text Leaderheader;
	Text Scoreboard;
	FloatRect textBounds;
	Text Space;
	Text moneyText;
	Text gameOver;
	Text Score;
	Text Wave;
	Text creditHeader;
	Text myName;
	Text unit[4];
	void initText();
	string playerName;

	Clock enemyAttackCooldown;
	Time ElapsedEnemyAttack;
	Time cooldownTime;

	Sprite cooldown[5];
	Texture Tcooldown;
	void initTexture();
	void initSprite();

	Clock world;
	Time Unit1Cooldown;
	Time Unit2Cooldown;
	Time Unit3Cooldown;
	Time Unit4Cooldown;
	Time MakeMoneyElapsed;
	Time NormalBulletElapsed;
	Time MaxNormalBulletElapsed;
	//GameObject
	Factory* factory;
	Shooter* shooter;
	Barricade* barricade;
	Bullet* bullet;
	Bomb* bomb;
	void initFactory();
	void initShooter();
	void initBarricade();
	void initBullet();
	void initBomb();
	void initVariable1();
	void initVariable2();
	void initName();
	void initLeader();
	void restart();
	void initWindow();
public:
	Game();
	virtual ~Game();
	//Accessor
	const bool running() const;

	//Functions
	//Game logic
	
	int screen;
	void pollEvents();
	void updateMoney();
	void updateBullet();
	void updateVariable();
	void update();
	void render();

	void menuUpdate();
	void menuRender();

	void nameUpdate();
	void nameRender();

	void overUpdate();
	void overRender();

	void leaderUpdate();
	void leaderRender();

	void tutoUpdate();
	void tutoRender();

	void creditUpdate();
	void creditRender();
};

