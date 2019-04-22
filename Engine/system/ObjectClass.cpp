#include "ObjectClass.h"

ObjectClass::ObjectClass()
{
}


ObjectClass::~ObjectClass()
{
}

bool ObjectClass::Initialize(unsigned int model, unsigned int texture, D3DXVECTOR3 pos, D3DXVECTOR3 dir, float velocity, float rotation, float rotationSpeed)
{
	m_textureIndex = texture;
	m_modelIndex = model;
	m_position = pos;
	m_direction = dir;
	m_velocity = velocity;

	m_rotation = rotation;
	m_rotationSpeed = rotationSpeed;

	return true;
}

void ObjectClass::Shutdown()
{
}

D3DXVECTOR3 ObjectClass::GetPosition()
{
	return m_position;
}

unsigned int ObjectClass::GetModelIndex()
{
	return m_modelIndex;
}

unsigned int ObjectClass::GetTextureIndex()
{
	return m_textureIndex;
}

D3DXVECTOR3 ObjectClass::GetDirection()
{
	return m_direction;
}

float ObjectClass::GetVelocity()
{
	return m_velocity;
}

void ObjectClass::SetVelocity(float v)
{
	m_velocity = v;
}

void ObjectClass::SetPosition(D3DXVECTOR3 pos)
{
	m_position = pos;
}

void ObjectClass::SetDirection(D3DXVECTOR3 dir)
{
	m_direction = dir;
}

void ObjectClass::SetRotation(float r)
{
	m_rotation = r;
}

void ObjectClass::SetRotationSpeed(float s)
{
	m_rotationSpeed = s;
}

void ObjectClass::GetWorldMatrix(D3DXMATRIX &worldMatrix)
{
	D3DXMatrixIdentity(&worldMatrix);
	D3DXMATRIX rotation;
	D3DXMATRIX resultMatrix;

	
	// 根据当前位置进行移动
	D3DXMatrixRotationY(&rotation, m_rotation);
	D3DXMatrixTranslation(&resultMatrix, m_position.x, m_position.y, m_position.z);
	worldMatrix = rotation*resultMatrix;
}

void ObjectClass::GetWorldMatrixUnrotate(D3DXMATRIX &worldMatrix)
{
	D3DXMatrixIdentity(&worldMatrix);

	D3DXMATRIX resultMatrix;
	D3DXMatrixTranslation(&resultMatrix, m_position.x, m_position.y, m_position.z);

	worldMatrix = resultMatrix;
}

float ObjectClass::GetRotation()
{
	return m_rotation;
}

float ObjectClass::GetRotationSpeed()
{
	return m_rotationSpeed;
}
