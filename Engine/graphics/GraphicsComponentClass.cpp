#include "GraphicsComponentClass.h"

GraphicsComponentClass::GraphicsComponentClass()
{
	m_Model = 0;
	m_Texture = 0;
}

bool GraphicsComponentClass::Initialize(char* modelname, WCHAR* texturename)
{
	m_Model = ModelMapClass::GetSingleton()->GetModel(modelname);

	m_Texture = TextureMapClass::GetSingleton()->GetTexture(texturename);

	return true;
}

bool GraphicsComponentClass::Initialize(bitmapStruct* bitmapname, WCHAR* texturename)
{
	m_Bitmap = BitmapMapClass::GetSingleton()->GetBitmap(bitmapname, texturename);
	return false;
}




void GraphicsComponentClass::Shutdown()
{
	// 不做任何操作
	// 资源 由两个map进行释放
}