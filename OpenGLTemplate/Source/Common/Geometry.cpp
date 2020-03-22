#include "Common/Geometry.h"
#include "Utils/LoadedAssets.h"

Geometry::Geometry()
{
	vertexInfoHandle = 0;

	vertexPositionHandle = 0;

	indexBufferHandle = 0;

	shader = ConstructShader();
}

void Geometry::SetVertices(std::vector<Vec3> points)
{
	for (int i = 0; i < points.size(); i++)
	{
		vertices.push_back(points[i][0]);//x
		vertices.push_back(points[i][1]);//y
		vertices.push_back(points[i][2]);//z
	}
}

void Geometry::SetIndices(std::vector<GLuint> indices)
{
	this->indices = indices;
}

void Geometry::Update()
{
	Draw();
}

Geometry::~Geometry()
{
}

void Geometry::GenerateIndexBufferHandle()
{
	glGenBuffers(1, &indexBufferHandle);

	BindIndexBufferHandle();

	//bind data
	int size = sizeof(GLuint) * indices.size();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices.data(), GL_STATIC_DRAW);
}

void Geometry::BindIndexBufferHandle()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferHandle);
}

void Geometry::UnbindIndexBufferHandle()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Geometry::GenerateVertexInfoHandle()
{
	//generate "n"(=1) vertex arrays and
	//pass the pointer(vao) to those n arrays(n = 1 in our case)
	glGenVertexArrays(1, &vertexInfoHandle);
}

void Geometry::BindVertexArrayHandle()
{
	//Bind the vertex array you want to use
	glBindVertexArray(vertexInfoHandle);
}

void Geometry::UnbindVertexArrayHandle()
{
	glBindVertexArray(0);
}

void Geometry::GenerateBufferDataHandle()
{
	//SIMILARLY, generate n(=1 in our case); buffers and bind the first one
	glGenBuffers(1, &vertexPositionHandle);

	BindBufferDataHandle();

	//bind buffer data
	int size = sizeof(GLfloat) * vertices.size(); // or 9*sizeof(float);
	glBufferData(GL_ARRAY_BUFFER, size, vertices.data(), GL_STATIC_DRAW);
}

void Geometry::BindBufferDataHandle()
{
	glBindBuffer(GL_ARRAY_BUFFER, vertexPositionHandle); //GL_ARRAY_BUFFER is one of may targets(or say ways) to bind buffers
}

void Geometry::UnBindBufferDataHandle()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Shader* Geometry::ConstructShader()
{
	Shader* shader = new Shader(LoadedAssets::GetShader(ShaderType::Tris_Vert), LoadedAssets::GetShader(ShaderType::Tris_Frag));

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

void Geometry::Draw()
{
	shader->UseShaderProgram();

	BindVertexArrayHandle();
	BindIndexBufferHandle();
	
	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);//no of vertices(not distinct)

	//UnBindBufferDataHandle();
	UnbindIndexBufferHandle();
	UnbindVertexArrayHandle();

	shader->UnbindShaderProgram();
}
