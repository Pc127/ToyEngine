#pragma once
#include "ForceGeneratorClass.h"

// 被ForceReigstry管理
// 包括注册于注销
// 作为力的抽象类
class FrictionForceClass:public ForceGeneratorClass
{
public:
	FrictionForceClass(float);
	~FrictionForceClass();

	bool Initialize();

	// 更新受力的物体
	// 如果为false表示该力的作用 需要被注销
	virtual bool Frame(PhysicsComponentClass*,float) override;

	bool IsActive();
	
protected:
	// 这里写了个active 隐藏了父类的active 导致父类active永远是true
	// bool active;

	// 阻尼系数
	// 摩擦力与速度成正比
	float damping;
};