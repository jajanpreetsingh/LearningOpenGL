#pragma once

#include "Common/Shader.h"
#include <iostream>

Shader::Shader(std::string vertSource, std::string fragSource)
{
	AddShaderSourceToMap(GL_VERTEX_SHADER, vertSource);
	AddShaderSourceToMap(GL_FRAGMENT_SHADER, fragSource);

	program = glCreateProgram();
}

bool Shader::LinkShader()
{
	GLint result = 0;
	GLchar log[1024] = { 0 };

	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(program, sizeof(log), nullptr, log);
		std::cout << "Error Linking Shader !!!" << std::endl << log << std::endl;
		return false;
	}

	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &result);

	if (!result)
	{
		glGetProgramInfoLog(program, sizeof(log), nullptr, log);
		std::cout << "Error Validating Shader !!!" << std::endl << log << std::endl;
		return false;
	}

	return true;
}

bool Shader::AddAndCompileShader(GLenum type)
{
	const GLchar* source = GetShaderByKey(type);

	GLuint shader = glCreateShader(type);

	GLint codeLength[] = { strlen(source) };

	glShaderSource(shader, 1, &source, codeLength);

	glCompileShader(shader);

	GLint result = 0;
	GLchar log[1024] = { 0 };

	glLinkProgram(shader);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (!result)
	{
		glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
		std::cout << "Error Compiling Shader of type " << type << " !!!" << std::endl << log << std::endl;
		return false;
	}

	glAttachShader(program, shader);

	glDeleteShader(shader);

	return true;
}

const GLchar* Shader::GetShaderByKey(GLenum key)
{
	return shaderSources[key].c_str();
}

void Shader::AddShaderSourceToMap(GLenum key, std::string source)
{
	shaderSources[key] = source;
}

GLuint Shader::GetUniformLocation(std::string uniformName)
{
	return glGetUniformLocation(program, uniformName.c_str());
}

void Shader::SetUniformFloat(std::string uniformName, float val)
{
	glUniform1f(uniformLocationMap[uniformName], val);
}

void Shader::UseShaderProgram()
{
	glUseProgram(program);
}

void Shader::UnbindShaderProgram()
{
	glUseProgram(0);
}

Shader::~Shader()
{
	glDeleteProgram(program);
}