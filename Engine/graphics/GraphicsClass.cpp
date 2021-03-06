﻿#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;

	m_LightShader = 0;
	m_Light = 0;
	m_TextureShader = 0;
	m_CartoonShader = 0;
}

bool GraphicsClass::Initialize(int screenWidth, int screenHeight, HWND hwnd)
{
	bool result;
	m_D3D = new D3DClass;
	if (!m_D3D) {
		return false;
	}
	result = m_D3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result) {
		// 再次修改了长字节
		MessageBox(hwnd, L"Could not initialize Direct3D", L"Error", MB_OK);
		return false;
	}

	// 相机模块
	m_Camera = CameraClass::GetSingleton();
	if (!m_Camera) {
		return false;
	}
	m_Camera->SetPosition(0.0f, 120.0f, 0.0f);

	// 着色器模块
	// 光照着色器
	m_LightShader = new LightShaderClass;
	if (!m_LightShader) {
		return false;
	}
	result = m_LightShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result) {
		MessageBox(hwnd, L"Could not initialize the color shader object", L"Error", MB_OK);
		return false;
	}

	m_Light = new LightClass;
	if (!m_Light) {
		return false;
	}
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	// 与相机保持一致
	m_Light->SetDirection(0.0f, -1.0f, 0.0f);
	m_Light->SetAmbientColor(0.5f, 0.5f, 0.5f, 1.0f);

	m_Light->SetSpecularColor(0.0f, 0.0f, 0.0f, 1.0f);
	//m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(0.00001f);

	// 卡通着色器
	m_CartoonShader = new CartoonShaderClass;
	if (!m_CartoonShader) {
		return false;
	}

	result = m_CartoonShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result) {
		MessageBox(hwnd, L"Could not initialize the color shader object", L"Error", MB_OK);
		return false;
	}

	m_TextureShader = new TextureShaderClass;
	if (!m_TextureShader)
	{
		return false;
	}

	// 纹理着色器
	result = m_TextureShader->Initialize(m_D3D->GetDevice(), hwnd);
	if (!result)
	{
		MessageBox(hwnd, L"Could not initialize the texture shader object.", L"Error", MB_OK);
		return false;
	}
	// 纹理与模型的单例模块 
	ModelMapClass::GetSingleton()->Initialize(m_D3D->GetDevice());
	TextureMapClass::GetSingleton()->Initialize(m_D3D->GetDevice());
	
	return true;
}

void GraphicsClass::Shutdown()
{
	if (m_LightShader)
	{
		m_LightShader->Shutdown();
		delete m_LightShader;
		m_LightShader = 0;
	}

	if (m_CartoonShader)
	{
		m_CartoonShader->Shutdown();
		delete m_CartoonShader;
		m_CartoonShader = 0;
	}

	if (m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	if (m_D3D) {
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}
	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	result = Render();
	if (!result) {
		return false;
	}
	return true;
}

bool GraphicsClass::Render()
{
	D3DXMATRIX viewMatrix, projectionMatrix, worldMatrix, orthoMatrix;
	bool result;
	// 设置背景颜色
	m_D3D->BeginScene(0.0f, 0.5f, 0.5f, 1.0f);

	m_Camera->Render();
	// 从相机设置视图矩阵
	m_Camera->GetViewMatrix(viewMatrix);
	// 从相机设置投影矩阵
	m_Camera->GetProjectionMatrix(projectionMatrix);

	
	// 进行物理系统的更新
	// m_physics->Frame();

	// 模型准备数据
	for (GameObjectClass* gameobject : GameObjectListClass::GetSingleton()->m_GameObjects) {
		if (gameobject->active && gameobject->m_GraphicsComponent) {

			GraphicsComponentClass* gc = gameobject->m_GraphicsComponent;

			// 获取世界矩阵
			if (gameobject->m_PhysicsComponent) {
				gameobject->m_PhysicsComponent->GetWorldMatrix(worldMatrix);
			}

			// 模型配置到渲染流水线
			gc->m_Model->Render(m_D3D->GetDeviceContext());

			if (gc->isUi == false) {
				// 渲染3d物体
				// 渲染背面
				m_D3D->RenderBack();
				result = m_CartoonShader->Render(m_D3D->GetDeviceContext(), gc->m_Model->GetIndexCount(),
					worldMatrix, viewMatrix, projectionMatrix);
				if (!result) {
					return false;
				}

				// 渲染正面
				m_D3D->RenderFront();
				result = m_LightShader->Render(m_D3D->GetDeviceContext(), gc->m_Model->GetIndexCount(),
					worldMatrix, viewMatrix, projectionMatrix, gc->m_Texture, m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
					m_Camera->GetPosition(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
				if (!result) {
					return false;
				}
			}
			else {
				// 渲染ui
				m_D3D->TurnZBufferOff();
				m_D3D->TurnOnAlphaBlending();

				// 从相机设置视图矩阵
				m_Camera->GetUiViewMatrix(viewMatrix);
				// 从相机设置投影矩阵
				m_Camera->GetOrthoMatrix(projectionMatrix);

				result = m_TextureShader->Render(m_D3D->GetDeviceContext(), gc->m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix, gc->m_Texture);
				if (!result)
				{
					return false;
				}
				m_D3D->TurnZBufferOn();
				m_D3D->TurnOffAlphaBlending();
			}
			
		}
	}

	m_D3D->EndScene();

	return true;
}
