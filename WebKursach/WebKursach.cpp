// WebKursach.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "createDoc.h"
#include "storage.h"
#include "enter.h"
#include "algorithm.h"



int main()
{
	createDoc doc;


	storage store;

	enter menu(store);
	algorithm alg1;

	doc.set_doc();
	doc.DocTYPE();
	doc.Begin_doc();
	doc.link_css();

	doc.alg_graph(store, alg1.alg(store));
	doc.End_doc();
	doc.close_doc();


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


