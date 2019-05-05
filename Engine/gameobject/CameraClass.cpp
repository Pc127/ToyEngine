#include "CameraClass.h"



CameraClass::CameraClass()
{
	m_positionX = 0.0f;
	m_positionY = 0.0f;
	m_positionZ = 0.0f;

	m_rotationX = 0.0f;
	m_rotationY = 0.0f;
	m_rotationZ = 0.0f;
}


CameraClass::~CameraClass()
{
}

CameraClass * CameraClass::GetSingleton()
{
	static CameraClass instance;
	return &instance;
}

void CameraClass::SetPosition(float x, float y, float z)
{
	m_positionX = x;
	m_positionY = y;
	m_positionZ = z;
	return;
}

void CameraClass::SetRotation(float x, float y, float z)
{
	m_rotationX = x;
	m_rotationY = y;
	m_rotationZ = z;
	return;
}

D3DXVECTOR3 CameraClass::GetPosition()
{
	return D3DXVECTOR3(m_positionX, m_positionY, m_positionZ);
}

D3DXVECTOR3 CameraClass::GetRotation()
{
	return D3DXVECTOR3(m_rotationX, m_rotationY, m_rotationZ);
}

void CameraClass::Render()
{
	D3DXVECTOR3 up, position, lookAt;
	// 偏航 俯仰 滚动
	float yaw, pitch, roll;
	D3DXMATRIX rotationMatrix;

	// 上方是x
	// 设置方向
	up.x = 1.0f;
	up.y = 0.0f;
	up.z = 0.0f;

	// 相机的世界坐标
	position.x = m_positionX;
	position.y = m_positionY;
	position.z = m_positionZ;

	// 摄像头的朝向
	// 朝向是y
	lookAt.x = 0.0f;
	lookAt.y = -1.0f;
	lookAt.z = 0.0f;

	// 旋转的设置，以弧度为单位
	pitch = m_rotationX * 0.0174532925f;
	yaw = m_rotationY * 0.0174532925f;
	roll = m_rotationZ * 0.0174532925f;

	// 创建旋转矩阵
	D3DXMatrixRotationYawPitchRoll(&rotationMatrix, yaw, pitch, roll);

	// 用旋转矩阵变换 lookAt与Up
	D3DXVec3TransformCoord(&lookAt, &lookAt, &rotationMatrix);
	D3DXVec3TransformCoord(&up, &up, &rotationMatrix);

	// 转换为观察位置
	lookAt = position + lookAt;

	// 创建视图矩阵
	// 摄像机位置+观察方向+世界空间的上向量
	D3DXMatrixLookAtLH(&m_viewMatrix, &position, &lookAt, &up);

	return;
}

void CameraClass::GetViewMatrix(D3DXMATRIX &viewMatrix)
{
	viewMatrix = m_viewMatrix;
	return;
}
