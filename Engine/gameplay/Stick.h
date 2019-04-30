#pragma once
#include "GameObjectClass.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"

class Stick:public GameObjectClass
{
public:
	Stick();
	~Stick();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
private:
};

