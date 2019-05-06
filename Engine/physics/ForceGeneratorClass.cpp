#include "ForceGeneratorClass.h"



ForceGeneratorClass::ForceGeneratorClass()
{
}


ForceGeneratorClass::~ForceGeneratorClass()
{
}

bool ForceGeneratorClass::Initialize()
{
	active = true;
	return true;
}

bool ForceGeneratorClass::IsActive()
{
	// 返回
	return active;
}

