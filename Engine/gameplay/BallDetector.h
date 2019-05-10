#pragma once
#include "GameObjectClass.h"
#include "FrictionForceClass.h"
#include "ForceRegistryClass.h"
#include <vector>
#include <initializer_list>

using namespace std;

class BallDetector:public GameObjectClass
{
public:
	BallDetector(initializer_list<GameObjectClass*> il);
	~BallDetector();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
	bool IsBallAllIn();
	bool IsOneBallIn();
private:
	vector<GameObjectClass*> m_balls;
	vector<bool> m_state;
};

