#pragma once
#include "ObjectClass.h"

#include <map>
#include <vector>

using namespace std;

class GameObjectClass;

class GameObjectListClass {
public:
	static GameObjectListClass* GetSingleton();
	bool Initialize();

	bool Insert(GameObjectClass*);

	vector<GameObjectClass*> m_GameObjects;

private:
	GameObjectListClass();
};