#pragma once
#include "GameObjectClass.h"

class Ui:public GameObjectClass
{
public:
	Ui(char* uuid, WCHAR* texture, int width, int height);
	~Ui();
	virtual bool Initialize() override;;
	virtual bool Frame() override;;
	//继承了父类的shutdown 所以不用考虑组件的析构
private:
	char* uuid;
	WCHAR* m_Texture;
	int width;
	int height;
};

