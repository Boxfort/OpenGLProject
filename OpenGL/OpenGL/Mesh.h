#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include "GL/glew.h"

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);

	void Draw();

	virtual ~Mesh();
protected:
private:
	enum
	{
		POSITION_VB,
		TEXCOORD_VB,
		NUM_BUFFERS
	};

	GLuint _vertexArrayObject;
	GLuint _vertexArrayBuffers[NUM_BUFFERS];
	unsigned int _drawCount;
};

#endif

