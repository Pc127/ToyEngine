#include "bitmap.h"



Bitmap::Bitmap(WCHAR* texture)
{
	m_Texture = texture;
	Initialize();
}


Bitmap::~Bitmap()
{
}


bool Bitmap::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", m_Texture);

	this->active = true;

	

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->mass = 1;
	m_PhysicsComponent->m_collider = new SphereColliderClass(1.2);

	// 加入摩擦力
	

	return true;
}

bool Bitmap::Frame()
{
	return false;
}
