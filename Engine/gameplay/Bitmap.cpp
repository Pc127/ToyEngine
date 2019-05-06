#include "bitmap.h"



Bitmap::Bitmap(WCHAR* texture)
{
	m_Texture = texture;
	Initialize();
}


Bitmap::~Bitmap()
{
}


bool Ball::Initialize()
{
	// ??
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", m_Texture);

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// ???? ? ???
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->mass = 1;
	m_PhysicsComponent->m_collider = new SphereColliderClass(1.2);

	// ?????
	ForceRegistryClass::GetSingleton()->AddForce(m_PhysicsComponent, new FrictionForceClass(1.0f));

	return true;
}

bool Ball::Frame()
{
	return false;
}
