#pragma once
#include "vertex.h"

class line
{
public:
	float weight;
	vertex* vert1;
	vertex* vert2;
	
	bool operator==(line & temp);
	line();	
	line(float _weight,vertex* _vert1, vertex* _vert2);
	~line();
	bool operator<( const line& b);
	bool operator==(const line& b);
};

