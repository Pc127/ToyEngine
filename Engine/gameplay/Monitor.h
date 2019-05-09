#pragma once
#include "GameObjectClass.h"
#include "Stick.h"

class Monitor:public GameObjectClass
{
public:
	Monitor(GameObjectClass*, GameObjectClass*);
	~Monitor();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
	bool state;
	GameObjectClass* stick;
	GameObjectClass* subline;
};

