#pragma once
#include <D3DX10math.h>

class PhysicsClass
{
public:
	PhysicsClass();
	~PhysicsClass();
	// 初始化游戏obj 暂时硬编码
	// 不指定参数
	bool Initialize();
	void Shutdown();
	// 计算更新物体位置
	bool Frame();
	// 获得指定索引的世界矩阵
	void GetWorldMatrix(D3DXMATRIX&, unsigned int);
	void GetWorldMatrixUnrotate(D3DXMATRIX&, unsigned int);

	unsigned int GetModelIndex(unsigned int);
	unsigned int GetTextureIndex(unsigned int);
	int GetObjCount();

	// 进行碰撞检测
	bool CollisionDetect();
private:
	unsigned int m_objNum;
};