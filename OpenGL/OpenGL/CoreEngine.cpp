#include "CoreEngine.h"
#include "Display.h"

CoreEngine::CoreEngine(int width, int height, int frameRate)
{
	_isRunning = false;
	_frameRate = frameRate;
}

void CoreEngine::CreateWindow(const char* title, int width, int height, bool fullscreen)
{
	_display.Create(title, width, height, fullscreen);
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

	_frameTime = 1.0 / _frameRate;

	double lastTime = Time::GetTime();
	double unprocessedTime = 0;

	while (_isRunning)
	{
		bool render = false;

		double startTime = Time::GetTime();
		double passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime / Time::SECOND;
		frameCounter += passedTime;

		while (unprocessedTime > _frameTime)
		{
			render = true;
			unprocessedTime -= _frameTime;

			if (_display.IsClosed())
			{
				Stop();
			}
			//TODO: _INPUT::UPDATE();

			_game.Input();
			_game.Update();

			if (frameCounter >= Time::SECOND)
			{
				std::cout << frames << std::endl;
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
	_display.SwapBuffers();
}

CoreEngine::~CoreEngine()
{
}
