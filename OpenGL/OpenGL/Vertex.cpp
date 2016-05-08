#include "Vertex.h"



Vertex::Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0, 0, 0))
{
	this->_pos = pos;
	this->_texCoord = texCoord;
	this->_normal = normal;
}


Vertex::~Vertex()
{
}
