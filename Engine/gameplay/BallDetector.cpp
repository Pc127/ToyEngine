#include "BallDetector.h"

BallDetector::BallDetector(initializer_list<GameObjectClass*> il)
{
	// 保存到数组
	for (auto ball : il) {
		m_balls.push_back(ball);
		m_state.push_back(true);
	}
}

BallDetector::~BallDetector()
{
}


bool BallDetector::Initialize()
{
	// 注册
	Register();

	bool result;

	this->active = true;

	return true;
}

bool BallDetector::Frame()
{
	return true;
}

bool BallDetector::IsBallAllIn()
{
	// 所有球都进洞了
	for (auto ball : m_balls) {
		if (ball->active == true)
			return false;
	}

	return true;
}

bool BallDetector::IsOneBallIn()
{
	for (size_t i = 0; i < m_balls.size(); i++) {
		// 更新进球状态
		if (m_balls[i]->active != m_state[i]) {
			m_state[i] = false;
			return true;
		}
	}
	return false;
}
