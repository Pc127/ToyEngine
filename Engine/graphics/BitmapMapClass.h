#pragma once
#include <d3d11.h>
#include <D3DX10math.h>
#include "TextureClass.h"
#include "bitmapclass.h"
#include "BitmapStruct.h"
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

class BitmapMapClass
{
public:
	
	static BitmapMapClass* GetSingleton();

	bool Initialize(ID3D11Device*);

	void Shutdown();

	BitmapClass* GetBitmap(bitmapStruct*, WCHAR*);

	bool SetBitmap(bitmapStruct*, WCHAR*);


private:
	BitmapMapClass();
	BitmapMapClass(const BitmapMapClass&) = delete;
	~BitmapMapClass();
private:
	ID3D11Device* m_device;
	map<bitmapStruct*, BitmapClass*> m_bitmapMap;
};