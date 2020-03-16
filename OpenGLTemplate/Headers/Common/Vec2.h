#pragma once

#include "Common/Vec1.h"

class Vec2 : public Vec1
{
public:

	Vec2();

	Vec2(float x, float y);

	~Vec2();

protected:
	float y;
};