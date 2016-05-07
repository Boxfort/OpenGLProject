#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord);
	
	inline glm::vec3* getPos() { return &_pos; }
	inline glm::vec2* getTexCoord() { return &_texCoord; }
	
	~Vertex();
protected:
private:
	glm::vec3 _pos;
	glm::vec2 _texCoord;
};

#endif
