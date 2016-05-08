#include "Transform.h"

glm::mat4 Transform::GetModel() const
{
	glm::mat4 posMatrix = glm::translate(_pos);
	glm::mat4 rotxMatrix = glm::rotate(_rot.x, glm::vec3(1, 0, 0));
	glm::mat4 rotyMatrix = glm::rotate(_rot.y, glm::vec3(0, 1, 0));
	glm::mat4 rotzMatrix = glm::rotate(_rot.z, glm::vec3(0, 0, 1));
	glm::mat4 scaleMatrix = glm::scale(_scale);

	glm::mat4 rotMatrix = rotzMatrix * rotyMatrix * rotxMatrix;

	return posMatrix * rotMatrix * scaleMatrix;
}

Transform::~Transform()
{
}
