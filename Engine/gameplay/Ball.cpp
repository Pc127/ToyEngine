#include "Ball.h"



Ball::Ball(WCHAR* texture)
{
	m_Texture = texture;
	Initialize();
}


Ball::~Ball()
{
}


bool Ball::Initialize()
{
	// 注册
	Register();

	bool result;
	this->type = 1;
	m_GraphicsComponent = new GraphicsComponentClass;

	m_GraphicsComponent->Initialize("../Engine/data/ball.txt", m_Texture);

	this->active = true;

	m_PhysicsComponent = new PhysicsComponentClass;

	// 设置质量 与 碰撞体
	m_PhysicsComponent->Initialize();
	m_PhysicsComponent->mass = 1;
	m_PhysicsComponent->m_collider = new SphereColliderClass(1.2);

	// 加入摩擦力
	ForceRegistryClass::GetSingleton()->AddForce(m_PhysicsComponent, new FrictionForceClass(1.0f));

	return true;
}

// 更新旋转速度
bool Ball::Frame()
{
	// 转轴
	D3DXVECTOR3 direction;

	// 计算旋转方向
	D3DXVec3Cross(&direction, &D3DXVECTOR3(0, 1, 0), &m_PhysicsComponent->m_velocity);

	float speed;
	speed = D3DXVec3Length(&m_PhysicsComponent->m_velocity);

	D3DXVec3Normalize(&direction, &direction);

	D3DXQuaternionRotationAxis(&m_PhysicsComponent->m_rotation, &direction, speed/100);
	D3DXQuaternionNormalize(&m_PhysicsComponent->m_rotation, &m_PhysicsComponent->m_rotation);
	return true;
}
