#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2\SDL.h>

class Display
{
public:
	Display(const char* title, int width, int height, bool fullscreen);
	
	void Clear(float r, float g, float b, float a);
	void SwapBuffers();
	bool IsClosed();

	inline int GetWidth() { return _width; }
	inline int GetHeight() { return _height; }
	inline float GetAspect() { return ((float)_width / (float)_height); }

	virtual ~Display();
protected:
private:
	bool _isClosed;
	int _width, _height;
	SDL_Window* _window;
	SDL_GLContext _glContext;
};

#endif //DISPLAY_H

