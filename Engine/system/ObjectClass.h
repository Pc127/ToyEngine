#pragma once
#include <D3DX10math.h>

class ObjectClass
{
public:
	ObjectClass();
	~ObjectClass();

	bool Initialize(unsigned int, unsigned int, D3DXVECTOR3, D3DXVECTOR3, float, float, float);
	void Shutdown();

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
private:
	D3DXVECTOR3 m_position;
	D3DXVECTOR3 m_direction;
	float m_velocity;

	// 旋转
	float m_rotation;
	float m_rotationSpeed;

	// 索引的模型
	unsigned int m_modelIndex;
	unsigned int m_textureIndex;
};