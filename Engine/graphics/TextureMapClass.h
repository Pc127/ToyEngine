#pragma once
#include <d3d11.h>
#include <D3DX11tex.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class TextureMapClass
{
public:
	static TextureMapClass* GetSingleton();

	// 用 device进行初始化
	bool Initialize(ID3D11Device*);

	void Shutdown();

	// 获取与设置纹理
	ID3D11ShaderResourceView* GetTexture(WCHAR *);
private:
	// 为了保证单例
	TextureMapClass();
	TextureMapClass(const TextureMapClass&) = delete;
	~TextureMapClass();

	// 设置纹理设为私有
	bool SetTexture(WCHAR *);

	// 保存一个m_device用来产生纹理
	ID3D11Device* m_device;

	// 用来保存 纹理到 字符串的映射
	map<WCHAR *, ID3D11ShaderResourceView*> m_textureMap;
};

