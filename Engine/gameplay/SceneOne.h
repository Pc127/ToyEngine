#pragma once
#include "GameSceneClass.h"
#include "BallOne.h"
#include "BallTwo.h"
#include "Table.h"
#include "Desktop.h"

class SceneOne:public GameSceneClass
{
public:
	SceneOne();
	~SceneOne();

	virtual bool Initialize() override;
	virtual bool Frame() override;
};

