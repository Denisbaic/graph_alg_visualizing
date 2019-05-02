
#include "vertex.h"

vertex::vertex(): id(0)
{
}

vertex::vertex(int _id)
{
	this->id = _id;
}

bool vertex::operator==(vertex& next_val)
{
	return this->id == next_val.id;
}

vertex::~vertex()
{
}