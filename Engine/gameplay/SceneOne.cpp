#include "SceneOne.h"



SceneOne::SceneOne()
{
}


SceneOne::~SceneOne()
{
}

bool SceneOne::Initialize()
{
	// 场景one仅有一个物体
	m_SceneObject.push_back(new BallOne);
	m_SceneObject[0]->Initialize();

	m_SceneObject.push_back(new BallTwo);
	m_SceneObject[1]->Initialize();

	m_SceneObject.push_back(new BallOne);
	m_SceneObject[2]->Initialize();
	m_SceneObject[2]->m_PhysicsComponent->m_position = D3DXVECTOR3(4, 0, 0);

	m_SceneObject.push_back(new BallOne);
	m_SceneObject[3]->Initialize();
	m_SceneObject[3]->m_PhysicsComponent->m_position = D3DXVECTOR3(7, -0.9, 0);

	m_SceneObject.push_back(new BallOne);
	m_SceneObject[4]->Initialize();
	m_SceneObject[4]->m_PhysicsComponent->m_position = D3DXVECTOR3(7, 1.5, 0);

	// 桌子
	m_SceneObject.push_back(new Table);
	m_SceneObject[5]->Initialize();

	// 桌面
	m_SceneObject.push_back(new Desktop);
	m_SceneObject[6]->Initialize();

	return true;
}

bool SceneOne::Frame()
{
	return false;
}
