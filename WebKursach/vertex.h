#pragma once
class vertex
{
public:
	int id;
	vertex();
	vertex(int _id);
	bool operator==(vertex& next_val);
	~vertex();
};
