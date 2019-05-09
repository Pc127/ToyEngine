#include "BitmapMapClass.h"



BitmapMapClass::BitmapMapClass()
{

}

BitmapMapClass::~BitmapMapClass()
{
}

bool BitmapMapClass::Initialize(ID3D11Device *device)
{
	m_device = device;

	return true;
}

BitmapMapClass * BitmapMapClass::GetSingleton()
{
	static BitmapMapClass instance;
	return &instance;
}

void BitmapMapClass::Shutdown()
{
	for_each(m_bitmapMap.begin(), m_bitmapMap.end(), [](pair<bitmapStruct*, BitmapClass*> it) {it.second->Shutdown(); delete it.second; });
}

BitmapClass * BitmapMapClass::GetBitmap(bitmapStruct* bitmapname, WCHAR* texturename)
{
	if (m_bitmapMap.count(bitmapname) == 0)
		SetBitmap(bitmapname,texturename);
	return m_bitmapMap[bitmapname];
}

bool BitmapMapClass::SetBitmap(bitmapStruct* bitmapname,WCHAR* texturename)
{
	m_bitmapMap[bitmapname] = new BitmapClass;

	bool result;
	result = m_bitmapMap[bitmapname]->Initialize(m_device, bitmapname->ScreenWidth,bitmapname->ScreenHeight, texturename,bitmapname->bitmapWidth,bitmapname->bitmapHeight);
	if (!result) {
		return false;
	}

	return true;
}
