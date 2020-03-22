#pragma once

#include <iostream>
#include "GL/glew.h"

#define ASSERT(x) if (!(x)) __debugbreak();

//calls a method x
#define CALLGLMETHOD(x) ClearGLError(); x; ASSERT(LogGLError(#x, __FILE__, __LINE__));

static void ClearGLError()
{
	while (glGetError() != GL_NO_ERROR);
}

static bool LogGLError(const char* funcName, const char* file, int lineNumber)
{
	while (GLenum error = glGetError())
	{
		std::cout << "[ Open GL error ] " << error << std::endl;
		return false;
	}

	return true;
}