#pragma once
#include "GraphicsComponentClass.h"
#include "PhysicsComponentClass.h"
#include "GameObjectListClass.h"
#include "GameObjectClass.h"
#include "GameSceneClass.h"

#include <vector>
#include <map>
#include <string>

using namespace std;

// 负责创建和销毁gameObject
class GameSceneSystemClass
{
public:
	static GameSceneSystemClass* GetSingleton();

	// 用来指定使用哪一个场景 作为首个场景
	bool Initialize(string);

	// 结束时候，析构所有场景？
	void Shutdown();

	// 设置场景
	void SetScene(string, GameSceneClass*);

	// 加载进入新的场景
	void LoadScene(string);

	// 调用该场景中 所有游戏物体的frame
	bool Frame();

public:
	string m_current;
	map<string, GameSceneClass*> m_Scenes;

private:
	GameSceneSystemClass();
	~GameSceneSystemClass();

};