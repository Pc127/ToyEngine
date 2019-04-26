#include "PhysicsClass.h"



PhysicsClass::PhysicsClass()
{
}


PhysicsClass::~PhysicsClass()
{
}

bool PhysicsClass::Initialize()
{
	// 获取了单例
	m_force = ForceRegistryClass::GetSingleton();
	m_force->Initialize();
	return true;
}

void PhysicsClass::Shutdown()
{
	m_force->Shutdown();

}

bool PhysicsClass::Frame(float deltatime)
{
	// 用来进行碰撞检测
	for (GameObjectClass* gameobject : GameObjectListClass::GetSingleton()->m_GameObjects) {
		if (gameobject->active && gameobject->m_PhysicsComponent) {
			PhysicsComponentClass* pc = gameobject->m_PhysicsComponent;
			// 对速度不为0的物体进行碰撞检测
			if (true) {
				// 滤去在该游戏物体之前的物体
				bool index = false;
				for (GameObjectClass* gameobject2 : GameObjectListClass::GetSingleton()->m_GameObjects) {
					// 相同物体跳过检测
					if (!index && gameobject2 == gameobject) {
						index = true;
						continue;
					}				
					if (CollisionDetectorClass::GetSingleton()->Detect(pc, gameobject2->m_PhysicsComponent, deltatime)) {
						// 发生碰撞时的处理
						ExchangeVelocity(pc, gameobject2->m_PhysicsComponent);
					};
				}
			}

		}
	}

	// 处理受力 与 速度更新
	m_force->Frame(deltatime);

	// 用来更新位置
	for (GameObjectClass* gameobject : GameObjectListClass::GetSingleton()->m_GameObjects) {
		if (gameobject->active && gameobject->m_PhysicsComponent) {

			PhysicsComponentClass* pc = gameobject->m_PhysicsComponent;

			pc->m_position += deltatime*pc->m_velocity;

		}
	}

	return true;
}

bool PhysicsClass::CollisionDetect()
{
	return false;
}

void PhysicsClass::ExchangeVelocity(PhysicsComponentClass *pc1, PhysicsComponentClass *pc2)
{
	D3DXVECTOR3  velo = pc1->m_velocity;

	pc1->m_velocity = pc2->m_velocity;

	pc2->m_velocity = velo;
}
