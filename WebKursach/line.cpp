
#include "line.h"


bool line::operator==(line& temp)
{
	if(this->vert1==temp.vert1 && this->vert2 == temp.vert2 || this->vert1 == temp.vert2 && this->vert2 == temp.vert1)
	{
		return true;
	}
	return false;
}

line::line()
{
}

line::line(float _weight, vertex* _vert1, vertex* _vert2)
{
	this->vert1 = _vert1;
	this->vert2 = _vert2;
	this->weight = _weight;
}

line::~line()
{
}

bool line::operator<(const line& b)
{
	return this->weight<b.weight;
}
//оператор проверки на равенство для unique
bool line::operator==(const line& b)
{
	return (this->vert1==b.vert1 && this->vert2==b.vert2) || (this->vert2==b.vert1&& this->vert1==b.vert2);
}