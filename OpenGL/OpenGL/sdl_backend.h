#ifndef SDL_BACKEND_H
#define SDL_BACkEND_H

	bool SDLGetIsCloseRequested();

	void SDLSetIsCloseRequested();

	void SDLCreateWindow(const char* title, int x, int y, int width, int height, bool fullscreen);

	void SDLSwapBuffers();

	void SDLDestroyWindow();

	void SDLSetMousePosition(int x, int y);

#endif