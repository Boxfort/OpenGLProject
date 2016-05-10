#ifndef COREENGINE_H
#define COREENGINE_H

class CoreEngine
{
public:
	CoreEngine();

	void Start();
	void Stop();
	void Run();
	void Render();

	~CoreEngine();
protected:
private:
	Display _display;
};

#endif
