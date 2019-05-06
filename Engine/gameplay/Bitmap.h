#pragma once
#include <d3d11.h>
#include <d3dx10math.h>
#include"GameObjectClass.h"
class Bitmap:public GameObjectClass
{
public:
	Bitmap(WCHAR* texture);
	~Bitmap();
	virtual bool Initialize() override;
	virtual bool Frame() override;
	

private:
	
	WCHAR* m_Texture;
};
