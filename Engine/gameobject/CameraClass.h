#pragma once
#include <D3DX10math.h>
class CameraClass
{
public:
	// 鼠标产生的射线
	struct Ray {
		D3DXVECTOR3 origin;
		D3DXVECTOR3 direction;
	};
public:
	static CameraClass* GetSingleton();

	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	D3DXVECTOR3 GetPosition();
	D3DXVECTOR3 GetRotation();

	void Render();

	// 视图以及投影矩阵
	void GetViewMatrix(D3DXMATRIX&);
	void GetProjectionMatrix(D3DXMATRIX&);
	void SetProjectionMatrix(D3DXMATRIX&);

	// 正交投影矩阵
	void GetOrthoMatrix(D3DXMATRIX&);
	void SetOrthoMatrix(D3DXMATRIX&);

	// picking 射线
	Ray GetPickingRay(int mouseX, int mouseY, int, int);
private:
	CameraClass();
	~CameraClass();
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;

	// 保存三个矩阵
	D3DXMATRIX m_viewMatrix;
	D3DXMATRIX m_projectionMatrix;
	D3DXMATRIX m_orthoMatrix;
};

