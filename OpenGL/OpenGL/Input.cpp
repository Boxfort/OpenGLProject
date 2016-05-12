#include "Input.h"
#include <SDL2/SDL.h>
#include "sdl_backend.h"

const static int NUM_KEYS = 512;
const static int NUM_MOUSEBUTTONS = 256;

static SDL_Event e;

static int mouseX = 0;
static int mouseY = 0;

static bool _inputs[NUM_KEYS];
static bool _downKeys[NUM_KEYS];
static bool _upKeys[NUM_KEYS];

static bool mouseInput[NUM_MOUSEBUTTONS];
static bool downMouse[NUM_MOUSEBUTTONS];
static bool upMouse[NUM_MOUSEBUTTONS];

Input::Input()
{
}

void Input::Update()
{
	for (int i = 0; i < NUM_MOUSEBUTTONS; i++)
	{
		downMouse[i] = false;
		upMouse[i] = false;
	}

	for (int i = 0; i < NUM_KEYS; i++)
	{
		_downKeys[i] = false;
		_upKeys[i] = false;
	}

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
		{
			//TODO: SDL BACKEND REFACTOR
		}
		if (e.type == SDL_MOUSEMOTION)
		{
			mouseX = e.motion.x;
			mouseY = e.motion.y;
		}
		if (e.type == SDL_KEYDOWN)
		{
			int value = e.key.keysym.scancode;

			_inputs[value] = true;
			_downKeys[value] = true;
		}
		if (e.type == SDL_KEYUP)
		{
			int value = e.key.keysym.scancode;

			_inputs[value] = false;
			_upKeys[value] = true;
		}
		if (e.type == SDL_MOUSEBUTTONDOWN)
		{
			int value = e.button.button;

			mouseInput[value] = true;
			downMouse[value] = true;
		}
		if (e.type == SDL_MOUSEBUTTONUP)
		{
			int value = e.button.button;

			mouseInput[value] = false;
			upMouse[value] = true;
		}
	}
}

bool Input::GetKey(int keyCode)
{
	return _inputs[keyCode];
}

bool Input::GetKeyDown(int keyCode)
{
	return _downKeys[keyCode];
}

bool Input::GetKeyUp(int keyCode)
{
	return _upKeys[keyCode];
}

bool Input::GetMouse(int button)
{
	return mouseInput[button];
}

bool Input::GetMouseDown(int button)
{
	return downMouse[button];
}

bool Input::GetMouseUp(int button)
{
	return upMouse[button];
}

Vector2f Input::GetMousePosition()
{
	Vector2f res((float)mouseX, (float)mouseY);
	return res;
}

void Input::SetCursor(bool visible)
{
	if (visible)
		SDL_ShowCursor(1);
	else
		SDL_ShowCursor(0);
}

void Input::SetMousePosition(Vector2f pos)
{
	SDLSetMousePosition((int)pos.GetX(), (int)pos.GetY());
}

