#pragma once
#include "line.h"
#include "storage.h"

class algorithm
{
public:
	/*
	int N;
	std::vector<vertex> used_vertex;
	std::vector<line> result_lines;
	std::vector<line> aviable_lines;
	*/

	algorithm();
	bool contains(std::vector<vertex> vertexes, vertex a);
	bool check_line(std::vector<line> lines, line a);

	std::vector<storage> alg(storage& store);
	
	~algorithm();
};

