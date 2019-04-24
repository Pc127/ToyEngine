#pragma once
#include "ColliderClass.h"
#include "SphereColliderClass.h"
#include "PhysicsComponentClass.h"

// 检测器 设置为单例 封装了检测碰撞的算法
class CollisionDetectorClass
{
public:
	static CollisionDetectorClass* GetSingleton();
	// 初始化游戏obj 暂时硬编码
	// 不指定参数
	bool Detect(PhysicsComponentClass*, PhysicsComponentClass*, float);
private:
	bool DetectSphere(SphereColliderClass*, SphereColliderClass*, D3DXVECTOR3, D3DXVECTOR3);
	CollisionDetectorClass();
	~CollisionDetectorClass();
};