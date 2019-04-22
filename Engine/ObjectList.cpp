#include "ObjectList.h"

ObjectListClass * ObjectListClass::GetSingleton()
{
	static ObjectListClass m_object;
}

bool ObjectListClass::Initialize()
{
	return false;
}

ObjectListClass::ObjectListClass()
{
}
