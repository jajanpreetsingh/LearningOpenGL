#pragma once

#include <GL/glew.h>

class VertexBufferHandle
{
public:
	VertexBufferHandle();

	void Bind();

	void Unbind();

	~VertexBufferHandle();

private:

	void GenerateBuffer();

	GLuint vertexHandle;
};
