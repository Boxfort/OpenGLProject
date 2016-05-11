#ifndef COREENGINE_H
#define COREENGINE_H

#include "Display.h"
#include "Time.h"
#include <thread>
#include <chrono>
#include <iostream>

class CoreEngine
{
public:
	CoreEngine(int width, int height, int frameRate);

	void CreateWindow(const char* title, int width, int height, bool fullscreen);
	void Start();
	void Stop();

	~CoreEngine();
protected:
private:
	bool _isRunning;
	int _frameRate;
	double _frameTime;
	Display _display;
	
	void Run();
	void Render();
};

#endif
