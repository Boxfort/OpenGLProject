#ifndef COREENGINE_H
#define COREENGINE_H

class CoreEngine
{
public:
	CoreEngine();

	void Start();
	void Stop();

	~CoreEngine();
protected:
private:
	Display _display;

	void Run();
	void Render();
};

#endif
