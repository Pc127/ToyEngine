#include "ForceRegistryClass.h"



ForceRegistryClass::ForceRegistryClass()
{
}


ForceRegistryClass::~ForceRegistryClass()
{
}

ForceRegistryClass * ForceRegistryClass::GetSingleton()
{
	static ForceRegistryClass instance;
	return &instance;
}

bool ForceRegistryClass::Initialize()
{
	return true;
}

void ForceRegistryClass::Shutdown()
{
	

}

bool ForceRegistryClass::Frame(float deltatime)
{
	CheckList();
	for (auto it = m_Force.begin(); it != m_Force.end(); it++) {
		// 遍历进行力的更新
		// 更新速度
		it->force->Frame(it->physics, deltatime);
	}
	return true;
}

bool ForceRegistryClass::AddForce(PhysicsComponentClass *pc, ForceGeneratorClass *fg)
{
	ForceRegistration fr;
	fr.force = fg;
	fr.physics = pc;
	// 加入list
	m_Force.push_back(fr);
	return true;
}

void ForceRegistryClass::CheckList()
{
	// 这里有问题
	// 如果一个力失效 我们会删除那个力 但不会删除物理组件
	for (auto it = m_Force.begin(); it != m_Force.end();) {
		if (!((it->force)->IsActive())) {
			delete it->force;
			it = m_Force.erase(it);
		}
		else {
			++it;
		}
	}
}
