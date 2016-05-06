#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3& pos);
	~Vertex();
protected:
private:
	glm::vec3 _pos;
};

#endif
