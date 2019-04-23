#include "BallOne.h"



BallOne::BallOne()
{
	Initialize();
}


BallOne::~BallOne()
{
}


bool BallOne::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", L"../Engine/data/Ball1.dds");

	this->active = true;

	return true;
}

bool BallOne::Frame()
{
	return false;
}
