#include "Stick.h"



Stick::Stick()
{

}


Stick::~Stick()
{
}


bool Stick::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/Stick.txt", L"../Engine/data/Stick.dds");

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();

	return true;
}

bool Stick::Frame()
{
	return false;
}
