#pragma once

#include <Common/Vec1.h>

Vec1::Vec1(float x) : x(x)
{
}

float Vec1::operator[](int i)
{
	switch (i)
	{
	case 0:
		return x;
	default:
		return 0;
	}
}

Vec1::~Vec1()
{
}