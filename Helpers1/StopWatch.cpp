#include "StopWatch.h"
#include <iostream>
StopWatch::StopWatch():startTime(0), running(false), elapsedTime(0.0)
{
}

StopWatch::~StopWatch()
{
}

void StopWatch::Start()
{
	if (!running) {
		running = true;
		startTime = clock();
	}
}

void StopWatch::Stop()
{
	if (running) {
		clock_t stopTime = clock();
		running = false;
		elapsedTime = static_cast<double>(stopTime - startTime) / CLOCKS_PER_SEC;
	}
}

void StopWatch::Reset()
{
	running = false;
	elapsedTime = 0.0;
}

double StopWatch::Elapse() const
{
	if (running) {
		clock_t currTime = clock();
		return elapsedTime + static_cast<double>(currTime - startTime) / CLOCKS_PER_SEC;
	} else{
		return elapsedTime;
	}
	
}

bool StopWatch::isRunning() const
{
	return running;
}
