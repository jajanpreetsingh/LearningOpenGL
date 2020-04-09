#pragma once

#include <GL/glew.h>
#include <vector>

class IndexBufferHandle
{
public:

	IndexBufferHandle(std::vector<GLuint>& data);

	void Bind();

	void Unbind();

	~IndexBufferHandle();

private:

	std::vector<GLuint> indices;

	int sizeInBytes;
 
	GLuint indexHandle;

	void GenerateBuffer();
};