#pragma once

#include "gtx/transform.hpp"
#include "Utils/Matrix/Matrix.h"

glm::mat4 Matrix::Translate(glm::mat4 model, glm::vec3 translation)
{
	return glm::translate(model, translation);
}

glm::mat4 Matrix::Rotate(glm::mat4 model, float angleInRadians, glm::vec3 axis)
{
	return glm::rotate(model, angleInRadians, axis);
}

glm::mat4 Matrix::Scale(glm::mat4 model, glm::vec3 scaleVec)
{
	return glm::scale(model, scaleVec);
}