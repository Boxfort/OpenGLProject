#include "Time.h"

const double Time::SECOND = 1000000000;
const double Time::MILLISECOND = 1000000;

double Time::GetTime() 
{ 
	return (SDL_GetTicks() / 1000.0); 
};

