#include "Ui.h"


Ui::Ui(char* uuid, WCHAR * texture, int width, int height)
{
	this->uuid = uuid;
	m_Texture = texture;
	this->width = width;
	this->height = height;
	Initialize();
}

Ui::~Ui()
{
}


bool Ui::Initialize()
{

	bool result;

	// 注册
	Register();

	// 需要先创建模型数据
	ModelMapClass::GetSingleton()->SetUiModel(uuid, width, height);
	
	m_GraphicsComponent = new GraphicsComponentClass;
	m_GraphicsComponent->Initialize(uuid, m_Texture);
	m_GraphicsComponent->isUi = true;

	this->active = true;


	m_PhysicsComponent = new PhysicsComponentClass;
	// 速度静止
	m_PhysicsComponent->Initialize();

	return true;
}

bool Ui::Frame()
{
	return false;
}
