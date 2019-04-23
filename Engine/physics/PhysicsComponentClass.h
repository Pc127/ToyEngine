#pragma once
#include <D3DX10math.h>
#include "Eigen\Dense"

using namespace Eigen;

class PhysicsComponentClass
{
public:
	PhysicsComponentClass();
	~PhysicsComponentClass();
	// 初始化游戏obj 暂时硬编码
	// 不指定参数
	bool Initialize();
	void Shutdown();
	bool Frame();

	// 进行碰撞检测
	bool CollisionDetect();
public:
	D3DXVECTOR3 GetPosition();
	unsigned int GetModelIndex();
	unsigned int GetTextureIndex();

	D3DXVECTOR3 GetDirection();
	float GetVelocity();

	void SetVelocity(float);
	void SetPosition(D3DXVECTOR3);
	void SetDirection(D3DXVECTOR3);

	void SetRotation(float);
	void SetRotationSpeed(float);

	// 根据位置获得世界矩阵
	void GetWorldMatrix(D3DXMATRIX&);
	void GetWorldMatrixUnrotate(D3DXMATRIX&);
	// 获得旋转角度
	float GetRotation();
	float GetRotationSpeed();
public:
	D3DXVECTOR3 m_position;
	D3DXVECTOR3 m_direction;
	float m_velocity;

	// 旋转
	float m_rotation;
	float m_rotationSpeed;
	
};