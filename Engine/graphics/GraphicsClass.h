#pragma once
#include <Windows.h>
#include "D3DClass.h"
#include "CameraClass.h"
#include "ModelClass.h"
//#include "ColorShaderClass.h"
#include "TextureShaderClass.h"
#include "LightClass.h"
#include "LightShaderClass.h"
#include "PhysicsClass.h"
#include "CartoonShaderClass.h"
#include "GraphicsComponentClass.h"
#include "GameObjectListClass.h"
#include "GameObjectClass.h"
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&) = default;
	~GraphicsClass() = default;

	bool Initialize(int, int, HWND);
	void Shutdown();
	bool Frame();
private:
	bool Render();
	D3DClass* m_D3D;
	CameraClass* m_Camera;

	// 渲染正面用LightShader
	LightShaderClass* m_LightShader;
	LightClass* m_Light;

	// 渲染背面用CartoonShader
	CartoonShaderClass* m_CartoonShader;
	
	TextureShaderClass* m_TextureShader;
};