
#include "enter.h"
#include <iostream>
#include "storage.h"
using namespace std;

enter::enter(storage& store )
{
	int number_of_vertex;
	cin >> number_of_vertex;
	//создание вершин
	for(int i=0;i<number_of_vertex;i++)
	{
		vertex* a = new vertex(i+1);
		store.vertexs.push_back(*a);
		delete a;
	}
	//ввод линий
	int vert1=0, vert2=0,weight=0;
	while(true)
	{
		cin >> vert1;
		if(vert1==0)
		{
			break;
		}
		cin >> vert2;
		cin >> weight;
		if(store.check(&vertex(vert1), &vertex(vert2)))
		{
			store.lines.push_back(line(weight, &store.vertexs[vert1 - 1], &store.vertexs[vert2 - 1]));
		}
		
	}
}


enter::~enter()
{
}

