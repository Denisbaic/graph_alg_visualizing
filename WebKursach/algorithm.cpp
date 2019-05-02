
#include "algorithm.h"
#include <algorithm>
#include <iostream>


algorithm::algorithm()
{
}

bool algorithm::contains(std::vector<vertex> vertexes,vertex a)
{
	std::vector<vertex>::iterator iter;
	for (iter = vertexes.begin(); iter != vertexes.end(); ++iter)
	{
		if(*iter==a)
		{
			return true;
		}
	}
	return false;
}

void add_aviable_line(std::vector<line>& lines, std::vector<line>& all_lines,vertex a)
{
	std::vector<line>::iterator iter = all_lines.begin();
	int i = 0;
	while(iter!=all_lines.end())
	{
		if(*iter->vert1==a|| *iter->vert2 == a)
		{
			lines.push_back(*iter);
			if(all_lines.size()==1)
			{
				all_lines.clear();
				break;
			}
			iter=all_lines.erase(iter);
			if(iter != all_lines.begin())
			{
				--iter;
			}
		}
		++iter;
		++i;
	}
	
}

std::vector<storage> algorithm::alg(storage& store)
{
	std::vector<storage> result_store;
	std::vector<line>min_lines;
	std::vector<vertex>used_vertex;
	std::vector<line>aviable_lines;
	std::vector<line>all_lines=store.lines;
	//включаем добавляем первую вершину и к нему доступные рёбра
	//включаем из них минимальное ребро в результат, удаляем его из вектора доступных линий, добавляем новую вершину
	//на третьем шаге удаляем рёбра, которые содержат две включённые вершины и не включены в результат

	//выделяем доступные рёбра
	//выбираем минимальное и включаем его в результат
	//удаляем из вектора доступных линий
	//удаляем рёбра, которые содержат две включённые вершины и не включены в результат

	for (unsigned int i = 0; i<store.vertexs.size()-1; i++)
	{
		line* min_line = new line(INFINITY, 0, 0);
		min_lines.push_back(*min_line);
		delete min_line;
	}


	used_vertex.push_back(store.vertexs[0]);

	add_aviable_line(aviable_lines, all_lines, used_vertex[0]);
	std::vector<line>::iterator min_line;
	for(std::vector<line>::iterator iter = aviable_lines.begin(); iter!=aviable_lines.end();++iter)
	{
		if(*iter<min_lines[0])
		{
			min_lines[0] = *iter;
			min_line = iter;
		}
	}
	if (!contains(used_vertex, *min_line->vert1))
	{
		used_vertex.push_back(*min_line->vert1);
	}
	if (!contains(used_vertex, *min_line->vert2))
	{
		used_vertex.push_back(*min_line->vert2);
	}
	min_lines[0]=*min_line;
	min_line = aviable_lines.erase(min_line);
	///////////////////////////////////
	storage* ptr_store = new storage();
	ptr_store->lines = min_lines;
	result_store.push_back(*ptr_store);
	delete ptr_store;
	//////////////////////////////////

	for(unsigned int i=1;i<store.vertexs.size()-1;i++)
	{
		for (std::vector<vertex>::iterator iter = used_vertex.begin(); iter != used_vertex.end(); ++iter)
		{
			add_aviable_line(aviable_lines, all_lines, *iter);
		}
		for (std::vector<line>::iterator iter = aviable_lines.begin(); iter != aviable_lines.end(); ++iter)
		{
			if (*iter<min_lines[i])
			{
				min_lines[i] = *iter;
				min_line = iter;
			}
		}
		if (!contains(used_vertex, *min_line->vert1))
		{
			used_vertex.push_back(*min_line->vert1);
		}
		if (!contains(used_vertex, *min_line->vert2))
		{
			used_vertex.push_back(*min_line->vert2);
		}
		min_lines[i]=*min_line;
		min_line = aviable_lines.erase(min_line);
		///////////////////////////////////
		ptr_store = new storage();
		ptr_store->lines = min_lines;
		result_store.push_back(*ptr_store);
		delete ptr_store;
		//////////////////////////////////
		
			for (std::vector<line>::iterator iter_lines = aviable_lines.begin(); iter_lines < aviable_lines.end();)
			{
				if (contains(used_vertex, *iter_lines->vert1) && contains(used_vertex, *iter_lines->vert2))
				{
					iter_lines = aviable_lines.erase(iter_lines);
				}
				else
				{										
					++iter_lines;					
				}
			}
		
	}	
	return result_store;
}


algorithm::~algorithm()
{
}
