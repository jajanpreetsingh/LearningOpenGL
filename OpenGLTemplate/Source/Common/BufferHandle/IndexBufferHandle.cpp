#pragma once

#include <Common/BufferHandle/IndexBufferHandle.h>

IndexBufferHandle::IndexBufferHandle(std::vector<GLuint>& data)
{
	indices = data;

	sizeInBytes = sizeof(GLuint) * indices.size();

	GenerateBuffer();
}

void IndexBufferHandle::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexHandle);
}

void IndexBufferHandle::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBufferHandle::~IndexBufferHandle()
{
	glDeleteBuffers(1, &indexHandle);
}

void IndexBufferHandle::GenerateBuffer()
{
	glGenBuffers(1, &indexHandle);
}
