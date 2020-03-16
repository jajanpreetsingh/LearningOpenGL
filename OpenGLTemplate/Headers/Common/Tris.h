#pragma once

#include "GL/glew.h"
#include "Common/Vec3.h"
#include "Common/Shader.h"
#include <vector>
#include <string>

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

	void BindVertexArray();
	void UnbindVertexArray();

	void BindBufferData();
	void UnBindBufferData();

	void UnbindData();

	~Tris();

private:

	std::string vertShader = "												\n\
		#version 330														\n\
		layout (location = 0) in vec3 pos;									\n\
		void main()															\n\
		{																	\n\
			gl_Position = vec4(pos, 1.0);	    \n\
		}";

	std::string fragShader = "												\n\
		#version 330														\n\
		out vec4 color;														\n\
		void main()															\n\
		{																	\n\
			color = vec4(1.0,0.0,1.0, 1.0);									\n\
		}";

	Vec3* points;

	Shader* shader;

	void ConstructVertices();
};