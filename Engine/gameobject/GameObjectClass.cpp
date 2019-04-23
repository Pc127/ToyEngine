#include "GameObjectClass.h"

GameObjectClass::GameObjectClass()
{
	m_GraphicsComponent = 0;
	m_PhysicsComponent = 0;

	// 向list进行注册
	Register();
}


GameObjectClass::~GameObjectClass()
{
}

bool GameObjectClass::Register()
{
	return GameObjectListClass::GetSingleton()->Insert(this);
}

bool GameObjectClass::Initialize()
{
	return true;
}

void GameObjectClass::Shutdown()
{
}
