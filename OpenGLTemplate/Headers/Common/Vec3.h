#pragma once

#include "Common/Vec2.h"

class Vec3 : public Vec2
{
public:

	Vec3(float x = 0, float y = 0, float z = 0);

	float operator[](int i);

	~Vec3();

private:

	float z;
};