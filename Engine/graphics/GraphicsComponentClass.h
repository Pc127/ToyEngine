#pragma once
#include <Windows.h>
#include "D3DClass.h"
#include "CameraClass.h"
#include "ModelClass.h"
//#include "ColorShaderClass.h"
//#include "TextureShaderClass.h"
#include "ModelMapClass.h"
#include "TextureMapClass.h"


class GraphicsComponentClass
{
public:
	GraphicsComponentClass();
	GraphicsComponentClass(const GraphicsComponentClass&) = delete;
	~GraphicsComponentClass() = default;

	bool Initialize(char*, WCHAR*);
	void Shutdown();
private:
	ModelClass* m_Model;
	ID3D11ShaderResourceView* m_Texture;
};