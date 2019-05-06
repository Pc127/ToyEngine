#pragma once
#include "ColliderClass.h"
#include "SphereColliderClass.h"
#include "AabbColliderClass.h"
#include "PhysicsComponentClass.h"

// 用来设置分离后的偏移位置 防止浮点误差
// const float deltaDistance = 0.01f;

// 检测器 设置为单例 封装了检测碰撞的算法
class CollisionDetectorClass
{
public:
	// 是否碰撞 相交时间 分离冲量
	struct CollisionInfo {
		bool hasCollide;
		float collidetime;
		float impluse;
		D3DXVECTOR3 normal;
	};
public:
	static CollisionDetectorClass* GetSingleton();
	// 不指定参数
	CollisionInfo Detect(PhysicsComponentClass*, PhysicsComponentClass*, float);
private:
	CollisionInfo DetectSphere(PhysicsComponentClass*, PhysicsComponentClass*, SphereColliderClass*, SphereColliderClass*, float);
	CollisionInfo DetectAabb(PhysicsComponentClass*, PhysicsComponentClass*, AabbColliderClass*, AabbColliderClass*, float);

	// 检测球与aabb的相交
	// AABB盒并不移动
	CollisionInfo DetectSphereAabb(PhysicsComponentClass*, PhysicsComponentClass*, SphereColliderClass*, AabbColliderClass*, float);

	CollisionDetectorClass();
	~CollisionDetectorClass();
};