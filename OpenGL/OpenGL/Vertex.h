#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord, const glm::vec3& normal = glm::vec3(0,0,0));
	
	inline glm::vec3* getPos() { return &_pos; }
	inline glm::vec3* getNormal() { return &_normal; }
	inline glm::vec2* getTexCoord() { return &_texCoord; }
	
	~Vertex();
protected:
private:
	glm::vec3 _pos;
	glm::vec3 _normal;
	glm::vec2 _texCoord;
};

#endif
