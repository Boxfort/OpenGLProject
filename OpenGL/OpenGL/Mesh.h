#ifndef MESH_H
#define MESH_H

#include "Vertex.h"
#include "GL/glew.h"
#include "obj_loader.h"

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);

	Mesh(const std::string& fileName);

	void InitMesh(const IndexedModel& model);
	void Draw();

	virtual ~Mesh();
protected:
private:
	enum
	{
		POSITION_VB,
		TEXCOORD_VB,
		INDEX_VB,

		NUM_BUFFERS
	};

	GLuint _vertexArrayObject;
	GLuint _vertexArrayBuffers[NUM_BUFFERS];
	unsigned int _drawCount;
};

#endif

