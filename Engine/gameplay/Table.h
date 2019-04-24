#pragma once
#include "GameObjectClass.h"

class Table:public GameObjectClass
{
public:
	Table();
	~Table();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	//继承了父类的shutdown 所以不用考虑组件的析构
};

