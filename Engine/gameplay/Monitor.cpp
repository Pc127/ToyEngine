#include "Monitor.h"


Monitor::Monitor(GameObjectClass *st, GameObjectClass *sl)
{
	stick = st;
	subline = sl;
}

Monitor::~Monitor()
{
}


bool Monitor::Initialize()
{
	// 注册
	Register();

	bool result;

	this->active = true;

	m_GraphicsComponent = 0;
	m_PhysicsComponent = 0;

	return true;
}

// 监控所有小球 是否在运动
bool Monitor::Frame()
{
	for (auto gameobject : GameObjectListClass::GetSingleton()->m_GameObjects) {
		if (gameobject->active&&gameobject->m_PhysicsComponent) {
			if (D3DXVec3Length(&gameobject->m_PhysicsComponent->m_velocity)) {
				state = false;
				stick->active = false;
				subline->active = false;
				return true;
			}
		}
	}

	state = true;
	stick->active = true;
	subline->active = true;
	return true;
}
