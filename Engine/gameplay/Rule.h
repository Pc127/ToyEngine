#pragma once
#include "GameObjectClass.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
#include "BallDetector.h"
#include "Monitor.h"

class Rule:public GameObjectClass
{
public:
	Rule(BallDetector* big, BallDetector* smallBalls, GameObjectClass* white, GameObjectClass* black, GameObjectClass* player1, GameObjectClass* player2,
		GameObjectClass* win, Monitor* monitor);
	~Rule();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
private:
	void ChangePlayer();
	void Winner();
	void EndGame();
private:
	BallDetector* bigBalls;
	BallDetector* smallBalls;
	GameObjectClass* whiteBall;
	GameObjectClass* blackBall;
	GameObjectClass* player1;
	GameObjectClass* player2;
	GameObjectClass* win;
	Monitor* monitor;
private:
	int whichPlayer;
	bool initialBallerOwnner;
	int BigBallOwnner;
};

