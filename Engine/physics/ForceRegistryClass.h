#pragma once
#include "GameObjectClass.h"
#include "GameObjectListClass.h"
#include "CollisionDetectorClass.h"
#include "ForceGeneratorClass.h"

#include <list>

using namespace std;

class ForceRegistryClass
{
public:
	// 保存物理模块 与 力的作用器
	struct ForceRegistration {
		PhysicsComponentClass* physics;
		ForceGeneratorClass* force;
	};
public:
	static ForceRegistryClass* GetSingleton();

	// 向作用力中央单元注册自己
	bool Initialize();

	// 向作用力发生器中注销自己
	void Shutdown();

	// 更新受力的物体 
	bool Frame(float);

	// 加入一个力
	bool AddForce(PhysicsComponentClass*, ForceGeneratorClass*);
	
private:
	// 检查list中是否有失效的力
	void CheckList();

	// 保存了 力与对应的作用物体
	list<ForceRegistration> m_Force;
	// 保证了单例模式
	ForceRegistryClass();
	~ForceRegistryClass();
};