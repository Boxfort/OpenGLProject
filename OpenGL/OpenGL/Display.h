#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <SDL2\SDL.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	
	void Clear(float r, float g, float b, float a);
	void Update();
	bool IsClosed();

	inline int GetWidth() { return _width; }
	inline int GetWidth() { return _height; }

	virtual ~Display();
protected:
private:
	bool _isClosed;
	int _width, _height;
	SDL_Window* _window;
	SDL_GLContext _glContext;
};

#endif //DISPLAY_H

