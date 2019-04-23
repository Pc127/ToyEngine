#include "ObjectListClass.h"

ObjectListClass * ObjectListClass::GetSingleton()
{
	static ObjectListClass m_object;
	return &m_object;
}

bool ObjectListClass::Initialize()
{
	return false;
}

ObjectListClass::ObjectListClass()
{
}
