#include "CoreEngine.h"
#include "Display.h"

CoreEngine::CoreEngine(int width, int height)
{
	_isRunning = false;
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

	while (_isRunning)
	{
		if (_display.IsClosed())
		{
			Stop();
		}

		Render();
	}
}

void CoreEngine::Render()
{
	_display.SwapBuffers();
}

CoreEngine::~CoreEngine()
{
}
