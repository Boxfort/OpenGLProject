#include <iostream>
#include "Display.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include <GL/glew.h>
#include "transform.h"
#include "Camera.h"
#include "Time.h"
#include "Vertex.h"
#include "CoreEngine.h"


int main(int argc, char *argv[])
{
	
	CoreEngine CE(800, 600, 200);
	CE.CreateWindow("BoxEngine");
	CE.Start();

	return 0;
}