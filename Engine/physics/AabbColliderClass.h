﻿#pragma once
#include "ColliderClass.h"

#include <D3DX10math.h>

// 仅仅用来保存碰撞体结构与类型 不做任何处理
class AabbColliderClass:public ColliderClass
{
public:
	AabbColliderClass(float);
	~AabbColliderClass();
public:
	// D3DXVECTOR3;
};