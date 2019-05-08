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
	// 该组件是否激活
	bool active;

	// 位置
	D3DXVECTOR3 m_position;

	// 速度
	D3DXVECTOR3 m_velocity;

	// 方向
	// 要保证是单位矩阵
	D3DXQUATERNION m_orientation;

	// 旋转速度
	// 要保证为对象坐标
	D3DXQUATERNION m_rotation;

	// 质量
	float mass = 1;

	// 物理组件的碰撞体
	ColliderClass* m_collider;
	
};