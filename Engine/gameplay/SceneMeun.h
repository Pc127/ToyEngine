#pragma once
#include"GameSceneClass.h"
#include "Ball.h"
#include "Table.h"
#include "Desktop.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
class SceneMeun :public GameSceneClass
{
public:
	SceneMeun();
	~SceneMeun();
	virtual bool Initialize() override;
	virtual bool Frame() override;

};
