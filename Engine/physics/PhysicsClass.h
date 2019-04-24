#pragma once
#include "GameObjectClass.h"
#include "GameObjectListClass.h"
#include "CollisionDetectorClass.h"

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
};