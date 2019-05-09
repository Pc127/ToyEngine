#pragma once
#include "GameObjectClass.h"
#include "Bitmapclass.h"
#include "BitmapStruct.h"
class Title:public GameObjectClass
{
public:
	Title(WCHAR* texture);
	~Title();
	virtual bool Initialize() override;;
	virtual bool Frame() override;;
	//继承了父类的shutdown 所以不用考虑组件的析构
private:
	WCHAR* m_Texture;
	bitmapStruct* m_Bitmapname;
};

