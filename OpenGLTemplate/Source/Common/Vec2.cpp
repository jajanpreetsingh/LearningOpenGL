#pragma once

#include "Common/Vec2.h"

Vec2::Vec2()
{
	x = y = 0;
}

Vec2::Vec2(float x, float y) : Vec1(x)
{
	this->y = y;
}

Vec2::~Vec2()
{
}