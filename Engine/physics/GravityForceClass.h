#pragma once
#include "ForceGeneratorClass.h"

// 被ForceReigstry管理
// 包括注册于注销
// 作为力的抽象类
class GravityForceClass:public ForceGeneratorClass
{
public:
	GravityForceClass(D3DXVECTOR3);
	~GravityForceClass();

	bool Initialize();

	// 更新受力的物体
	// 如果为false表示该力的作用 需要被注销
	virtual bool Frame(PhysicsComponentClass*,float) override;

	bool IsActive();
	
protected:
	// 阻尼系数
	// 摩擦力与速度成正比
	D3DXVECTOR3 gravity;
};