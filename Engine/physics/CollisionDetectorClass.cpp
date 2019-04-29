#include "CollisionDetectorClass.h"



CollisionDetectorClass * CollisionDetectorClass::GetSingleton()
{
	return nullptr;
}

CollisionDetectorClass::CollisionInfo CollisionDetectorClass::Detect(PhysicsComponentClass *pc1, PhysicsComponentClass *pc2, float deltatime)
{
	ColliderClass* c1 = pc1->m_collider;
	ColliderClass* c2 = pc2->m_collider;

	CollisionInfo info;
	info.hasCollide = false;

	// 没有碰撞体 自然不会碰撞
	if (c1 == 0 || c2 == 0) {
		return info;
	}

	if (c1->m_type == ColliderType::SPHRER && c2->m_type == ColliderType::SPHRER) {
		// 归入球类碰撞体中 进行判断
		return DetectSphere(pc1, pc2, dynamic_cast<SphereColliderClass*>(c1), dynamic_cast<SphereColliderClass*>(c2), deltatime);
	}

	return info;
}

// 检测更新后的位置是否会产生碰撞
CollisionDetectorClass::CollisionInfo CollisionDetectorClass::DetectSphere(PhysicsComponentClass *pc1, PhysicsComponentClass *pc2, SphereColliderClass *sc1, SphereColliderClass *sc2, float deltatime)
{
	CollisionInfo info;

	// 闭合速度
	// 相当于球2静止
	D3DXVECTOR3 closingVel = pc1->m_velocity;
	closingVel -= pc2->m_velocity;

	// 位置方向
	D3DXVECTOR3 posDir = pc2->m_position;
	posDir -= pc1->m_position;

	// 距离
	float dif = D3DXVec3Length(&posDir);

	// 归一化
	D3DXVec3Normalize(&posDir, &posDir);

	// 分离速度
	float closingSpd = D3DXVec3Dot(&closingVel, &posDir);

	// 不会产生碰撞的情况
	// 两球体相交的情况
	if (closingSpd <= 0 || closingSpd * deltatime <= dif - sc1->radius - sc2->radius) {
		info.hasCollide = false;
		return info;
	}

	// 碰撞的时间
	float collidetime = (dif - sc1->radius - sc2->radius) / closingSpd;

	info.hasCollide = true;
	info.collidetime = collidetime;
	// 弹性碰撞 的冲量计算
	info.impluse = 2*closingSpd/(pc1->mass+pc2->mass);

	return info;
}

CollisionDetectorClass::CollisionDetectorClass()
{
}


CollisionDetectorClass::~CollisionDetectorClass()
{
}
