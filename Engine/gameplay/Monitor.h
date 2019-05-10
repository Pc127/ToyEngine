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
	// 小球是否全部静止
	bool state;
	GameObjectClass* stick;
	GameObjectClass* subline;
};

