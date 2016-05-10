#ifndef COREENGINE_H
#define COREENGINE_H

class CoreEngine
{
public:
	CoreEngine(int width, int height);

	void CreateWindow(const char* title, int width, int height, bool fullscreen);
	void Start();
	void Stop();

	~CoreEngine();
protected:
private:
	Display _display;
	bool _isRunning = false;

	void Run();
	void Render();
};

#endif
