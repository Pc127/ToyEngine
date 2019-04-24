#pragma once
#include <D3DX10Math.h>
#include "MathHeader.h"

#include "ColliderClass.h"
#include "SphereColliderClass.h"

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

	// Component原则上不进行帧更新
	bool Frame();

public:
	// 根据位置获得世界矩阵
	void GetWorldMatrix(D3DXMATRIX&);
public:
	// 变量的get/set先不写了吧

public:
	// 该组件是否激活
	bool active;

	// 位置
	D3DXVECTOR3 m_position;

	// 速度
	D3DXVECTOR3 m_direction;
	float m_velocity;

	// 旋转
	float m_rotation;
	float m_rotationSpeed;

	// 物理组件的碰撞体
	ColliderClass* m_collider;
	
};