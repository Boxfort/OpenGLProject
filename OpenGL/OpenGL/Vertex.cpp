#include "Vertex.h"



Vertex::Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
{
	this->_pos = pos;
	this->_texCoord = texCoord;
}


Vertex::~Vertex()
{
}
