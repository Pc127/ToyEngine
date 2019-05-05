#include "GameObjectListClass.h"

GameObjectListClass * GameObjectListClass::GetSingleton()
{
	static GameObjectListClass m_object;
	return &m_object;
}

GameObjectListClass::GameObjectListClass()
{
}

bool GameObjectListClass::Initialize()
{
	return true;
}

bool GameObjectListClass::Insert(GameObjectClass* gameObject)
{
	m_GameObjects.push_back(gameObject);
	return true;
}
