#pragma once
#include "ObjectClass.h"

#include <map>
#include <vector>

using namespace std;

class ObjectListClass {
public:
	static ObjectListClass* GetSingleton();
	bool Initialize();
private:
	ObjectListClass();
	
	vector<ObjectClass*> m_objs;
};