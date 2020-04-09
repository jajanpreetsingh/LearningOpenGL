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

	std::vector<GLuint> indices;

private:

	int sizeInBytes;
 
	GLuint indexHandle;

	void GenerateBuffer();
};