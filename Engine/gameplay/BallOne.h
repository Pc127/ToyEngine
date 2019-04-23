#pragma once
#include "GameObjectClass.h"

class BallOne:public GameObjectClass
{
public:
	BallOne();
	~BallOne();
	virtual bool Initialize() override;
	virtual bool Frame() override;
};

