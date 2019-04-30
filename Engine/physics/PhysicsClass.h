#pragma once
#include "GameObjectClass.h"
#include "GameObjectListClass.h"
#include "CollisionDetectorClass.h"
// 受力的中心处理
#include "ForceRegistryClass.h"

class PhysicsClass
{
public:
	PhysicsClass();
	~PhysicsClass();
	// 初始化游戏obj 暂时硬编码
	// 不指定参数
	bool Initialize();
	void Shutdown();
	// 计算更新物体位置
	bool Frame(float);
	
private:
	bool CollisionDetect();
	void ExchangeVelocity(PhysicsComponentClass*, PhysicsComponentClass*);
	// 更新碰撞后的速度
	void UpdateVelocity(PhysicsComponentClass*, PhysicsComponentClass*, CollisionDetectorClass::CollisionInfo);
	// 根据不同类型 来更新碰撞速度
	void UpdateSphereVelocity(PhysicsComponentClass*, PhysicsComponentClass*, CollisionDetectorClass::CollisionInfo);
	void UpdateSphereAabbVelocity(PhysicsComponentClass*, PhysicsComponentClass*, CollisionDetectorClass::CollisionInfo);
	ForceRegistryClass* m_force;
};