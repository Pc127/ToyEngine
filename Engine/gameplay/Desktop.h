#pragma once
#include "GameObjectClass.h"

class Desktop:public GameObjectClass
{
public:
	Desktop();
	~Desktop();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
};

