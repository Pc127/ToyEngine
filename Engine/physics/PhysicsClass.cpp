#include "PhysicsClass.h"



PhysicsClass::PhysicsClass()
{
}


PhysicsClass::~PhysicsClass()
{
}

bool PhysicsClass::Initialize()
{
	return true;
}

void PhysicsClass::Shutdown()
{
	

}

bool PhysicsClass::Frame()
{

	// 进行碰撞检测
	CollisionDetect();
	// 循环计算 只考虑速度&时间
	//for (int i = 0; i < m_objNum; i++) {
	//	if (m_obj[i].GetVelocity() != 0) {
	//		D3DXVECTOR3 pos = m_obj[i].GetPosition() + deltaTime * m_obj[i].GetDirection() * m_obj[i].GetVelocity();
	//		m_obj[i].SetPosition(pos);
	//		 旋转
	//		float rotation = m_obj[i].GetRotation() + deltaTime * m_obj[i].GetRotationSpeed();
	//		if (rotation > 360.0f) {
	//			rotation -= 360.0f;
	//		}
	//		if (rotation < 0.0f) {
	//			rotation += 360.0f;
	//		}
	//		m_obj[i].SetRotation(rotation);
	//	}
	//}
	
	return true;
}

void PhysicsClass::GetWorldMatrix(D3DXMATRIX &worldMatrix, unsigned int i)
{

}

void PhysicsClass::GetWorldMatrixUnrotate(D3DXMATRIX &worldMatrix, unsigned int i)
{
	return;
}

unsigned int PhysicsClass::GetModelIndex(unsigned int i)
{
	return 0;
}

unsigned int PhysicsClass::GetTextureIndex(unsigned int i)
{
	return 0;
}

int PhysicsClass::GetObjCount()
{
	return 0;
}

bool PhysicsClass::CollisionDetect()
{
	//// 遍历小球
	//for (int i = 0; i < m_objNum; ++i) {
	//	// 对速度不为0的球体进行判断
	//	if (m_obj[i].GetVelocity() != 0) {
	//		D3DXVECTOR3 dir1 = m_obj[i].GetDirection();
	//		D3DXVECTOR3 pos1 = m_obj[i].GetPosition() + m_timer->DeltaTime() * m_obj[i].GetDirection() * m_obj[i].GetVelocity();
	//		float v1 = m_obj[i].GetVelocity();

	//		for (int j = 0; j < m_objNum; j++) {
	//			D3DXVECTOR3 pos2 = m_obj[j].GetPosition() + m_timer->DeltaTime() * m_obj[j].GetDirection() * m_obj[j].GetVelocity();
	//			// 两球距离
	//			D3DXVECTOR3 diff = pos1 - pos2;
	//			if (D3DXVec3Length(&diff) < 2.2f) {
	//				// 交换速度
	//				m_obj[i].SetDirection(m_obj[j].GetDirection());
	//				m_obj[i].SetVelocity(m_obj[j].GetVelocity());

	//				m_obj[j].SetDirection(dir1);
	//				m_obj[j].SetVelocity(v1);
	//			}
	//		}
	//	}
	//}

	return true;
}
