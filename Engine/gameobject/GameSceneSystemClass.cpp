#include "GameSceneSystemClass.h"

GameSceneSystemClass::GameSceneSystemClass()
{
}


GameSceneSystemClass::~GameSceneSystemClass()
{
}


GameSceneSystemClass * GameSceneSystemClass::GetSingleton()
{
	static GameSceneSystemClass instance;
	return &instance;
}

bool GameSceneSystemClass::Initialize(string name)
{
	m_current = name;
	m_Scenes[m_current]->Initialize();
	return false;
}



void GameSceneSystemClass::Shutdown()
{
	// 清理旧场景中所有物体
	m_Scenes[m_current]->Shutdown();
	for (auto it : m_Scenes) {
		delete it.second;
	}
}

// 先设置场景 再initialize
void GameSceneSystemClass::SetScene(string name, GameSceneClass *gs)
{
	m_Scenes[name] = gs;
}

void GameSceneSystemClass::LoadScene(string name)
{
	// 清理旧场景中所有物体
	m_Scenes[m_current]->Shutdown();

	// 设置新场景
	m_current = name;
	m_Scenes[m_current]->Initialize();
}

// 调用当前game list中 所有物体的frame逻辑
bool GameSceneSystemClass::Frame()
{
	auto objs = GameObjectListClass::GetSingleton()->m_GameObjects;

	for (auto obj : objs) {
		obj->Frame();
	}

	return true;
}


