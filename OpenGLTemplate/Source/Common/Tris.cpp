#pragma once

#include "GL/glew.h"
#include "Common/Tris.h"
#include <iostream>

Tris::Tris(Vec3 a, Vec3 b, Vec3 c)
{
	points = new Vec3[3];
	vboPosition = 0;
	vao = 0;

	points[0] = a;
	points[1] = b;
	points[2] = c;

	ConstructVertices();
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

	BindVertexArray();

	glDrawArrays(GL_TRIANGLES, 0, 3);

	UnbindVertexArray();

	shader->UnbindShaderProgram();
}

Shader* Tris::ConstructShader()
{
	Shader* shader = new Shader(vertShader, fragShader);

	bool result = shader->AddAndCompileShader(GL_VERTEX_SHADER);

	if (!result)
	{
		return nullptr;
	}

	result = shader->AddAndCompileShader(GL_FRAGMENT_SHADER);

	if (!result)
	{
		return nullptr;;
	}

	result = shader->LinkShader();

	if (!result)
	{
		return nullptr;;
	}

	return shader;
}

void Tris::BindVertexArray()
{
	//Bind the vertex array you want to use
	glBindVertexArray(vao);
}

void Tris::UnbindVertexArray()
{
	glBindVertexArray(0);
}

void Tris::BindBufferData()
{
	glBindBuffer(GL_ARRAY_BUFFER, vboPosition); //GL_ARRAY_BUFFER is one of may targets(or say ways) to bind buffers
}

void Tris::UnBindBufferData()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Tris::BindData()
{
	//generate "n"(=1) vertex arrays and
	//pass the pointer(vao) to those n arrays(n = 1 in our case)
	glGenVertexArrays(1, &vao);
	BindVertexArray();

	//SIMILARLY, generate n(=1 in our case); buffers and bind the first one
	glGenBuffers(1, &vboPosition);
	BindBufferData();

	//bind data
	int size = sizeof(float) * vertices.size(); // or 9*sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, size, vertices.data(), GL_STATIC_DRAW);

	//stride is if we are using same array for pos, color and tangent etx.. then we need to jump to different values by skipping
	// in this case we are using it just for pos, so stride = 0
	int stride = 0;

	int sizeOfData = 3;// for x,y,z in position
	int type = GL_FLOAT;

	//by what index the data will be ref in shaders or draw call
	//see vert shader layout line
	int index = 0;
	void* pointerOffset = 0;// if you want to start for nth vertex

	glVertexAttribPointer(index, sizeOfData, type, GL_FALSE, stride, pointerOffset);
	glEnableVertexAttribArray(index);

	UnbindData();
}

void Tris::UnbindData()
{
	//Unbind data vao and vboPosition
	UnBindBufferData();
	UnbindVertexArray();
}

Tris::~Tris()
{
}