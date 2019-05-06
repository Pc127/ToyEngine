#include "PhysicsComponentClass.h"



PhysicsComponentClass::PhysicsComponentClass()
{
}


PhysicsComponentClass::~PhysicsComponentClass()
{
}

bool PhysicsComponentClass::Initialize()
{
	m_position = D3DXVECTOR3(0, 0, 0);
	m_velocity = D3DXVECTOR3(0, 0, 0);
	m_rotation = 0;
	return true;
}

void PhysicsComponentClass::Shutdown()
{
	if (m_collider) {
		delete m_collider;
		m_collider = 0;
	}
}

bool PhysicsComponentClass::Frame()
{
	
	return true;
}


void PhysicsComponentClass::GetWorldMatrix(D3DXMATRIX &worldMatrix)
{
	D3DXMatrixIdentity(&worldMatrix);
	// 仅仅进行位移操作
	D3DXMatrixTranslation(&worldMatrix, m_position.x, m_position.y, m_position.z);


	// 旋转操作
	if (m_rotation != 0) {
		D3DXMATRIX rotationMatrix;
		D3DXMatrixIdentity(&rotationMatrix);
		D3DXMatrixRotationY(&rotationMatrix, m_rotation);
		D3DXMatrixMultiply(&worldMatrix, &rotationMatrix, &worldMatrix);
	}
}
