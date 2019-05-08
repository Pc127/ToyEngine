#include "GameObjectClass.h"

GameObjectClass::GameObjectClass()
{
	m_GraphicsComponent = 0;
	m_PhysicsComponent = 0;
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
	if (m_GraphicsComponent) {
		m_GraphicsComponent->Shutdown();
		delete m_GraphicsComponent;
		m_GraphicsComponent = 0;
	}

	if (m_PhysicsComponent) {
		m_PhysicsComponent->Shutdown();
		delete m_PhysicsComponent;
		m_PhysicsComponent = 0;
	}
}

void GameObjectClass::OnCollision(GameObjectClass *)
{
}
