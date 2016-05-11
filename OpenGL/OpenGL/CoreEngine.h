#ifndef COREENGINE_H
#define COREENGINE_H

#include "Display.h"
#include "Time.h"
#include "Game.h"
#include <thread>
#include <chrono>
#include <iostream>

class CoreEngine
{
public:
	CoreEngine(int width, int height, int frameRate);

	void CreateWindow(const char* title);
	void Start();
	void Stop();

	~CoreEngine();
protected:
private:
	bool _isRunning;
	double _frameTime;
	Display _display;
	int _height;
	int _width;
	Game _game;
	
	void Run();
	void Render();
};

#endif
