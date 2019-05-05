#include "CameraClass.h"



CameraClass::Ray CameraClass::GetPickingRay(int mouseX, int mouseY, int m_screenWidth, int m_screenHeight)
{
	float pointX, pointY;
	D3DXMATRIX projectionMatrix, viewMatrix, inverseViewMatrix, worldMatrix, translateMatrix, inverseWorldMatrix;
	D3DXVECTOR3 direction, origin, rayOrigin, rayDirection;
	bool intersect, result;

	// 光标进行归一化
	pointX = ((2.0f * (float)mouseX) / (float)m_screenWidth) - 1.0f;
	pointY = (((2.0f * (float)mouseY) / (float)m_screenHeight) - 1.0f) * -1.0f;

	// 调整纵横比
	GetProjectionMatrix(projectionMatrix);
	pointX = pointX / projectionMatrix._11;
	pointY = pointY / projectionMatrix._22;

	// 获取试图矩阵的逆矩阵
	GetViewMatrix(viewMatrix);
	D3DXMatrixInverse(&inverseViewMatrix, NULL, &viewMatrix);

	// 从试图矩阵的逆 中获取方向
	direction.x = (pointX * inverseViewMatrix._11) + (pointY * inverseViewMatrix._21) + inverseViewMatrix._31;
	direction.y = (pointX * inverseViewMatrix._12) + (pointY * inverseViewMatrix._22) + inverseViewMatrix._32;
	direction.z = (pointX * inverseViewMatrix._13) + (pointY * inverseViewMatrix._23) + inverseViewMatrix._33;

	// 相机位置为光线的原点
	origin = GetPosition();

	// 翻转世界矩阵
	D3DXMatrixIdentity(&worldMatrix);
	D3DXMatrixInverse(&inverseWorldMatrix, NULL, &worldMatrix);

	D3DXVec3TransformCoord(&rayOrigin, &origin, &inverseWorldMatrix);
	D3DXVec3TransformNormal(&rayDirection, &direction, &inverseWorldMatrix);

	// 单位化方向
	D3DXVec3Normalize(&rayDirection, &rayDirection);

	Ray ray;
	ray.origin = rayOrigin;
	ray.direction = rayDirection;

	return ray;
}

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

void CameraClass::GetProjectionMatrix(D3DXMATRIX &projectionMatrix)
{
	projectionMatrix = m_projectionMatrix;
	return;
}

void CameraClass::SetProjectionMatrix(D3DXMATRIX &projectionMatrix)
{
	m_projectionMatrix = projectionMatrix;
	return;
}

void CameraClass::GetOrthoMatrix(D3DXMATRIX &orthoMatrix)
{
	orthoMatrix = m_orthoMatrix;
	return;
}

void CameraClass::SetOrthoMatrix(D3DXMATRIX &orthoMatrix)
{
	m_orthoMatrix = orthoMatrix;
	return;
}
