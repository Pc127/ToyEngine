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

	m_SceneObject.push_back(new BallOne);
	m_SceneObject[1]->Initialize();

	return true;
}

bool SceneOne::Frame()
{
	return false;
}
