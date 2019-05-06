#pragma once
#include <Windows.h>

class TimerClass
{
public:
	TimerClass();
	~TimerClass();

	float TotalTime() const;
	float DeltaTime() const;

	void Reset();
	void Initialize();
	void Stop();
	void Frame();
private:
	double m_secondsPreCount;
	double m_deltaTime;

	// 起始时间
	__int64 m_baseTime;
	// 暂停时常
	__int64 m_pausedTime;
	// 停止的时刻
	__int64 m_stopTime;
	// 上一帧的时刻
	__int64 m_prevTime;
	__int64 m_currTime;

	bool m_stopped;
};