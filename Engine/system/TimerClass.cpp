#include "TimerClass.h"



TimerClass::TimerClass():m_secondsPreCount(0.0),m_deltaTime(-1.0),m_baseTime(0),
m_pausedTime(0),m_prevTime(0),m_currTime(0),m_stopTime(false)
{
	__int64 countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	m_secondsPreCount = 1.0 / (double)countsPerSec;
}


TimerClass::~TimerClass()
{
}

float TimerClass::TotalTime() const
{
	// 停止的时间不算在内
	if (m_stopped) {
		return (float)(((m_stopTime - m_pausedTime) - m_baseTime)*m_secondsPreCount);
	}
	else {
		return (float)(((m_currTime - m_pausedTime) - m_baseTime)*m_secondsPreCount);
	}
}

float TimerClass::DeltaTime() const
{
	return (float)m_deltaTime;
}

void TimerClass::Reset()
{
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	m_baseTime = currTime;
	m_prevTime = currTime;
	m_stopTime = currTime;
	m_stopped = false;
}

void TimerClass::Initialize()
{
	__int64 startTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&startTime);
	// 之前是否停止
	if (m_stopped) {
		// 计算停止时间
		m_pausedTime += (startTime - m_stopTime);
		m_prevTime = startTime;

		m_stopTime = 0;
		m_stopped = false;
	}
}

void TimerClass::Stop()
{
	if (!m_stopped) {
		__int64 currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		// 设定停止
		m_stopped = true;
		m_stopTime = currTime;
	}
}

void TimerClass::Frame()
{
	if (m_stopped) {
		m_deltaTime = 0.0;
		return;
	}
	// 获得本帧开始显示的时刻
	__int64 currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
	m_currTime = currTime;
	// 计算本帧与前一帧的时间差
	m_deltaTime = (m_currTime - m_prevTime)*m_secondsPreCount;
	m_prevTime = m_currTime;

	if (m_deltaTime < 0.0) {
		m_deltaTime = 0.0;
	}
}
