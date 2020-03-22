#pragma once

#include "Common/Geometry.h"
#include "Common/Vec3.h"
#include "Common/Shader.h"
#include <vector>
#include <string>

class Tris : public Geometry
{
public:

	Tris(Vec3 a, Vec3 b, Vec3 c = Vec3());

	void BindData();

	void UnbindData();

	void Update();

	~Tris();

private:

	Vec3* points;

	void ConstructVertices();

	void Draw();
};