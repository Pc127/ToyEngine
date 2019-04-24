#pragma once
#include "GraphicsComponentClass.h"
#include "PhysicsComponentClass.h"
#include "GameObjectListClass.h"
#include "GameObjectClass.h"

#include <vector>

using namespace std;

// 负责创建和销毁gameObject
class GameSceneClass
{
public:
	GameSceneClass();
	virtual ~GameSceneClass();

	bool ClearScene();

	virtual bool Initialize() = 0;
	virtual bool Frame() = 0;
	void Shutdown();

public:
	vector<GameObjectClass*> m_SceneObject;
};