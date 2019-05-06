#pragma once

#include <map>
#include <vector>

using namespace std;

class GameObjectClass;

// 仅仅作为中介者 不创建 或者 销毁gameobject
class GameObjectListClass {
public:
	static GameObjectListClass* GetSingleton();
	bool Initialize();

	bool Insert(GameObjectClass*);

	vector<GameObjectClass*> m_GameObjects;

private:
	GameObjectListClass();
};