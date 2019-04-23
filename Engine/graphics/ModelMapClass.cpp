#include "ModelMapClass.h"



ModelMapClass::ModelMapClass()
{

}

ModelMapClass::~ModelMapClass()
{
}

bool ModelMapClass::Initialize(ID3D11Device *device)
{
	m_device = device;

	return true;
}

ModelMapClass * ModelMapClass::GetSingleton()
{
	static ModelMapClass instance;
	return &instance;
}

void ModelMapClass::Shutdown()
{
	for_each(m_modelMap.begin(), m_modelMap.end(), [](pair<char*, ModelClass*> it) {it.second->Shutdown(); delete it.second; });
}

ModelClass * ModelMapClass::GetModel(char* modelfilename)
{
	if (m_modelMap.count(modelfilename) == 0)
		SetModel(modelfilename);
	return m_modelMap[modelfilename];
}

bool ModelMapClass::SetModel(char* modelfilename)
{
	m_modelMap[modelfilename] = new ModelClass;

	bool result;
	result = m_modelMap[modelfilename]->Initialize(m_device, modelfilename);
	if (!result) {
		return false;
	}

	return true;
}
