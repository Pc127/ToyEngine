#pragma once
#include "GameObjectClass.h"
#include "GameObjectListClass.h"
#include "CollisionDetectorClass.h"

// 被ForceReigstry管理
// 包括注册于注销
// 作为力的抽象类
class ForceGeneratorClass
{
public:
	ForceGeneratorClass();
	virtual ~ForceGeneratorClass();

	// 初始化
	bool Initialize();

	// 更新受力的物体
	// 如果为false表示该力的作用 需要被注销
	virtual bool Frame(PhysicsComponentClass*,float) = 0;

	bool IsActive();
	
protected:
	bool active;
};