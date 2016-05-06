#ifndef TEXTURE_H
#define TEXTURE_H

#include "GL/glew.h"
#include <string>

class Texture
{
public:
	Texture(const std::string& fileName, GLfloat filter);

	void Bind(unsigned int unit);

	virtual ~Texture();
protected:
private:

	GLuint _texture;
};

#endif

