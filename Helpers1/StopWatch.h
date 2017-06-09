#pragma once
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <ctime>

class StopWatch {
	clock_t startTime;
	bool running;
	double elapsedTime;
public:
	StopWatch();
	virtual ~StopWatch();

	void Start();
	void Stop();
	void Reset();
	double Elapse() const;//this method compute the time when time since last reset
	bool isRunning() const;
};


#endif // !STOPWATCH_H
