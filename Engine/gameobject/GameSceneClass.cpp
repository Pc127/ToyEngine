#include "GameSceneClass.h"

GameSceneClass::GameSceneClass()
{
}


GameSceneClass::~GameSceneClass()
{
}

bool GameSceneClass::ClearScene()
{
	GameObjectListClass::GetSingleton()->m_GameObjects.clear();
	return true;
}


bool GameSceneClass::Initialize()
{
	return true;
}

void GameSceneClass::Shutdown()
{
	// 清空场景物体的全局表示
	ClearScene();
	// 清空场景中物体
	for (auto it : m_SceneObject) {
		it->Shutdown();
		delete it;
		it = 0;
	}
}
