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

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", m_Texture);//L"../Engine/data/Ball1.dds"

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;
	// 速度静止
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->m_position = D3DXVECTOR3(1, 0, 0);
	m_PhysicsComponent->mass = 1;
	m_PhysicsComponent->m_collider = new SphereColliderClass(1);


	return true;
}

bool Ball::Frame()
{
	return false;
}
