#include "ScenePlay.h"



ScenePlay::ScenePlay()
{
}


ScenePlay::~ScenePlay()
{
}

bool ScenePlay::Initialize()
{
	//1
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball4.dds"));
	m_SceneObject[0]->Initialize();
	m_SceneObject[0]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 40);
	

	//2 
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball14.dds"));
	m_SceneObject[1]->Initialize();
	m_SceneObject[1]->m_PhysicsComponent->m_position = D3DXVECTOR3(2.5, 0, 40);

	//3
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball3.dds"));
	m_SceneObject[2]->Initialize();
	m_SceneObject[2]->m_PhysicsComponent->m_position = D3DXVECTOR3(5, 0, 40);

	//4
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball15.dds"));
	m_SceneObject[3]->Initialize();
	m_SceneObject[3]->m_PhysicsComponent->m_position = D3DXVECTOR3(-2.5, 0, 40);

	//5
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball5.dds"));
	m_SceneObject[4]->Initialize();
	m_SceneObject[4]->m_PhysicsComponent->m_position = D3DXVECTOR3(-5, 0, 40);

	//6
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball2.dds"));
	m_SceneObject[5]->Initialize();
	m_SceneObject[5]->m_PhysicsComponent->m_position = D3DXVECTOR3(1.25, 0, 37.5);

	//7
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball12.dds"));
	m_SceneObject[6]->Initialize();
	m_SceneObject[6]->m_PhysicsComponent->m_position = D3DXVECTOR3(3.75, 0, 37.5);

	//8
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball11.dds"));
	m_SceneObject[7]->Initialize();
	m_SceneObject[7]->m_PhysicsComponent->m_position = D3DXVECTOR3(-1.25, 0, 37.5);

	//9
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball13.dds"));
	m_SceneObject[8]->Initialize();
	m_SceneObject[8]->m_PhysicsComponent->m_position = D3DXVECTOR3(-3.75, 0, 37.5);


	//10
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball8.dds"));
	m_SceneObject[9]->Initialize();
	m_SceneObject[9]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 35);

	//11
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball10.dds"));
	m_SceneObject[10]->Initialize();
	m_SceneObject[10]->m_PhysicsComponent->m_position = D3DXVECTOR3(2.5, 0, 35);

	//12
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball6.dds"));
	m_SceneObject[11]->Initialize();
	m_SceneObject[11]->m_PhysicsComponent->m_position = D3DXVECTOR3(-2.5, 0, 35);

	//13
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball7.dds"));
	m_SceneObject[12]->Initialize();
	m_SceneObject[12]->m_PhysicsComponent->m_position = D3DXVECTOR3(1.25, 0, 32.5);

	//14
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball9.dds"));
	m_SceneObject[13]->Initialize();
	m_SceneObject[13]->m_PhysicsComponent->m_position = D3DXVECTOR3(-1.25, 0, 32.5);

	//15
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball1.dds"));
	m_SceneObject[14]->Initialize();
	m_SceneObject[14]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 30);

	//16
	m_SceneObject.push_back(new Ball(L"../Engine/data/Ball16.dds"));
	m_SceneObject[15]->Initialize();
	m_SceneObject[15]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 0);
	m_SceneObject[15]->m_PhysicsComponent->m_velocity = D3DXVECTOR3(0, 0, 7);

	// 桌子
	m_SceneObject.push_back(new Table);
	m_SceneObject[16]->Initialize();

	// 桌面
	m_SceneObject.push_back(new Desktop);
	m_SceneObject[17]->Initialize();

	return true;
}

bool ScenePlay::Frame()
{
	return false;
}
