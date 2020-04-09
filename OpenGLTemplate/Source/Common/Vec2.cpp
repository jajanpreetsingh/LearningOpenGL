#pragma once

#include "Common/Vec2.h"

Vec2::Vec2() :Vec1(0), y(0)
{
}

Vec2::Vec2(float x, float y) : Vec1(x), y(y)
{
}

float Vec2::operator[](int i)
{
	switch (i)
	{
	case 0:
		return x;
	case 1:
		return y;
	default:
		return 0;
	}
}

Vec2::~Vec2()
{
}