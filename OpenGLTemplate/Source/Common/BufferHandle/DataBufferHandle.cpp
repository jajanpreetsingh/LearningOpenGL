#pragma once

#include <Common/BufferHandle/DataBufferHandle.h>

DataBufferHandle::DataBufferHandle(std::vector<Vec3>& data, int sizePerComp)
{
	for (size_t i = 0; i < data.size(); i++)
	{
		for (size_t j = 0; j < sizePerComp; j++)
		{
			vertices.emplace_back(data[i][j]);
		}
	}

	sizeInBytes = data.size() * sizePerComp * sizeof(GLfloat);

	GenerateBuffer();

	Bind();

	glBufferData(GL_ARRAY_BUFFER, sizeInBytes, vertices.data(), GL_STATIC_DRAW);

	Unbind();
}

void DataBufferHandle::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, dataHandle);
}

void DataBufferHandle::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

DataBufferHandle::~DataBufferHandle()
{
	glDeleteBuffers(1, &dataHandle);
}

void DataBufferHandle::GenerateBuffer()
{
	glGenBuffers(1, &dataHandle);
}
