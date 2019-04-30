#pragma once
#include <d3d11.h>
#include <D3DX10math.h>
#include "TextureClass.h"

#include <fstream>
using namespace std;

class ModelClass
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
		// 颜色改为纹理
		// D3DXVECTOR4 color;
		// 纹理坐标
		D3DXVECTOR2 texture;
		D3DXVECTOR3 normal;
	};
	// 坐标 纹理 法线
	struct ModelType {
		float x, y, z;
		float tu, tv;
		float nx, ny, nz;
	};
public:
	ModelClass();
	ModelClass(const ModelClass&);
	~ModelClass();

	bool Initialize(ID3D11Device*, char*);
	void Shutdown();
	void Render(ID3D11DeviceContext*);

	int GetIndexCount();
private:
	bool InitializeBuffers(ID3D11Device*);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext*);

	// 加载与释放 模型数据
	bool LoadModel(char*);
	void ReleaseModel();

private:
	ID3D11Buffer* m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

	ModelType* m_model;
};