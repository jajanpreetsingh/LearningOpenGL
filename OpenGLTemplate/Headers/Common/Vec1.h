#pragma once

class Vec1
{
public:

	Vec1(float x = 0); 
	
	float operator[](int i);

	~Vec1();

protected:

	float x;
};