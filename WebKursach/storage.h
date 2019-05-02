#pragma once
#include <vector>

#include "vertex.h"
#include "line.h"


class storage
{
public:
	std::vector<vertex> vertexs;
	std::vector<line>lines;
	bool check(vertex* _vert1, vertex* _vert2);
	storage();
	~storage();
};

