
#include "line_rend.h"


line_rend::line_rend()
{
}

line_rend::line_rend(float _vert1_x, float _vert1_y, float _vert2_x, float _vert2_y, float _weight)
{
	this->vert1_x = _vert1_x;
	this->vert1_y = _vert1_y;
	this->vert2_x = _vert2_x;
	this->vert2_y = _vert2_y;
	this->text = _weight;
}

line_rend::~line_rend()
{
}
