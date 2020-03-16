#pragma once

#include "GL/glew.h"
#include <string>

class Shader
{
public:

	GLuint program;

	std::string vertShader;
	std::string fragShader;

	Shader(const GLchar* vertSource, const GLchar* fragSource);

	bool LinkShader();

	bool AddAndCompileShader(const GLchar* source, GLenum type);

	~Shader();

private:
};