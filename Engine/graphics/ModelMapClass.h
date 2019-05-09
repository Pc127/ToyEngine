#pragma once
#include <d3d11.h>
#include <D3DX10math.h>
#include "TextureClass.h"
#include "ModelClass.h"
#include "InputClass.h"
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;


class ModelMapClass
{
public:
	static ModelMapClass* GetSingleton();

	bool Initialize(ID3D11Device*);

	void Shutdown();

	ModelClass* GetModel(char*);

	bool SetModel(char*);
	
	bool SetUiModel(char*, int, int);
private:
	ModelMapClass();
	ModelMapClass(const ModelMapClass&) = delete;
	~ModelMapClass();
private:
	ID3D11Device* m_device;
	map<char*, ModelClass*> m_modelMap;
};