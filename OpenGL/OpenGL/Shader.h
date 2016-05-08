#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include "transform.h"
#include "Camera.h"

class Shader
{
public:
	Shader(const std::string& fileName);

	void Bind();
	void Update(const Transform& transform, const Camera& camera);

	virtual ~Shader();
protected:
private:
	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	static const unsigned int NUM_SHADERS = 2;
	GLuint _program;
	GLuint _shaders[NUM_SHADERS];
	GLuint _uniforms[NUM_UNIFORMS];

	std::string LoadShader(const std::string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const std::string& text, GLenum shaderType);
};

#endif // SHADER_H