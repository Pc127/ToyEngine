#pragma once
#include "GraphicsClass.h"
#include "InputClass.h"
#include "TimerClass.h"
#include "PhysicsClass.h"
#include <windows.h>
// 排除一些较少使用的win32API
#ifndef  _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_
#endif // ! _SYSTEMCLASS_H_

// gameplay
#include "SceneOne.h"

#define WIN32_LEAN_AND_MEAN


class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass &other) = default;
	~SystemClass() = default;
	bool Initialize();
	void Run();
	void Shutdown();
	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
public:
	
	
private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();
private:
	// 此处进行了修改，原为LPCWSTR指向w_char
	// 已改回
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;
	TimerClass* m_Timer;
	PhysicsClass* m_Physics;

	// 场景
	GameSceneClass* m_GameScene;
};


static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static SystemClass *ApplicationHandle = 0;