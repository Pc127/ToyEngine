#include "ImpulseForceClass.h"



ImpulseForceClass::ImpulseForceClass(D3DXVECTOR3 impu)
{
	this->impulse= impu;
}


ImpulseForceClass::~ImpulseForceClass()
{
}

bool ImpulseForceClass::Initialize()
{
	active = true;
	return true;
}

bool ImpulseForceClass::Frame(PhysicsComponentClass *pc, float deltatime)
{
	// 利用重力更新速度
	pc->m_velocity += impulse;

	// 一帧之后 该冲量失效
	active = false;
		
	return true;
}

bool ImpulseForceClass::IsActive()
{
	// 返回
	return active;
}