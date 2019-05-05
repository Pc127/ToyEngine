#pragma once
#include <d3d11.h>
#include <d3dx10math.h>
#include <fstream>
using namespace std;
#include "textureclass.h"
class FontClass
{
private:
	struct FontType
	{
		float left, right;
		int size;
	};

	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:
	FontClass();
	FontClass(const FontClass&);
	~FontClass();

	bool initialize(ID3D11Device*, char*, WCHAR*);
	void shutdown();

	ID3D11ShaderResourceView* getTexture();

	void buildVertexArray(void*, char*, float, float);

private:
	bool loadFontData(char*);
	void releaseFontData();
	bool loadTexture(ID3D11Device*, WCHAR*);
	void releaseTexture();

private:
	FontType* mFont;
	TextureClass* mTexture;
};