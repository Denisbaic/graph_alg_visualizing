#pragma once
#include <fstream>
#include <vector>
#include "storage.h"
#include "circle_rend.h"
#include "line_rend.h"

class createDoc
{
public:
	//GRAPH PROPERTIES
	int graph_radius = 200;
	int number_vert;
	int cx = graph_radius, cy = graph_radius;

	std::vector<circle_rend> vect_circles;
	std::vector<line_rend> vect_lines;
	std::vector<bool> vect_result;

	std::ofstream doc_html;
	std::ofstream doc_css;

	void set_doc();
	void Begin_doc();
	void link_css();
	void End_doc();
	void begin_svg();
	void end_svg();
	void DocTYPE();
	void close_doc();
	void print_circle(circle_rend circle);
	void print_line(line_rend line, int id, int index_graph, std::string color);
	void print_graph(int index_graph);

	void graph_circle_v1(storage& store, storage& result_store, int index_graph);
	void graph_circle_v2(storage& store, storage& result_store, int index_graph);
	void graph_circle_v3(storage& store, storage& result_store, int index_graph);
	void graph_circle_v4(storage& store, storage& result_store, int index_graph);

	void alg_graph(storage& store, std::vector<storage>&& result_store);	


	createDoc();
	~createDoc();
};
