#pragma once

#include "GL/glew.h"
#include <string>
#include <map>
#include <vector>

class Shader
{
public:

	Shader(std::string vertSource, std::string fragSource);

	bool LinkShader();

	bool AddAndCompileShader(GLenum type);

	void UseShaderProgram();

	void UnbindShaderProgram();

	GLuint GetUniformLocation(std::string uniformName);

	~Shader();

private:

	std::map<GLenum, std::string> shaderSources;

	std::map<std::string, GLuint> uniformLocationMap;

	GLuint program;

	const GLchar* GetShaderByKey(GLenum key);

	void AddShaderSourceToMap(GLenum key, std::string source);

	void SetUniformFloat(std::string uniformName, float val);
};