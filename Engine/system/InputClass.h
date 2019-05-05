#pragma once
// 指定api版本
#define DIRECTINPUT_VERSION 0x0800

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>

class InputClass
{
public:
	InputClass();
	InputClass(const InputClass&);
	~InputClass();

	bool Initialize(HINSTANCE, HWND, int, int);
	void Shutdown();
	bool Frame();

	// 判断左右方向的输入
	bool IsLeftArrowPressed();
	bool IsRightArrowPressed();
	bool IsLeftPressed();
	bool IsRightPressed();
	bool IsEscapePressed();

	// 获取鼠标位置
	void GetMouseLocation(int&, int&);

	// 检测鼠标右键的输入
	bool IsLeftMouseButtonDown();

private:
	bool ReadKeyboard();
	bool ReadMouse();
	void ProcessInput();

private:
	// 直接输入
	// 键盘与鼠标
	IDirectInput8* m_directInput;
	IDirectInputDevice8* m_keyboard;
	IDirectInputDevice8* m_mouse;

	// 键盘状态 由int变为char
	unsigned char m_keyboardState[256];
	// 鼠标状态
	DIMOUSESTATE m_mouseState;

	int m_screenWidth, m_screenHeight;
	int m_mouseX, m_mouseY;
};
