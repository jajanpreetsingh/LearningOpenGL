#pragma once

#include <Common/Vec1.h>

class Vec2 : public Vec1
{
public:

	Vec2(float x = 0, float y = 0); 
	
	float operator[](int i);

	~Vec2();

protected:
	float y;
};