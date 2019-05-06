#include "GravityForceClass.h"



GravityForceClass::GravityForceClass(D3DXVECTOR3 grav)
{
	this->gravity = grav;
}


GravityForceClass::~GravityForceClass()
{
}

bool GravityForceClass::Initialize()
{
	active = true;
	return true;
}

bool GravityForceClass::Frame(PhysicsComponentClass *pc, float deltatime)
{
	// 利用重力更新速度
	pc->m_velocity += gravity*deltatime;
		
	return true;
}

bool GravityForceClass::IsActive()
{
	// 返回
	return active;
}