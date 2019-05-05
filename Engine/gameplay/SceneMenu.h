#pragma once
#include"GameSceneClass.h"
#include "Ball.h"
#include "Table.h"
#include "Desktop.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
#include"Edge.h"
class SceneMenu :public GameSceneClass
{
public:
	SceneMenu();
	~SceneMenu();
	virtual bool Initialize() override;
	virtual bool Frame() override;

};
