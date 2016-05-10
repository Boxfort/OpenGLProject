#include "CoreEngine.h"
#include "Display.h"

CoreEngine::CoreEngine()
{
}

void CoreEngine::Start()
{
	Run();
}

void CoreEngine::Stop()
{

}

void CoreEngine::Run()
{
	while (!_display.IsClosed())
	{
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
