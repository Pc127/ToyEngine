#pragma once
#include "GameObjectClass.h"
#include "BallDetector.h"

class AiPlayer:public GameObjectClass
{
public:
	AiPlayer();
	~AiPlayer();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
private:
	GameObjectClass* whiteball;
};

