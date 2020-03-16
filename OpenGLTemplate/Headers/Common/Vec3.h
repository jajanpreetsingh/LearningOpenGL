#pragma once

#include "Common/Vec2.h"

class Vec3 : public Vec2
{
public:

	Vec3();

	Vec3(float x, float y, float z);

	float operator[](int i);

	~Vec3();

private:

	float z;
};