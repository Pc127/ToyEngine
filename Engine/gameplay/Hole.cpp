#include "Hole.h"

Hole::Hole()
{
}

Hole::~Hole()
{
}


bool Hole::Initialize()
{
	// 注册
	Register();

	bool result;

	// 不需要渲染
	m_GraphicsComponent = 0;
	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();

	// mass等于0 代表静止
	m_PhysicsComponent->mass = 0;
	m_PhysicsComponent->m_collider = new SphereColliderClass(1.8);

	return true;
}

bool Hole::Frame()
{
	return false;
}

void Hole::OnCollision(GameObjectClass *obj)
{
	Ball* ball = dynamic_cast<Ball*>(obj);

	if (ball) {
		ball->m_PhysicsComponent->m_velocity = D3DXVECTOR3(0, -20, 0);
		ball->active = false;
	}
}
