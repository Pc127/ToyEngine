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

	this->type = 0;
	m_Bitmapname = new bitmapStruct;
	m_GraphicsComponent = new GraphicsComponentClass;
	this->m_Bitmapname->ScreenWidth = 800;
	this->m_Bitmapname->ScreenHeight = 600;
	this->m_Bitmapname->bitmapHeight = 100;
	this->m_Bitmapname->bitmapWidth = 100;
	
	m_GraphicsComponent->Initialize(m_Bitmapname, m_Texture);

	this->active = true;


	m_PhysicsComponent = new PhysicsComponentClass;
	// 速度静止
	m_PhysicsComponent->Initialize();

	return true;
}

bool Title::Frame()
{
	return false;
}
