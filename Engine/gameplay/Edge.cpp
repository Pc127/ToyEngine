#include "Edge.h"

Edge::Edge(D3DXVECTOR3 min, D3DXVECTOR3 max)
{
	this->max = max;
	this->min = min;
}

Edge::~Edge()
{
}


bool Edge::Initialize()
{
	// 注册
	Register();

	bool result;

	/*m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", L"../Engine/data/Ball16.dds");*/

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->mass = 1;
	m_PhysicsComponent->m_collider = new AabbColliderClass(min, max);
	m_PhysicsComponent->m_position = max;
	m_PhysicsComponent->m_velocity = D3DXVECTOR3(0, 0, 0);

	return true;
}

bool Edge::Frame()
{
	return false;
}
