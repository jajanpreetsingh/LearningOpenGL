#pragma once

#include "GL/glew.h"
#include <vector>
#include <Common/Vec3.h>
#include "Interfaces/Updatable.h"
#include "Common/Shader.h"

class Geometry : public Updatable
{
public:

	Shader* shader = nullptr;

	Geometry();

	void SetVertices(std::vector<Vec3> points);

	void SetIndices(std::vector<GLuint> indices);

	void Update();

	void GenerateIndexBufferHandle();

	void BindIndexBufferHandle();

	void UnbindIndexBufferHandle();

	void GenerateVertexInfoHandle();

	void BindVertexArrayHandle();

	void UnbindVertexArrayHandle();

	void GenerateBufferDataHandle();

	void BindBufferDataHandle();

	void UnBindBufferDataHandle();
	
	~Geometry();

//protected:

	/// vertex array object, holds the "TYPE" of info about vertex
	/// can hold multiple vertex buffer objects, for color, normal, position, tangents
	GLuint vertexInfoHandle;

	GLuint vertexPositionHandle;

	GLuint indexBufferHandle;

	std::vector<GLfloat> vertices;

	std::vector<GLuint> indices;

	virtual Shader* ConstructShader();

private:

	void Draw();
};