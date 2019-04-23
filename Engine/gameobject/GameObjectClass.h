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

	virtual bool Initialize() = 0;
	virtual bool Frame() = 0;
	virtual void Shutdown() = 0;

private:
	// 是否被激活
	bool active;

	// 渲染组件
	GraphicsComponentClass* m_GraphicsComponent;

	//物理组件
	PhysicsComponentClass* m_PhysicsComponent;
};