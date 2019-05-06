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
	else if(c1->m_type == ColliderType::AABB && c2->m_type == ColliderType::AABB)
	{
		// 判断两个aabb盒 是否相交
		return DetectAabb(pc1, pc2, dynamic_cast<AabbColliderClass*>(c1), dynamic_cast<AabbColliderClass*>(c2), deltatime);
	}
	else if (c1->m_type == ColliderType::AABB && c2->m_type == ColliderType::SPHRER) {
		// 判断aabb 与 球是否相交
		return DetectSphereAabb(pc2, pc1, dynamic_cast<SphereColliderClass*>(c2), dynamic_cast<AabbColliderClass*>(c1), deltatime);
	}
	else if (c1->m_type == ColliderType::SPHRER && c2->m_type == ColliderType::AABB) {
		// 判断aabb 与 球是否相交
		return DetectSphereAabb(pc1, pc2, dynamic_cast<SphereColliderClass*>(c1), dynamic_cast<AabbColliderClass*>(c2), deltatime);
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

CollisionDetectorClass::CollisionInfo CollisionDetectorClass::DetectAabb(PhysicsComponentClass *, PhysicsComponentClass *, AabbColliderClass *, AabbColliderClass *, float)
{
	// aabb盒子 就不进行相交性检测了把
	// 懒得写
	CollisionInfo info;
	info.hasCollide = false;

	return info;
}

// 假定aabb盒子 并不会移动
CollisionDetectorClass::CollisionInfo CollisionDetectorClass::DetectSphereAabb(PhysicsComponentClass *sphere_physic, PhysicsComponentClass *aabb_physic, SphereColliderClass *sphere_col, AabbColliderClass *aabb_col, float deltatime)
{
	CollisionInfo info;

	// aabb到球最近点
	D3DXVECTOR3 nearpoint;

	// 圆心设为 更新之后的圆心
	D3DXVECTOR3 oldpoint = sphere_physic->m_position;
	D3DXVECTOR3 circlepoint = sphere_physic->m_position + deltatime * sphere_physic->m_velocity;

	// 求normal 代表了点 在哪一个维度
	D3DXVECTOR3 normal;

	// 分x y z三个维度 计算出最近点
	// x维度
	if (circlepoint.x < aabb_col->min.x) {
		nearpoint.x = aabb_col->min.x;
		normal.x = -1;
	}
	else if (circlepoint.x > aabb_col->max.x) {
		nearpoint.x = aabb_col->max.x;
		normal.x = 1;
	}
	else {
		nearpoint.x = circlepoint.x;
		normal.x = 0;
	}
	// y维度
	if (circlepoint.y < aabb_col->min.y) {
		nearpoint.y = aabb_col->min.y;
		normal.y = -1;
	}
	else if (circlepoint.y > aabb_col->max.y) {
		nearpoint.y = aabb_col->max.y;
		normal.y = 1;
	}
	else {
		nearpoint.y = circlepoint.y;
		normal.y = 0;
	}
	// z维度
	if (circlepoint.z < aabb_col->min.z) {
		nearpoint.z = aabb_col->min.z;
		normal.z = -1;
	}
	else if (circlepoint.z > aabb_col->max.z) {
		nearpoint.z = aabb_col->max.z;
		normal.z = 1;
	}
	else {
		nearpoint.z = circlepoint.z;
		normal.z = 0;
	}

	// 归一化为碰撞法线
	D3DXVec3Normalize(&normal, &normal);

	// 最近点到圆心的距离
	D3DXVECTOR3 diff = nearpoint;
	diff -= circlepoint;

	// 距离
	float dis = D3DXVec3Length(&diff);

	// 在内 或者 距离小于半径 时候相交
	if (D3DXVec3Length(&normal)==0||dis<sphere_col->radius) {
		info.hasCollide = true;
	}
	else {
		info.hasCollide = false;
		return info;
	}

	// 闭合速度
	// 相当于 aabb 静止
	D3DXVECTOR3 closingVel = sphere_physic->m_velocity;
	closingVel -= aabb_physic->m_velocity;

	// 分离速度
	float closingSpd = D3DXVec3Dot(&closingVel, &normal);
	if (closingSpd < 0)
		closingSpd = -closingSpd;
	else if (closingSpd == 0)
	{
		info.hasCollide = false;
		return info;
	}

	// 最近点到最初圆心的距离
	diff = nearpoint;
	diff -= oldpoint;
	dis = D3DXVec3Length(&diff);

	// 碰撞的时间
	float collidetime = (dis-sphere_col->radius) / closingSpd;

	info.hasCollide = true;
	info.collidetime = collidetime;
	// 弹性碰撞 的冲量计算
	// aabb盒并不移动
	info.impluse = 0;
	info.normal = normal;

	return info;
}

CollisionDetectorClass::CollisionDetectorClass()
{
}


CollisionDetectorClass::~CollisionDetectorClass()
{
}
