#include "ModelClass.h"



ModelClass::ModelClass()
{
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_model = 0;
}

ModelClass::ModelClass(const ModelClass &)
{
}


ModelClass::~ModelClass()
{
}

// 用一个dds纹理
bool ModelClass::Initialize(ID3D11Device *device, char* modelFilename)
{
	bool result;

	// 加载模型数据
	result = LoadModel(modelFilename);
	if (!result) {
		return false;
	}

	// 初始化保存三角形几何的顶点和索引缓冲器
	result = InitializeBuffers(device);
	if (!result) {
		return false;
	}

	return true;
}

void ModelClass::Shutdown()
{
	// 释放顶点和索引缓冲区
	ShutdownBuffers();
	ReleaseModel();
	return;
}

void ModelClass::Render(ID3D11DeviceContext *deviceContext)
{
	// 将顶点和索引缓冲区放在图形管道上
	// 准备绘图
	RenderBuffers(deviceContext);
	return;
}

int ModelClass::GetIndexCount()
{
	return m_indexCount;
}

// 加载一个ui model
bool ModelClass::InitializeUi(ID3D11Device* device, int screenWidth, int screenHeight, int bitmapWidth, int bitmapHeight)
{
	bool result;

	// 加载模型数据
	result = LoadUiModel(screenWidth, screenHeight, bitmapWidth, bitmapHeight);
	if (!result) {
		return false;
	}

	// 初始化保存三角形几何的顶点和索引缓冲器
	result = InitializeBuffers(device);
	if (!result) {
		return false;
	}

	return true;


}


bool ModelClass::InitializeBuffers(ID3D11Device *device)
{
	VertexType *vertices;
	unsigned long *indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;

	HRESULT result;

	vertices = new VertexType[m_vertexCount];

	if (!vertices) {
		return false;
	}

	indices = new unsigned long[m_indexCount];
	if (!indices) {
		return false;
	}

	// 位置与颜色
	for (int i = 0; i < m_vertexCount; i++) {
		vertices[i].position = D3DXVECTOR3(m_model[i].x, m_model[i].y, m_model[i].z);
		vertices[i].texture = D3DXVECTOR2(m_model[i].tu, m_model[i].tv);
		vertices[i].normal = D3DXVECTOR3(m_model[i].nx, m_model[i].ny, m_model[i].nz);

		indices[i] = i;
	}

	// 设置静态顶点缓冲区的参数
	// Buffer_Desc
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	// 数据长度
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * m_vertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;
    
	// Subsource_data
	// 为子资源提供指向数据的指针
	// 指向顶点数据
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// 创建顶点缓冲区
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &m_vertexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	// 设置静态索引的参数
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * m_indexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// 设置子资源
	// 指向索引数据
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// 创建索引缓冲区
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &m_indexBuffer);
	if (FAILED(result))
	{
		return false;
	}

	delete[] vertices;
	vertices = 0;

	delete[] indices;
	indices = 0;

	return true;
}

void ModelClass::ShutdownBuffers()
{
	if (m_indexBuffer)
	{
		m_indexBuffer->Release();
		m_indexBuffer = 0;
	}

	if (m_vertexBuffer)
	{
		m_vertexBuffer->Release();
		m_vertexBuffer = 0;
	}

	return;
}

void ModelClass::RenderBuffers(ID3D11DeviceContext *deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	// 设置顶点缓冲区的 步长&偏移量
	stride = sizeof(VertexType);
	offset = 0;

	// 激活缓冲区
	deviceContext->IASetVertexBuffers(0, 1, &m_vertexBuffer, &stride, &offset);
	deviceContext->IASetIndexBuffer(m_indexBuffer, DXGI_FORMAT_R32_UINT, 0);
	// 设置渲染的基本图元类型
	// 指定图元的拓扑结构
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	return;
}


bool ModelClass::LoadModel(char *filename)
{
	ifstream fin;
	char input;
	fin.open(filename);

	if (fin.fail()) {
		return false;
	}

	fin.get(input);
	while (input != ':') {
		fin.get(input);
	}

	// 读入顶点数
	fin >> m_vertexCount;

	// test
	m_vertexCount = m_vertexCount;

	m_indexCount = m_vertexCount;


	m_model = new ModelType[m_vertexCount];
	if (!m_model) {
		return false;
	}

	// 读取数据的开头
	fin.get(input);
	while (input != ':') {
		fin.get(input);
	}
	fin.get(input);
	fin.get(input);

	// 输入顶点数据
	for (int i = 0; i < m_vertexCount; i++) {
		fin >> m_model[i].x >> m_model[i].y >> m_model[i].z;
		fin >> m_model[i].tu >> m_model[i].tv;
		m_model[i].tu = 1 - m_model[i].tu;
		//m_model[i].tv = 1 - m_model[i].tv;
		fin >> m_model[i].nx >> m_model[i].ny >> m_model[i].nz;
	}

	fin.close();

	return true;
}

void ModelClass::ReleaseModel()
{
	if (m_model) {
		delete[] m_model;
		m_model = 0;
	}
	return;
}

bool ModelClass::LoadUiModel(int screenWidth, int screenHeight, int bitmapWidth, int bitmapHeight)
{
	float left, right, top, bottom;
	VertexType* vertices;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType* verticesPtr;
	HRESULT result;


	float positionX = 0;
	float positionY = 0;

	// 顶点数量为6
	m_vertexCount = 6;

	m_indexCount = m_vertexCount;

	// 计算顶点坐标
	left = (float)((screenWidth / 2) * -1) + (float)positionX;

	right = left + (float)bitmapWidth;

	top = (float)(screenHeight / 2) - (float)positionY;

	bottom = top - (float)bitmapHeight;

	// 更新顶点buffer
	m_model = new ModelType[m_vertexCount];
	if (!m_model)
	{
		return false;
	}

	// 第一个三角
	m_model[0].x = left;
	m_model[0].y = top;
	m_model[0].z = 0.0f;
	m_model[0].tu = 0.0f;
	m_model[0].tv = 0.0f;

	// Bottom right.
	m_model[1].x = right;
	m_model[1].y = bottom;
	m_model[1].z = 0.0f;
	m_model[1].tu = 1.0f;
	m_model[1].tv = 1.0f;

	// Bottom left.
	m_model[2].x = left;
	m_model[2].y = bottom;
	m_model[2].z = 0.0f;
	m_model[2].tu = 0.0f;
	m_model[2].tv = 1.0f;

	// 第二个三角
	// Top left.
	m_model[3].x = left;
	m_model[3].y = top;
	m_model[3].z = 0.0f;
	m_model[3].tu = 0.0f;
	m_model[3].tv = 0.0f;
	
	// Top right
	m_model[4].x = right;
	m_model[4].y = top;
	m_model[4].z = 0.0f;
	m_model[4].tu = 1.0f;
	m_model[4].tv = 0.0f;

	// Bottom right.
	m_model[5].x = right;
	m_model[5].y = bottom;
	m_model[5].z = 0.0f;
	m_model[5].tu = 1.0f;
	m_model[5].tv = 1.0f;
}
