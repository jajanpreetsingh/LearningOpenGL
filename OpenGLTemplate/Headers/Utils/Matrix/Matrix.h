#pragma once

#include "glm.hpp"

class Matrix
{
public:

	static glm::mat4 Translate(glm::mat4 model, glm::vec3 translation);

	static glm::mat4 Rotate(glm::mat4 model,float angle, glm::vec3 axis);

	static glm::mat4 Scale(glm::mat4 model, glm::vec3 scaleVec);
};
