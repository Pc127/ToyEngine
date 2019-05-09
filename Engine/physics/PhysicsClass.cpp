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
	auto gameobjs = GameObjectListClass::GetSingleton()->m_GameObjects;
	for (auto it = gameobjs.begin(); it != gameobjs.end(); ++it ) {
		if ((*it)->active && (*it)->m_PhysicsComponent) {
			PhysicsComponentClass* pc = (*it)->m_PhysicsComponent;
			// 滤去在该游戏物体之前的物体
			// 避免一次碰撞检测进行两次
			for (auto it2 = it; it2 != gameobjs.end();++it2) {
				if ((*it2)->active && (*it2)->m_PhysicsComponent) {
					CollisionDetectorClass::CollisionInfo info;
					PhysicsComponentClass* pc2 = (*it2)->m_PhysicsComponent;
					info = CollisionDetectorClass::GetSingleton()->Detect(pc, pc2, deltatime);
					if (info.hasCollide) {
						// 质量大于0的时候 双方进行速度处理
						// 发生碰撞时的处理
						if(pc->mass>0&&pc2->mass>0)
							UpdateVelocity(pc, pc2, info);
						// 调用双方的碰撞处理函数
						(*it)->OnCollision(*(it2));
						(*it2)->OnCollision(*(it));
					}	
				}		
			}
		}
	}

	// 处理受力 与 速度更新
	m_force->Frame(deltatime);

	// 用来更新位置 与 方向
	for (GameObjectClass* gameobject : GameObjectListClass::GetSingleton()->m_GameObjects) {
		if (gameobject->active && gameobject->m_PhysicsComponent) {

			PhysicsComponentClass* pc = gameobject->m_PhysicsComponent;
			pc->m_position += deltatime*pc->m_velocity;

			// rotation是0的话 进行单位化
			if (D3DXQuaternionLength(&pc->m_rotation) == 0) {
				D3DXQuaternionIdentity(&pc->m_rotation);
			}

			// 通过旋转速度 更新方向
			pc->m_orientation *= deltatime*pc->m_rotation;
			// 单位化
			D3DXQuaternionNormalize(&pc->m_orientation, &pc->m_orientation);
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

// 判断碰撞 类型 进行速度更新
void PhysicsClass::UpdateVelocity(PhysicsComponentClass *pc1, PhysicsComponentClass *pc2, CollisionDetectorClass::CollisionInfo info)
{
	if (pc1->m_collider->m_type == ColliderType::SPHRER && pc2->m_collider->m_type == ColliderType::SPHRER) {
		UpdateSphereVelocity(pc1, pc2, info);
	}else if (pc1->m_collider->m_type == ColliderType::SPHRER && pc2->m_collider->m_type == ColliderType::AABB) {
		UpdateSphereAabbVelocity(pc1, pc2, info);
	}else if (pc2->m_collider->m_type == ColliderType::SPHRER && pc1->m_collider->m_type == ColliderType::AABB) {
		UpdateSphereAabbVelocity(pc2, pc1, info);
	}
}

void PhysicsClass::UpdateSphereVelocity(PhysicsComponentClass *pc1, PhysicsComponentClass *pc2, CollisionDetectorClass::CollisionInfo info)
{
	// 调整相交位置 分离相交情况
	// 更新到碰撞的位置
	pc1->m_position += info.collidetime * pc1->m_velocity;
	pc2->m_position += info.collidetime * pc2->m_velocity;

	// 计算碰撞法线
	D3DXVECTOR3 normal = pc1->m_position - pc2->m_position;
	D3DXVec3Normalize(&normal, &normal);
	// 计算冲量
	D3DXVECTOR3 impulsePerMass = normal*info.impluse;

	// 利用冲量更新速度
	pc1->m_velocity += impulsePerMass / pc1->mass;
	pc2->m_velocity -= impulsePerMass / pc2->mass;
}

void PhysicsClass::UpdateSphereAabbVelocity(PhysicsComponentClass *sphere, PhysicsComponentClass *aabb, CollisionDetectorClass::CollisionInfo info)
{
	// 调整相交位置 分离相交情况
	// 更新到碰撞的位置
	sphere->m_position += info.collidetime * sphere->m_velocity;
	// aabb不更新位置

	// 在法线方向上的投影
	float project = D3DXVec3Dot(&sphere->m_velocity, &info.normal);

	// 减去两倍的normal方向上的分量
	sphere->m_velocity -= 2 * project* info.normal;
}