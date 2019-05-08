#pragma once
#include "GameObjectClass.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
#include "AabbColliderClass.h"
#include "SphereColliderClass.h"
#include "Ball.h"

class Hole:public GameObjectClass
{
public:
	Hole();
	~Hole();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
	virtual void OnCollision(GameObjectClass*) override;
private:
};

