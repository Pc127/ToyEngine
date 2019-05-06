#include "TextureMapClass.h"

TextureMapClass::TextureMapClass()
{
	m_device = 0;
}

TextureMapClass::~TextureMapClass()
{
}


TextureMapClass * TextureMapClass::GetSingleton()
{
	// 设置单例模式
	static TextureMapClass instance;
	return &instance;
}

bool TextureMapClass::Initialize(ID3D11Device *device)
{
	m_device = device;
	return true;
}

void TextureMapClass::Shutdown()
{
	// 释放所有的texture
	for_each(m_textureMap.begin(), m_textureMap.end(), [](std::pair<WCHAR *, ID3D11ShaderResourceView*> it) {it.second->Release(); });
	return;
}

bool TextureMapClass::SetTexture(WCHAR *filename)
{
	HRESULT result;

	m_textureMap[filename] = 0;

	result = D3DX11CreateShaderResourceViewFromFile(m_device, filename, NULL, NULL, &m_textureMap[filename], NULL);
	if (FAILED(result)) {
		return false;
	}
	return true;
}

ID3D11ShaderResourceView * TextureMapClass::GetTexture(WCHAR* filename)
{
	if (m_textureMap.count(filename) == 0)
		SetTexture(filename);
	return m_textureMap[filename];
}
