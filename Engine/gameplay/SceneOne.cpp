#include "SceneOne.h"



SceneOne::SceneOne()
{
}


SceneOne::~SceneOne()
{
}

bool SceneOne::Initialize()
{
	
	//1
	auto ball04 = new Ball(L"../Engine/data/Ball4.dds");
	m_SceneObject.push_back(ball04);
	m_SceneObject[0]->Initialize();
	m_SceneObject[0]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 40);
	

	//2
	auto ball14 = new Ball(L"../Engine/data/Ball14.dds");
	m_SceneObject.push_back(ball14);
	m_SceneObject[1]->Initialize();
	m_SceneObject[1]->m_PhysicsComponent->m_position = D3DXVECTOR3(2.5, 0, 40);

	//3
	auto ball03 = new Ball(L"../Engine/data/Ball3.dds");
	m_SceneObject.push_back(ball03);
	m_SceneObject[2]->Initialize();
	m_SceneObject[2]->m_PhysicsComponent->m_position = D3DXVECTOR3(5, 0, 40);

	//4
	auto ball15 = new Ball(L"../Engine/data/Ball15.dds");
	m_SceneObject.push_back(ball15);
	m_SceneObject[3]->Initialize();
	m_SceneObject[3]->m_PhysicsComponent->m_position = D3DXVECTOR3(-2.5, 0, 40);

	//5
	auto ball05 = new Ball(L"../Engine/data/Ball5.dds");
	m_SceneObject.push_back(ball05);
	m_SceneObject[4]->Initialize();
	m_SceneObject[4]->m_PhysicsComponent->m_position = D3DXVECTOR3(-5, 0, 40);

	//6
	auto ball02 = new Ball(L"../Engine/data/Ball2.dds");
	m_SceneObject.push_back(ball02);
	m_SceneObject[5]->Initialize();
	m_SceneObject[5]->m_PhysicsComponent->m_position = D3DXVECTOR3(1.25, 0, 37.5);

	//7
	auto ball12 = new Ball(L"../Engine/data/Ball12.dds");
	m_SceneObject.push_back(ball12);
	m_SceneObject[6]->Initialize();
	m_SceneObject[6]->m_PhysicsComponent->m_position = D3DXVECTOR3(3.75, 0, 37.5);

	//8
	auto ball11 = new Ball(L"../Engine/data/Ball11.dds");
	m_SceneObject.push_back(ball11);
	m_SceneObject[7]->Initialize();
	m_SceneObject[7]->m_PhysicsComponent->m_position = D3DXVECTOR3(-1.25, 0, 37.5);

	//9
	auto ball13 = new Ball(L"../Engine/data/Ball13.dds");
	m_SceneObject.push_back(ball13);
	m_SceneObject[8]->Initialize();
	m_SceneObject[8]->m_PhysicsComponent->m_position = D3DXVECTOR3(-3.75, 0, 37.5);


	//10
	auto ball08 = new Ball(L"../Engine/data/Ball8.dds");
	m_SceneObject.push_back(ball08);
	m_SceneObject[9]->Initialize();
	ball08->active = true;
	m_SceneObject[9]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 35);

	//11
	auto ball10 = new Ball(L"../Engine/data/Ball10.dds");
	m_SceneObject.push_back(ball10);
	m_SceneObject[10]->Initialize();
	m_SceneObject[10]->m_PhysicsComponent->m_position = D3DXVECTOR3(2.5, 0, 35);

	//12
	auto ball06 = new Ball(L"../Engine/data/Ball6.dds");
	m_SceneObject.push_back(ball06);
	m_SceneObject[11]->Initialize();
	m_SceneObject[11]->m_PhysicsComponent->m_position = D3DXVECTOR3(-2.5, 0, 35);

	//13
	auto ball07 = new Ball(L"../Engine/data/Ball7.dds");
	m_SceneObject.push_back(ball07);
	m_SceneObject[12]->Initialize();
	m_SceneObject[12]->m_PhysicsComponent->m_position = D3DXVECTOR3(1.25, 0, 32.5);

	//14
	auto ball09 = new Ball(L"../Engine/data/Ball9.dds");
	m_SceneObject.push_back(ball09);
	m_SceneObject[13]->Initialize();
	m_SceneObject[13]->m_PhysicsComponent->m_position = D3DXVECTOR3(-1.25, 0, 32.5);

	//15
	auto ball01 = new Ball(L"../Engine/data/Ball1.dds");
	m_SceneObject.push_back(ball01);
	m_SceneObject[14]->Initialize();
	m_SceneObject[14]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 30);

	// 白球
	auto whiteBall = new Ball(L"../Engine/data/Ball16.dds");
	m_SceneObject.push_back(whiteBall);
	m_SceneObject[15]->Initialize();
	m_SceneObject[15]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 0);
	m_SceneObject[15]->m_PhysicsComponent->m_velocity = D3DXVECTOR3(0, 0, 0);

	// 桌子
	m_SceneObject.push_back(new Table);
	m_SceneObject[16]->Initialize();

	// 桌面
	m_SceneObject.push_back(new Desktop);
	m_SceneObject[17]->Initialize();

	// 碰撞边框
	// 左手侧
	m_SceneObject.push_back(new Edge(D3DXVECTOR3(-26, -10, 53.2), D3DXVECTOR3(26, 10, 56.1)));
	m_SceneObject[18]->Initialize();

	// 右手侧
	m_SceneObject.push_back(new Edge(D3DXVECTOR3(-26, -10, -56.1), D3DXVECTOR3(26, 10, -53.2)));
	m_SceneObject[19]->Initialize();

	// 左上侧
	m_SceneObject.push_back(new Edge(D3DXVECTOR3(28.18, -10, 2.39), D3DXVECTOR3(31.18, 10, 52.05)));
	m_SceneObject[20]->Initialize();

	// 右上侧
	m_SceneObject.push_back(new Edge(D3DXVECTOR3(28.18, -10, -52.05), D3DXVECTOR3(31.18, 10, -2.39)));
	m_SceneObject[21]->Initialize();

	// 右下侧
	m_SceneObject.push_back(new Edge(D3DXVECTOR3(-31.18, -10, -52.05), D3DXVECTOR3(-28.18, 10, -2.39)));
	m_SceneObject[22]->Initialize();

	// 左下侧
	m_SceneObject.push_back(new Edge(D3DXVECTOR3(-31.18, -10, 2.39), D3DXVECTOR3(-28.18, 10, 52.05)));
	m_SceneObject[23]->Initialize();

	// 台球杆
	m_SceneObject.push_back(new Stick(m_SceneObject[15]));
	m_SceneObject[24]->Initialize();

	// 辅助线
	m_SceneObject.push_back(new Subline(m_SceneObject[15]));
	m_SceneObject[25]->Initialize();


	// 球洞中上
	m_SceneObject.push_back(new Hole);
	m_SceneObject[26]->Initialize();
	m_SceneObject[26]->m_PhysicsComponent->m_position = D3DXVECTOR3(30,0,0);

	// 球洞左上
	m_SceneObject.push_back(new Hole);
	m_SceneObject[27]->Initialize();
	m_SceneObject[27]->m_PhysicsComponent->m_position = D3DXVECTOR3(29, 0, 54);

	// 球洞右上
	m_SceneObject.push_back(new Hole);
	m_SceneObject[28]->Initialize();
	m_SceneObject[28]->m_PhysicsComponent->m_position = D3DXVECTOR3(29, 0, -54);

	// 球洞左下
	m_SceneObject.push_back(new Hole);
	m_SceneObject[29]->Initialize();
	m_SceneObject[29]->m_PhysicsComponent->m_position = D3DXVECTOR3(-29, 0, 54);

	// 球洞右下
	m_SceneObject.push_back(new Hole);
	m_SceneObject[30]->Initialize();
	m_SceneObject[30]->m_PhysicsComponent->m_position = D3DXVECTOR3(-29, 0, -54);

	// 球洞中下
	m_SceneObject.push_back(new Hole);
	m_SceneObject[31]->Initialize();
	m_SceneObject[31]->m_PhysicsComponent->m_position = D3DXVECTOR3(-30, 0, 0);

	// 台球杆的监视器
	auto monitor = new Monitor(m_SceneObject[24], m_SceneObject[25]);
	m_SceneObject.push_back(monitor);
	m_SceneObject[32]->Initialize();

	// 玩家标识
	auto player1 = new Ui("player1", L"../Engine/data/Player1.dds", 100, 100);
	m_SceneObject.push_back(player1);
	m_SceneObject[33]->Initialize();
	m_SceneObject[33]->m_PhysicsComponent->m_position = D3DXVECTOR3(0, -50, 0);

	auto player2 = new Ui("player2", L"../Engine/data/Player2.dds", 100, 100);
	m_SceneObject.push_back(player2);
	m_SceneObject[34]->Initialize();
	m_SceneObject[34]->m_PhysicsComponent->m_position = D3DXVECTOR3(200, -50, 0);


	// 胜利标识
	auto win = new Ui("win", L"../Engine/data/Win.dds", 100, 100);
	m_SceneObject.push_back(win);
	win->Initialize();
	win->m_PhysicsComponent->m_position = D3DXVECTOR3(200, -200, 0);

	// 大小球队列
	auto bigBalls = new BallDetector({ball09, ball10, ball11, ball12, ball13, ball14, ball15});
	m_SceneObject.push_back(bigBalls);
	bigBalls->Initialize();

	auto smallBalls = new BallDetector({ball01, ball02, ball03, ball04, ball05, ball06, ball07});
	m_SceneObject.push_back(smallBalls);
	smallBalls->Initialize();

	// 规则
	auto rule = new Rule(bigBalls, smallBalls, whiteBall, ball08, player1, player2, win, monitor);
	m_SceneObject.push_back(rule);
	rule->Initialize();

	return true;
}

bool SceneOne::Frame()
{
	return false;
}
