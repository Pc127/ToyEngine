#pragma once
#include "GameSceneClass.h"
#include "Ball.h"
#include "Table.h"
#include "Desktop.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
#include "Edge.h"
#include "Stick.h"
#include "Monitor.h"
#include "Hole.h"

class SceneOne:public GameSceneClass
{
public:
	SceneOne();
	~SceneOne();

	virtual bool Initialize() override;
	virtual bool Frame() override;
};

