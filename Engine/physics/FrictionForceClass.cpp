#include "FrictionForceClass.h"



FrictionForceClass::FrictionForceClass(float damp)
{
	this->damping = damp;
}


FrictionForceClass::~FrictionForceClass()
{
}

bool FrictionForceClass::Initialize()
{
	active = true;
	return true;
}

// 并不会让摩擦力失效
bool FrictionForceClass::Frame(PhysicsComponentClass *pc, float deltatime)
{
	if (D3DXVec3Length(&pc->m_velocity) == 0) {
		return true;
	}
		
	D3DXVECTOR3 deltaVec = pc->m_velocity * damping * -1 / pc->mass * deltatime/ D3DXVec3Length(&pc->m_velocity);

	// 反向速度变话 超过了速度
	if (D3DXVec3Length(&deltaVec) > D3DXVec3Length(&pc->m_velocity)) {
		// 运动速度为0
		pc->m_velocity = D3DXVECTOR3(0,0,0);
	}
	else {
		pc->m_velocity += deltaVec;
		// 如果速度过小 让其停止运动
		// 并让摩擦力失效
		if (D3DXVec3Length(&pc->m_velocity) < 0.01) {
			pc->m_velocity = D3DXVECTOR3(0, 0, 0);
		}
	}
	return true;
}

bool FrictionForceClass::IsActive()
{
	// 返回
	return active;
}