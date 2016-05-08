#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>

class Transform
{
public:

	inline Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0, 1.0, 1.0)) :
		_pos(pos),
		_rot(rot),
		_scale(scale)
	{};
	
	glm::mat4 GetModel() const;

	inline glm::vec3& GetPos() { return _pos; }
	inline glm::vec3& GetRot() { return _rot; }
	inline glm::vec3& GetScale() { return _scale; }
	
	inline void SetPos(const glm::vec3 pos) { _pos = pos; }
	inline void SetRot(const glm::vec3 rot) { _rot = rot; }
	inline void SetScale(const glm::vec3 scale) { _scale = scale; }

	virtual ~Transform();
protected:
private:
	glm::vec3 _pos;
	glm::vec3 _rot;
	glm::vec3 _scale;
};

#endif

