#include "Title.h"

Title::Title(WCHAR* texture)
{
	m_Texture = texture;
	Initialize();
}


Title::~Title()
{
}


bool Title::Initialize()
{

	bool result;

	// 注册
	Register();

	// 需要先创建模型数据
	ModelMapClass::GetSingleton()->SetUiModel("title", 1000, 200);
	
	m_GraphicsComponent = new GraphicsComponentClass;
	m_GraphicsComponent->Initialize("title", m_Texture);
	m_GraphicsComponent->isUi = true;

	this->active = true;


	m_PhysicsComponent = new PhysicsComponentClass;
	// 速度静止
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->m_position = D3DXVECTOR3(350,0,0);

	return true;
}

bool Title::Frame()
{
	return false;
}
