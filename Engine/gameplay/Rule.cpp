#include "Rule.h"


Rule::Rule(BallDetector * big, BallDetector * smallBalls, GameObjectClass * white, GameObjectClass * black, 
	GameObjectClass * player1, GameObjectClass * player2, GameObjectClass * win, Monitor* monitor)
{
	this->bigBalls = big;
	this->smallBalls = smallBalls;
	this->whiteBall = white;
	this->blackBall = black;
	this->player1 = player1;
	this->player2 = player2;
	this->win = win;
	this->monitor = monitor;
}

Rule::~Rule()
{
}


bool Rule::Initialize()
{
	// 注册
	Register();

	bool result;

	this->active = true;

	this->player1->active = true;
	this->player2->active = false;
	this->win->active = false;
	this->whichPlayer = 1;

	return true;
}

// 更新旋转速度
bool Rule::Frame()
{
	// 击球开始 到 击球停止
	static bool pull = false;
	
	// 更新击球状态
	if (!pull&&monitor->state == false) {
		pull = true;
	}

	if (pull == true) {
		// 小球全部禁止
		if (monitor->state == true) {
			// 回复击球状态
			// 进行判定
			pull = false;
		}
		else {
			// 等待判断时刻到来
			return true;
		}
	}
	else {
		// 尚未击球
		return true;
	}

	// 判定状态
	// 黑球进了
	if (blackBall->active == false) {
		if (!initialBallerOwnner) {
			ChangePlayer();
			Winner();
			return true;
		}

		// 检查是否获胜
		// 当前的玩家是 大球
		if (whichPlayer == BigBallOwnner) {
			if (bigBalls->IsBallAllIn())
			{
				Winner();
				return true;
			}

		}
		else {
			if (smallBalls->IsBallAllIn()) {
				Winner();
				return true;
			}
		}

		// 没有获胜的话 默认情况 还是对方赢了
		ChangePlayer();
		Winner();
		return true;
	}

	// 白球进了
	if (whiteBall->active == false) {
		ChangePlayer();
		// 重新置球
		whiteBall->m_PhysicsComponent->m_position = D3DXVECTOR3(0, 0, 0);
		whiteBall->m_PhysicsComponent->m_velocity = D3DXVECTOR3(0, 0, 0);
		whiteBall->active = true;
		return true;
	}

	// 大球进了
	if (bigBalls->IsOneBallIn()) {
		// 还没分配球的归属
		if (!initialBallerOwnner) {
			// 分配归属
			BigBallOwnner = whichPlayer;
			initialBallerOwnner = true;
			// 还是该玩家继续击球
			return true;
		}
		else {
			// 当前玩家就是大球分配者
			if (BigBallOwnner == whichPlayer) {
				// 继续击球
				return true;
			}
			else {
				// 交换玩家击球
				ChangePlayer();
				return true;
			}
		}
	}

	// 小球进了
	if (smallBalls->IsOneBallIn()) {
		// 还没分配球的归属
		if (!initialBallerOwnner) {
			// 分配归属
			BigBallOwnner = 3 - whichPlayer;
			initialBallerOwnner = true;
			// 还是该玩家继续击球
			return true;
		}
		else {
			// 当前玩家就是小球分配者
			if (BigBallOwnner != whichPlayer) {
				// 继续击球
				return true;
			}
			else {
				// 交换玩家击球
				ChangePlayer();
				return true;
			}
		}
	}

	// 大小球都没进 交换玩家
	ChangePlayer();

}

void Rule::ChangePlayer()
{
	player1->active = !player1->active;
	player2->active = !player2->active;
	// 交替序号
	whichPlayer = 3 - whichPlayer;
}

void Rule::Winner()
{
	if (whichPlayer == 1) {
		win->active = true;
		// 下移 50 放置标志
		win->m_PhysicsComponent->m_position = player1->m_PhysicsComponent->m_position - D3DXVECTOR3(0, -50, 0);
	}
	else {
		win->active = true;
		// 下移 50 放置标志
		win->m_PhysicsComponent->m_position = player2->m_PhysicsComponent->m_position - D3DXVECTOR3(0, -50, 0);
	}

	// 结束游戏
	EndGame();
}

void Rule::EndGame()
{
	monitor->stick->active = false;
	monitor->subline->active = false;
	monitor->active = false;
}