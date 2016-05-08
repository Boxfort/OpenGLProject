#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
	Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar);
	
	glm::mat4 GetViewProjection() const;
	
	~Camera();
protected:
private:
	glm::mat4 _perspective;
	glm::vec3 _position;
	glm::vec3 _forward;
	glm::vec3 _up;
};

#endif

