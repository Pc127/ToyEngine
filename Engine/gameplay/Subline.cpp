﻿#include "Subline.h"

Subline::Subline(GameObjectClass *ball)
{
	this->ball = ball;
}

Subline::~Subline()
{
}


bool Subline::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/Subline.txt", L"../Engine/data/Subline.dds");

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();

	return true;
}

bool Subline::Frame()
{
	// 于球杆的距离
	float distance = 1;

	int mouseX, mouseY;
	InputClass::GetSingleton()->GetMouseLocation(mouseX, mouseY);

	int screenWidth, screenHeight;
	screenWidth = InputClass::GetSingleton()->m_screenWidth;
	screenHeight = InputClass::GetSingleton()->m_screenHeight;

	CameraClass::Ray ray = CameraClass::GetSingleton()->GetPickingRay(mouseX, mouseY, screenWidth, screenHeight);

	// 鼠标射线 与 球桌相交位置
	D3DXVECTOR3 rayPostion;
	float t = (ray.origin.y - 0)/(0-ray.direction.y);
	rayPostion = ray.origin + (ray.direction*t);

	// 白球位置
	D3DXVECTOR3 ballPostion = ball->m_PhysicsComponent->m_position;

	// 计算方向
	// 白球到射点
	D3DXVECTOR3 direction = ballPostion - rayPostion ;
	// 修正误差
	direction.y = 0;
	D3DXVec3Normalize(&direction, &direction);

	// 计算球杆 真实位置与旋转角度
	D3DXVECTOR3 stick = D3DXVECTOR3(1, 0, 0);

	float angle = D3DXVec3Dot(&stick, &direction);
	// 0到180度
	angle = std::acos(angle);

	if (direction.z > 0) {
		angle = 2*D3DX_PI - angle;
	}

	m_PhysicsComponent->m_position = ballPostion + direction*distance;
	m_PhysicsComponent->m_position.y = 0;

	// 把角度转化为四元素的方向
	D3DXQuaternionRotationAxis(&m_PhysicsComponent->m_orientation, &D3DXVECTOR3(0, 1, 0), angle);

	return true;
}