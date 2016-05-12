#include "CoreEngine.h"
#include "Display.h"
#include "Input.h"

CoreEngine::CoreEngine(int width, int height, int frameRate)
{
	_isRunning = false;
	_width = width;
	_height = height;
	_frameTime = 1.0 / frameRate;
}

void CoreEngine::CreateWindow(const char* title)
{
	_display.Create(title, _width, _height, false);
}

void CoreEngine::Start()
{
	if (_isRunning)
	{
		return;
	}

	Run();
}

void CoreEngine::Stop()
{
	if (!_isRunning)
	{
		return;
	}

	_isRunning = false;
}

void CoreEngine::Run()
{
	_isRunning = true;

	unsigned int frames = 0;
	unsigned int frameCounter = 0;

	double lastTime = Time::GetTime();
	double unprocessedTime = 0;

	while (_isRunning)
	{
		bool render = false;

		double startTime = Time::GetTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime;
		frameCounter += passedTime;

		while (unprocessedTime > _frameTime)
		{
			render = true;
			unprocessedTime -= _frameTime;

			if (_display.IsCloseRequested())
			{
				Stop();
			}
			Input::Update();

			_game.Input();
			_game.Update();

			if (frameCounter >= 1.0)
			{
				std::cout << frames << std::endl;
				frames = 0;
				frameCounter = 0;
			}
		}
		if (render)
		{
			_game.Render();
			Render();
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
}

void CoreEngine::Render()
{
	_display.Render();
}

CoreEngine::~CoreEngine()
{
	Display::Dispose();
}
