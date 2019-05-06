#pragma once
#include "ColliderClass.h"

// 仅仅用来保存碰撞体结构与类型 不做任何处理
class SphereColliderClass:public ColliderClass
{
public:
	SphereColliderClass(float);
	~SphereColliderClass();
	// 初始化游戏obj 暂时硬编码
	// 不指定参数
public:
	float radius;
};