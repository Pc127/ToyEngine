#include "BallTwo.h"



BallTwo::BallTwo()
{
	Initialize();
}


BallTwo::~BallTwo()
{
}


bool BallTwo::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", L"../Engine/data/Ball2.dds");

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;
	m_PhysicsComponent->m_position = D3DXVECTOR3(-5, 0, 0);
	m_PhysicsComponent->m_direction = D3DXVECTOR3(1, 0, 0);
	m_PhysicsComponent->m_velocity = 1;
	m_PhysicsComponent->m_collider = new SphereColliderClass(1);

	return true;
}

bool BallTwo::Frame()
{
	return false;
}
