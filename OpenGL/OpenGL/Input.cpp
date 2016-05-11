#include "Input.h"

const static int NUM_KEYS = 512;
const static int NUM_MOUSEBUTTONS = 256;

static SDL_Event e;

static bool _inputs[NUM_KEYS];
static bool _downKeys[NUM_KEYS];
static bool _upKeys[NUM_KEYS];

Input::Input()
{
}

void Input::Update()
{
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

Input::~Input()
{
}
