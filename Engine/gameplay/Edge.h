#pragma once
#include "GameObjectClass.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
#include "AabbColliderClass.h"

class Edge:public GameObjectClass
{
public:
	Edge(D3DXVECTOR3 min, D3DXVECTOR3 max);
	~Edge();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
private:
	D3DXVECTOR3 min;
	D3DXVECTOR3 max;
};

