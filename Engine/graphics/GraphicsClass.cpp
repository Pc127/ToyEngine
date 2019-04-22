#include "GraphicsClass.h"

GraphicsClass::GraphicsClass()
{
	m_D3D = 0;
	m_Camera = 0;
	m_Model = 0;

	m_LightShader = 0;
	m_Light = 0;
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
	m_Camera = new CameraClass;
	if (!m_Camera) {
		return false;
	}
	m_Camera->SetPosition(0.0f, 0.0f, -15.0f);

	// 模型模块
	m_MoelCount = 1;
	m_Model = new ModelClass[m_MoelCount];
	if (!m_Model) {
		return false;
	}
	// result = m_Model[0].Initialize(m_D3D->GetDevice(), "../Engine/data/cube.txt");
	result = m_Model[0].Initialize(m_D3D->GetDevice(), "../Engine/data/ball.txt");
	if (!result) {
		MessageBox(hwnd, L"Could not initialize the model object", L"Error", MB_OK);
		return false;
	}

	// 纹理模块
	m_Texture = new TextureClass[3];
	if (!m_Texture) {
		return false;
	}
	result = m_Texture[0].Initialize(m_D3D->GetDevice(), L"../Engine/data/Ball1.dds");
	if (!result) {
		return false;
	}
	result = m_Texture[1].Initialize(m_D3D->GetDevice(), L"../Engine/data/Ball2.dds");
	if (!result) {
		return false;
	}
	result = m_Texture[2].Initialize(m_D3D->GetDevice(), L"../Engine/data/Ball3.dds");
	if (!result) {
		return false;
	}

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
	m_Light->SetDirection(1.0f, 0.0f, 0.0f);
	m_Light->SetAmbientColor(1.0f, 1.0f, 1.0f, 1.0f);

	m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetSpecularPower(16.0f);

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

	// 物理模块
	m_physics = new PhysicsClass;
	if (!m_physics) {
		return false;
	}
	m_physics->Initialize();
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

	if (m_Model)
	{
		m_Model->Shutdown();
		delete[] m_Model;
		m_Model = 0;
	}

	if (m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}
	if (m_D3D) {
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}
	if (m_Texture) {
		m_Texture->Shutdown();
		m_Texture = 0;
	}
	return;
}

bool GraphicsClass::Frame()
{
	bool result;
	// 设置旋转
	static float rotation = 0.0f;
	rotation += (float)D3DX_PI*0.01f;
	if (rotation > 360.0f) {
		rotation -= 360.0f;
	}
	result = Render(rotation);
	if (!result) {
		return false;
	}
	return true;
}

bool GraphicsClass::Render(float rotation)
{
	D3DXMATRIX viewMatrix, projectionMatrix, worldMatrix;
	bool result;
	// 设置背景颜色
	m_D3D->BeginScene(0.0f, 0.5f, 0.5f, 1.0f);

	m_Camera->Render();
	// 从相机设置视图矩阵
	m_Camera->GetViewMatrix(viewMatrix);
	// 从dxd设置世界与投影矩阵
	m_D3D->GetWorldMatrix(worldMatrix);
	m_D3D->GetProjectionMatrix(projectionMatrix);

	// 通过旋转矩阵，对世界矩阵进行旋转
    //D3DXMatrixRotationY(&worldMatrix, rotation);

	// 进行物理系统的更新
	m_physics->Frame();

	// 模型准备数据
	for (int j = 0; j < m_MoelCount; j++) {
		m_Model[j].Render(m_D3D->GetDeviceContext());

		for (int i = 0; i < m_physics->GetObjCount(); i++) {
			if (m_physics->GetModelIndex(i) != j)
				continue;

			// 渲染正面
			m_D3D->RenderFront();
			m_physics->GetWorldMatrix(worldMatrix, i);
			result = m_LightShader->Render(m_D3D->GetDeviceContext(), m_Model[j].GetIndexCount(),
				worldMatrix, viewMatrix, projectionMatrix, m_Texture[m_physics->GetTextureIndex(i)].GetTexture(), m_Light->GetDirection(),m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
				m_Camera->GetPosition(),m_Light->GetSpecularColor(),m_Light->GetSpecularPower());
			if (!result) {
				return false;
			}

			// 渲染背面
			m_D3D->RenderBack();
			m_physics->GetWorldMatrix(worldMatrix, i);
			result = m_CartoonShader->Render(m_D3D->GetDeviceContext(), m_Model[j].GetIndexCount(),
				worldMatrix, viewMatrix, projectionMatrix);
			if (!result) {
				return false;
			}
					
		}
	}

	m_D3D->EndScene();

	return true;
}
