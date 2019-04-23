#pragma once
#include "GraphicsComponentClass.h"
#include "PhysicsComponentClass.h"
#include "GameObjectListClass.h"

class GameObjectClass
{
public:
	GameObjectClass();
	~GameObjectClass();

	bool Register();

	// 会在这里new出适用的组件
	virtual bool Initialize() = 0;
	virtual bool Frame() = 0;

	// 会调用两个组件的shutdown函数
	void Shutdown();

public:
	// 是否被激活
	bool active;

	// 渲染组件
	GraphicsComponentClass* m_GraphicsComponent;

	//物理组件
	PhysicsComponentClass* m_PhysicsComponent;
};