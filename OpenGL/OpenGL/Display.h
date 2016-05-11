#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
public:
	Display() {};
	
	static void Create(const char* title, int width, int height, bool fullscreen);
	static void Render();
	static void Dispose();
	static bool IsCloseRequested();

	static inline int GetWidth() { return _width; }
	static inline int GetHeight() { return _height; }
	static inline float GetAspect() { return ((float)_width / (float)_height); }

protected:
private:
	static int _width, _height;
};

#endif //DISPLAY_H

