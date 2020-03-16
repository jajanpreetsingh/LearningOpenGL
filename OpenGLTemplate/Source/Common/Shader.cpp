#pragma once

#include "Common/Shader.h"
#include <iostream>

Shader::Shader(const GLchar* vertSource, const GLchar* fragSource)
{
	this->vertShader = std::string(vertSource);
	this->fragShader = std::string(fragSource);

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

bool Shader::AddAndCompileShader(const GLchar* source, GLenum type)
{
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
		std::cout << "Error Compiling Shader !!!" << std::endl << log << std::endl;
		return false;
	}

	glAttachShader(program, shader);

	return true;
}

Shader::~Shader()
{
}