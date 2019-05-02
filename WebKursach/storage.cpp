
#include "storage.h"


bool storage::check(vertex* _vert1, vertex* _vert2)
{
	for(int i=0;i<lines.size();i++)
	{
		if((_vert1->id==lines[i].vert1->id && _vert2->id == lines[i].vert2->id) || (_vert1->id == lines[i].vert2->id && _vert2->id == lines[i].vert1->id))
		{
			return false;
		}
	}
	return true;
}

storage::storage(){
}


storage::~storage()
{
}
