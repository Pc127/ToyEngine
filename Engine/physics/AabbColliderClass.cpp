#include "AabbColliderClass.h"



AabbColliderClass::AabbColliderClass(D3DXVECTOR3 min, D3DXVECTOR3 max)
{
	this->min = min;
	this->max = max;
	this->m_type = ColliderType::AABB;
}


AabbColliderClass::~AabbColliderClass()
{
}

