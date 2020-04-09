#pragma once

#include <Common/BufferHandle/VertexBufferHandle.h>

VertexBufferHandle::VertexBufferHandle()
{
	GenerateBuffer();
}

void VertexBufferHandle::Bind()
{
	glBindVertexArray(vertexHandle);
}

void VertexBufferHandle::Unbind()
{
	glBindVertexArray(0);
}

inline VertexBufferHandle::~VertexBufferHandle()
{
	glDeleteBuffers(1, &vertexHandle);
}

void VertexBufferHandle::GenerateBuffer()
{

	glGenVertexArrays(1, &vertexHandle);
}
