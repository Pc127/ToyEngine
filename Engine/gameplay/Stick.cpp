﻿#include "Stick.h"

Stick::Stick(GameObjectClass *ball)
{
	this->ball = ball;
}

Stick::~Stick()
{
}


bool Stick::Initialize()
{
	// 注册
	Register();

	bool result;

	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/Stick.txt", L"../Engine/data/Stick.dds");

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();

	return true;
}

bool Stick::Frame()
{
	// 于球杆的距离
	static float distance = 1;


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
	// 射点到白球
	D3DXVECTOR3 direction = rayPostion - ballPostion;
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

	static int count = 0;

	if (InputClass::GetSingleton()->IsLeftMouseButtonDown()) {
		if(count<400)
			++count;
		distance = count/30 + 1;
	}
	else {
		distance = 1;
		if (count > 0) {
			float force = count*0.1;
			if (force > 40)
				force = 40;
			ball->m_PhysicsComponent->m_velocity = direction * -force;
			count = 0;
		}
	}

	return true;
}