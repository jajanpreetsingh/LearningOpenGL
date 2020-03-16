#pragma once

#include "GL/glew.h"
#include <string>
#include <map>

class Shader
{
public:

	Shader(std::string vertSource, std::string fragSource);

	bool LinkShader();

	bool AddAndCompileShader(GLenum type);

	void UseShaderProgram();

	void UnbindShaderProgram();

	~Shader();

private:

	std::map<GLenum, std::string> shaderSources;

	GLuint program;

	const GLchar* GetShaderByKey(GLenum key);

	void AddShaderSourceToMap(GLenum key, std::string source);
};