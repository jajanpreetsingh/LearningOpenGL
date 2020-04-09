#pragma once

#include "Common/Vec1.h"

class Vec2 : public Vec1
{
public:

	Vec2();

	Vec2(float x, float y); 
	
	float operator[](int i);

	~Vec2();

protected:
	float y;
};