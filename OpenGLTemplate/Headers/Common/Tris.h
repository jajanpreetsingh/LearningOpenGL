#pragma once

#include "GL/glew.h"
#include "Common/Vec3.h"
#include "Common/Shader.h"
#include <vector>

class Tris
{
public:

	/// vertex array object, holds the "TYPE" of info about vertex
	/// can hold multiple vertex buffer objects, for color, normal, position, tangents
	GLuint vao;

	GLuint vboPosition;

	std::vector<GLfloat> vertices;

	Tris(Vec3 a, Vec3 b, Vec3 c = Vec3());

	void Draw();

	Shader* ConstructShader();

	void BindData();

	void UnbindData();

	~Tris();

private:

	const GLchar* vertShader = "											\n\
		#version 330														\n\
		layout (location = 0) in vec3 pos;									\n\
		void main()															\n\
		{																	\n\
			gl_Position = vec4(0.4 * pos.x, 0.4 * pos.y, pos.z, 1.0);	    \n\
		}";

	const GLchar* fragShader = "											\n\
		#version 330														\n\
		out vec4 color;														\n\
		void main()															\n\
		{																	\n\
			color = vec4(0.0,0.0,1.0, 1.0);									\n\
		}";

	Vec3* points;
};