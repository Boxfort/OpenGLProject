#include "Display.h"
#include "sdl_backend.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

int Display::_width = 0;
int Display::_height = 0;

 void Display::Create(const char* title, int width, int height, bool fullscreen)
{
	Display::_width = width;
	Display::_height = height;

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	SDLCreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fullscreen);

	GLenum status = glewInit();
	if (status != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize" << std::endl;
	}
}

void Display::Render()
{
	SDLSwapBuffers();
}

void Display::Dispose()
{
	SDLDestroyWindow();
	SDL_Quit();
}

bool Display::IsCloseRequested()
{
	return SDLGetIsCloseRequested();
}