#pragma once

#include "GL/glew.h"
#include "Common/Tris.h"
#include "Utils/LoadedAssets.h"
#include <iostream>

Tris::Tris(Vec3 a, Vec3 b, Vec3 c)
{
	points = new Vec3[3];
	vertexPositionHandle = 0;
	vertexInfoHandle = 0;

	points[0] = a;
	points[1] = b;
	points[2] = c;

	ConstructVertices();

	shader = ConstructShader();
}

void Tris::ConstructVertices()
{
	vertices.push_back(points[0][0]);
	vertices.push_back(points[0][1]);
	vertices.push_back(points[0][2]);

	vertices.push_back(points[1][0]);
	vertices.push_back(points[1][1]);
	vertices.push_back(points[1][2]);

	vertices.push_back(points[2][0]);
	vertices.push_back(points[2][1]);
	vertices.push_back(points[2][2]);

	BindData();

	shader = ConstructShader();
}

void Tris::Draw()
{
	if (shader == nullptr)
	{
		return;
	}

	shader->UseShaderProgram();

	BindVertexArrayHandle();

	BindBufferDataHandle();

	glDrawArrays(GL_TRIANGLES, 0, 3);// 3 is count of vertices, not triangles, see draw call in geometry class

	UnBindBufferDataHandle();

	UnbindVertexArrayHandle();

	shader->UnbindShaderProgram();
}

void Tris::BindData()
{
	GenerateVertexInfoHandle();
	BindVertexArrayHandle();

	GenerateBufferDataHandle();

	//stride is if we are using same array for pos, color and tangent etx.. then we need to jump to different values by skipping
	// in this case we are using it just for pos, so stride = 0
	int stride = 0;

	int noOfComponents = 3;// for x,y,z in position; shoul be 2 if no z specified
	int type = GL_FLOAT;

	//by what index the data will be ref in shaders or draw call
	//see vert shader layout line
	int index = 0;
	void* pointerOffset = 0;// if you want to start for nth vertex

	glVertexAttribPointer(index, noOfComponents, type, GL_FALSE, stride, pointerOffset);
	glEnableVertexAttribArray(index);

	UnbindData();
}

void Tris::UnbindData()
{
	//Unbind data vao and vboPosition
	UnBindBufferDataHandle();
	UnbindIndexBufferHandle();
	UnbindVertexArrayHandle();
}

void Tris::Update()
{
	Draw();
}

Tris::~Tris()
{
}