
#include "createDoc.h"
#include "circle_rend.h"
#include <set>
#include <cmath>
#include <string>

#define PI 3.14159265

void createDoc::set_doc()
{
	doc_html.open("result1.html");
	doc_css.open("style1.css");
	doc_html << "<!DOCTYPE html>" << std::endl;
}

void createDoc::Begin_doc()
{
	doc_html << "<html>" << std::endl;
}

void createDoc::link_css()
{
	doc_html << R"(<link href = "style1.css" rel = "stylesheet">)";
}

void createDoc::End_doc()
{
	doc_html << "</html>" << std::endl;
}

void createDoc::begin_svg()
{
	doc_html << "<svg width=\"" << 2 * graph_radius + 2 * 10 << "\"height=\"" << 2 * graph_radius + 2 * 10 << "\">" << std
		::endl;
}

void createDoc::end_svg()
{
	doc_html << "</svg>" << std::endl;
}

void createDoc::DocTYPE()
{
	doc_html << "<!DOCTYPE html>" << std::endl;
}

void createDoc::close_doc()
{
	doc_css.close();
	doc_html.close();
}

void createDoc::print_circle(circle_rend circle)
{
	doc_html << "<circle cx =\"" << circle.x << "\"cy =\"" << circle.y << "\"r=\"" << circle.r << "\"/>";
	std::string a = std::to_string(abs(circle.text + 1));
	float width_scale = a.length();
	doc_html << "<text fill=\"white\" x =\"" << circle.x - 4* width_scale << "\"y =\"" << circle.y + 5 << "\">" << circle.text + 1 <<
		"</text>" << std::endl;
}

void createDoc::print_line(line_rend line, int id, int index_graph, std::string color)
{
	doc_html << "<line id=\"line" << index_graph << id << "\" x1 = \"" << line.vert1_x << "\" y1 = \"" << line.vert1_y <<
		"\" x2 = \"" <<
		line.vert2_x << "\"y2 = \"" << line.vert2_y << "\" />" << std::endl;
	std::string a = std::to_string(abs(line.text));
	float width_scale = a.length();

	int lenght = sqrt(pow(line.vert2_x - line.vert1_x, 2) + pow(line.vert2_y - line.vert1_y, 2));

	int x3 = (line.vert2_x + line.vert1_x) / 2;
	int y3 = (line.vert2_y + line.vert1_y) / 2;

	doc_html << R"(<rect  style="fill:blue;" width=")" << width_scale * 10 << "\" height=\"15\" x=\"" << (line.vert1_x + x3
	) / 2 - width_scale * 10 / 2 << "\" y=\"" << (line.vert1_y + y3) / 2 - 7.5 << "\"/>";
		doc_html << "<text id=\"text" << index_graph << id << "\" fill=\"white\" x =\"" << (line.vert1_x + x3) / 2 -
		width_scale * 10 / 2 << "\"y =\"" << (line.
			vert1_y + y3) / 2 + 6 << "\">" << line.text << "</text>" << std::endl;

	doc_css << "#line" << index_graph << id << "{ stroke:" << color << ";}";
	
}

void createDoc::print_graph(int index_graph)
{
	for (size_t i = 0; i < vect_lines.size(); i++)
	{
		if (vect_result[i])
		{
			print_line(vect_lines[i], i, index_graph, "red");
		}
		else
		{
			print_line(vect_lines[i], i, index_graph, "black");
		}
	}

	for (size_t i = 0; i < vect_circles.size(); i++)
	{
		print_circle(vect_circles[i]);
	}
}

void createDoc::graph_circle_v1(storage& store, storage& result_store, int index_graph)
{
	number_vert = store.vertexs.size();
	vect_result.resize(store.lines.size(), false);
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		vect_circles.push_back(circle_rend(i));
	}
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		float angle = 360.0 / number_vert;
		float x;
		float y;

		x = cos(i * angle * PI / 180) * graph_radius + cx + 10;
		y = sin(i * angle * PI / 180) * graph_radius + cy + 10;

		vect_circles[i].x = x;
		vect_circles[i].y = y;
		vect_circles[i].text = i;
	}

	for (size_t i = 0; i < store.lines.size(); i++)
	{
		if (std::find(result_store.lines.begin(), result_store.lines.end(), store.lines[i]) != result_store.lines.end())
		{
			vect_result[i] = true;
		}
		int x1, x2, y1, y2;
		int id1, id2;
		id1 = store.lines[i].vert1->id;
		id2 = store.lines[i].vert2->id;
		x1 = vect_circles[id1 - 1].x;
		x2 = vect_circles[id2 - 1].x;
		y1 = vect_circles[id1 - 1].y;
		y2 = vect_circles[id2 - 1].y;
		line_rend* temp = new line_rend(x1, y1, x2, y2, store.lines[i].weight);
		vect_lines.push_back(*temp);
		delete temp;
	}
	this->begin_svg();
	this->print_graph(index_graph);
	this->end_svg();
}
void createDoc::graph_circle_v2(storage& store, storage& result_store, int index_graph)
{
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		vect_circles.push_back(circle_rend(i));
	}
	vect_circles[0].x = 40;
	vect_circles[0].y = 60;

	vect_circles[1].x = 150;
	vect_circles[1].y = 240;

	vect_circles[2].x = 220;
	vect_circles[2].y = 100;

	vect_circles[3].x = 285;
	vect_circles[3].y = 60;

	vect_circles[4].x = 280;
	vect_circles[4].y = 200;

	vect_circles[5].x = 165;
	vect_circles[5].y = 380;
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		vect_circles[i].text = i;
	}

	for (size_t i = 0; i < store.lines.size(); i++)
	{
		vect_result.resize(store.lines.size(), false);
		if (std::find(result_store.lines.begin(), result_store.lines.end(), store.lines[i]) != result_store.lines.end())
		{
			
			vect_result[i] = true;
		}
		int x1, x2, y1, y2;
		int id1, id2;
		id1 = store.lines[i].vert1->id;
		id2 = store.lines[i].vert2->id;
		x1 = vect_circles[id1 - 1].x;
		x2 = vect_circles[id2 - 1].x;
		y1 = vect_circles[id1 - 1].y;
		y2 = vect_circles[id2 - 1].y;
		line_rend* temp = new line_rend(x1, y1, x2, y2, store.lines[i].weight);
		vect_lines.push_back(*temp);
		delete temp;
	}
	this->begin_svg();
	this->print_graph(index_graph);
	this->end_svg();
}
void createDoc::graph_circle_v3(storage& store, storage& result_store, int index_graph)
{
	/*
	number_vert = store.vertexs.size();
	vect_result.resize(store.lines.size(), false);
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		vect_circles.push_back(circle_rend(i));
	}
	for (size_t i = 0; i < store.vertexs.size()-1; i++)
	{
		float angle = 360.0 / number_vert;
		float x;
		float y;

		x = cos(i * angle * PI / 180) * graph_radius + cx + 10;
		y = sin(i * angle * PI / 180) * graph_radius + cy + 10;

		vect_circles[i].x = x;
		vect_circles[i].y = y;
		vect_circles[i].text = i;
	}
	vect_circles[store.vertexs.size()-1].x = 160;
	vect_circles[store.vertexs.size()-1].y = 160;
	vect_circles[store.vertexs.size()-1].text = store.vertexs.size()-1;
	for (size_t i = 0; i < store.lines.size(); i++)
	{
		if (std::find(result_store.lines.begin(), result_store.lines.end(), store.lines[i]) != result_store.lines.end())
		{
			vect_result[i] = true;
		}
		int x1, x2, y1, y2;
		int id1, id2;
		id1 = store.lines[i].vert1->id;
		id2 = store.lines[i].vert2->id;
		x1 = vect_circles[id1 - 1].x;
		x2 = vect_circles[id2 - 1].x;
		y1 = vect_circles[id1 - 1].y;
		y2 = vect_circles[id2 - 1].y;
		line_rend* temp = new line_rend(x1, y1, x2, y2, store.lines[i].weight);
		vect_lines.push_back(*temp);
		delete temp;
	}
	this->begin_svg();
	this->print_graph(index_graph);
	this->end_svg();
	*/
	number_vert = store.vertexs.size();
	vect_result.resize(store.lines.size(), false);
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		vect_circles.push_back(circle_rend(i));
	}
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		float angle = 360.0 / number_vert;
		float x;
		float y;

		x = 200*cos(i * angle * PI / 180) + cx + 10;
		y = 100*sin(i * angle * PI / 180)  + cy + 10;

		vect_circles[i].x = x;
		vect_circles[i].y = y;
		vect_circles[i].text = i;
	}
	for (size_t i = 0; i < store.lines.size(); i++)
	{
		if (std::find(result_store.lines.begin(), result_store.lines.end(), store.lines[i]) != result_store.lines.end())
		{
			vect_result[i] = true;
		}
		int x1, x2, y1, y2;
		int id1, id2;
		id1 = store.lines[i].vert1->id;
		id2 = store.lines[i].vert2->id;
		x1 = vect_circles[id1 - 1].x;
		x2 = vect_circles[id2 - 1].x;
		y1 = vect_circles[id1 - 1].y;
		y2 = vect_circles[id2 - 1].y;
		line_rend* temp = new line_rend(x1, y1, x2, y2, store.lines[i].weight);
		vect_lines.push_back(*temp);
		delete temp;
	}
	this->begin_svg();
	this->print_graph(index_graph);
	this->end_svg();
}
void createDoc::graph_circle_v4(storage& store, storage& result_store, int index_graph)
{
	number_vert = store.vertexs.size();
	vect_result.resize(store.lines.size(), false);
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		vect_circles.push_back(circle_rend(i));
	}
	for (size_t i = 0; i < store.vertexs.size(); i++)
	{
		float angle = 360.0 / number_vert;
		float x;
		float y;

		x = 100 * cos(i * angle * PI / 180) + cx + 10;
		y = 200 * sin(i * angle * PI / 180) + cy + 10;

		vect_circles[i].x = x;
		vect_circles[i].y = y;
		vect_circles[i].text = i;
	}
	for (size_t i = 0; i < store.lines.size(); i++)
	{
		if (std::find(result_store.lines.begin(), result_store.lines.end(), store.lines[i]) != result_store.lines.end())
		{
			vect_result[i] = true;
		}
		int x1, x2, y1, y2;
		int id1, id2;
		id1 = store.lines[i].vert1->id;
		id2 = store.lines[i].vert2->id;
		x1 = vect_circles[id1 - 1].x;
		x2 = vect_circles[id2 - 1].x;
		y1 = vect_circles[id1 - 1].y;
		y2 = vect_circles[id2 - 1].y;
		line_rend* temp = new line_rend(x1, y1, x2, y2, store.lines[i].weight);
		vect_lines.push_back(*temp);
		delete temp;
	}
	this->begin_svg();
	this->print_graph(index_graph);
	this->end_svg();

}

void createDoc::alg_graph(storage& store, std::vector<storage>&& result_store)
{

	if(store.vertexs.size()==12)
	{
		for (size_t i = 0; i < result_store.size(); i++)
		{
			graph_circle_v1(store, result_store[i], i);
			vect_circles.clear();
			vect_lines.clear();
			vect_result.clear();
		}
	}
	else if(store.vertexs.size() == 6)
	{
		for (size_t i = 0; i < result_store.size(); i++)
		{
			graph_circle_v2(store, result_store[i], i);
			vect_circles.clear();
			vect_lines.clear();
			vect_result.clear();
		}

	}
	else if (store.vertexs.size() == 8)
	{
		for (size_t i = 0; i < result_store.size(); i++)
		{
			graph_circle_v3(store, result_store[i], i);
			vect_circles.clear();
			vect_lines.clear();
			vect_result.clear();
		}

	}
	else if (store.vertexs.size() == 10)
	{
		for (size_t i = 0; i < result_store.size(); i++)
		{
			graph_circle_v4(store, result_store[i], i);
			vect_circles.clear();
			vect_lines.clear();
			vect_result.clear();
		}

	}
	else
	{
		for (size_t i = 0; i < result_store.size(); i++)
		{

			graph_circle_v1(store, result_store[i], i);
			vect_circles.clear();
			vect_lines.clear();
			vect_result.clear();
		}
	}
	
}


createDoc::createDoc(): number_vert(0)
{
}


createDoc::~createDoc()
{
}
