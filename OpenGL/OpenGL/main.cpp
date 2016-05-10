#include "Display.h"
#include "Shader.h"
#include "Texture.h"
#include "Mesh.h"
#include <GL/glew.h>
#include "transform.h"
#include "Camera.h"
#include "Vertex.h"

int main(int argc, char *argv[])
{
	Display display("BoxEngine",800,600,false);
	Shader shader("./res/basicShader");

	//Vertex vertices[] = { Vertex(glm::vec3(-0.5,-0.5,0), glm::vec2(0,0), glm::vec3(0,1,0)),
	//					  Vertex(glm::vec3(0.0,0.5,0)  , glm::vec2(0.5,1.0), glm::vec3(1,0,0)),
	//					  Vertex(glm::vec3(0.5,-0.5,0) , glm::vec2(1.0,0), glm::vec3(-1,0,0))   };

	//unsigned int indices[] = { 0, 1, 2 };

	//Mesh mesh1(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices)/sizeof(indices[0]));
	Mesh mesh("./res/models/monkey.obj");

	Texture texture("./res/texture1.jpg", GL_NEAREST);
	Transform transform;
	Camera camera(glm::vec3(0, 0, -4), 70.0f, display.GetAspect(), 0.01f, 1000.0f);

	float counter = 0.0f;
	

	while (!display.IsClosed())
	{
		float cosCounter = cosf(counter);
		float sinCounter = sinf(counter);

		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);

		//transform.GetPos().x = sinf(counter);
		transform.GetRot().y = counter;
		//transform.SetScale(glm::vec3(cosCounter, cosCounter, sinCounter));

		shader.Bind();
		texture.Bind(0);
		shader.Update(transform, camera);
		mesh.Draw();

		display.Update();
		counter += 0.001f;
	}
	
	return 0;
}