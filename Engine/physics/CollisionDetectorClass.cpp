#include "CollisionDetectorClass.h"



CollisionDetectorClass * CollisionDetectorClass::GetSingleton()
{
	return nullptr;
}

bool CollisionDetectorClass::Detect(PhysicsComponentClass *pc1, PhysicsComponentClass *pc2, float deltatime)
{
	ColliderClass* c1 = pc1->m_collider;
	ColliderClass* c2 = pc2->m_collider;

	if (c1 == 0 || c2 == 0)
		return false;
	if (c1->m_type == ColliderType::SPHRER && c2->m_type == ColliderType::SPHRER) {
		// 计算新的位置
		D3DXVECTOR3 p1 = pc1->m_position + deltatime*pc1->m_velocity;
		D3DXVECTOR3 p2 = pc2->m_position + deltatime*pc2->m_velocity;
		return DetectSphere(dynamic_cast<SphereColliderClass*>(c1), dynamic_cast<SphereColliderClass*>(c2), p1, p2);
	}

	return false;
}

// 检测更新后的位置是否会产生碰撞
bool CollisionDetectorClass::DetectSphere(SphereColliderClass *sc1, SphereColliderClass *sc2, D3DXVECTOR3 p1, D3DXVECTOR3 p2)
{
	D3DXVECTOR3 distance;
	D3DXVec3Subtract(&distance, &p1, &p2);

	if (D3DXVec3Length(&distance) > sc1->radius + sc2->radius)
		return false;

	return true;
}

CollisionDetectorClass::CollisionDetectorClass()
{
}


CollisionDetectorClass::~CollisionDetectorClass()
{
}
