#include "Desktop.h"



Desktop::Desktop()
{
	Initialize();
}


Desktop::~Desktop()
{
}


bool Desktop::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/Desktop.txt", L"../Engine/data/Desktop.dds");

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;
	// 速度静止
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 0);
	// m_PhysicsComponent->m_collider = new SphereColliderClass(1);


	return true;
}

bool Desktop::Frame()
{
	return false;
}
