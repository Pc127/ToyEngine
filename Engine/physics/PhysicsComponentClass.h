#pragma once
#include <D3DX10math.h>
#include "TimerClass.h"
#include "ObjectClass.h"

class PhysicsComponentClass
{
public:
	PhysicsComponentClass();
	~PhysicsComponentClass();
	// 初始化游戏obj 暂时硬编码
	// 不指定参数
	bool Initialize();
	void Shutdown();
	bool Frame();

	// 进行碰撞检测
	bool CollisionDetect();
private:
};