#include "Ball.h"



Ball::Ball(WCHAR* texture)
{
	m_Texture = texture;
	Initialize();
}


Ball::~Ball()
{
}


bool Ball::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", m_Texture);

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->mass = 1;
	m_PhysicsComponent->m_collider = new SphereColliderClass(1);

	// 加入摩擦力
	ForceRegistryClass::GetSingleton()->AddForce(m_PhysicsComponent, new FrictionForceClass(1.0f));

	return true;
}

bool Ball::Frame()
{
	return false;
}
