#pragma once

#include "Common/Vec3.h"

Vec3::Vec3() : Vec2(0, 0), z(0)
{
}

Vec3::Vec3(float x, float y, float z) : Vec2(x, y), z(x)
{
}

Vec3::~Vec3()
{
}

float Vec3::operator[](int i)
{
	switch (i)
	{
	case 0:
		return x;
	case 1:
		return y;
	case 2:
		return z;
	default:
		return 0;
	}
}