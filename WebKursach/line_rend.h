#pragma once
class line_rend
{
public:
	float vert1_x,vert1_y, vert2_x, vert2_y;
	int text;
	
	line_rend();
	line_rend(float _vert1_x, float _vert1_y, float _vert2_x, float _vert2_y, float _weight);
	~line_rend();
};

