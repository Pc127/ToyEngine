#pragma once

#include <D3DX10math.h>
#include "ColliderClass.h"

// 仅仅用来保存碰撞体结构与类型 不做任何处理
class AabbColliderClass:public ColliderClass
{
public:
	AabbColliderClass(D3DXVECTOR3 min, D3DXVECTOR3 max);
	~AabbColliderClass();
public:
	D3DXVECTOR3 min;
	D3DXVECTOR3 max;
};