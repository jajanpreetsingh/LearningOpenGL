#pragma once

#include <GL/glew.h>
#include <vector>
#include <Common/Vec3.h>

class DataBufferHandle
{
public:
	DataBufferHandle(std::vector<Vec3>& data, int sizePerComp);

	void Bind();

	void Unbind();

	~DataBufferHandle();

private:

	void GenerateBuffer();

	GLuint dataHandle;

	std::vector<GLfloat> vertices;

	int sizeInBytes;
};