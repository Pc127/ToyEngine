#pragma once
#include "GameSceneClass.h"
#include "Ball.h"
#include "Table.h"
#include "Desktop.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
#include "Edge.h"
#include "Stick.h"

class ScenePlay:public GameSceneClass
{
public:
	ScenePlay();
	~ScenePlay();

	virtual bool Initialize() override;
	virtual bool Frame() override;
};

