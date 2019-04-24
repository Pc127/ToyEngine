#pragma once
#include "GameSceneClass.h"
#include "BallOne.h"
#include "BallTwo.h"

class SceneOne:public GameSceneClass
{
public:
	SceneOne();
	~SceneOne();

	virtual bool Initialize() override;
	virtual bool Frame() override;
};

