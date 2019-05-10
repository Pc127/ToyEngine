﻿#include "AiPlayer.h"



AiPlayer::AiPlayer()
{
	Initialize();
}


AiPlayer::~AiPlayer()
{
}


bool AiPlayer::Initialize()
{
	// 注册
	Register();

	bool result;
	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/Table.txt", L"../Engine/data/Table.dds");

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;
	// 速度静止
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 0);

	return true;
}

bool AiPlayer::Frame()
{
	return false;
}
