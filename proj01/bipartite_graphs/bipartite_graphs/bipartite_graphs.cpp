// bipartite_graphs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "adj_matrix.h"
#include <iostream>
#include <string>

using namespace std;

void menu(adj_matrix myGraph);

string nCount, dir, choice, input, start, finish;
int to, from, nodes;
bool direct;

void main(){
	cout << "Please enter the number of nodes you require (fewer than 20): ";
	cin >> nCount;
	cout << endl;
	nodes = atoi(nCount.c_str());
	cin.clear();
	cin.ignore(10, '\n');

	cout << "Would you like a directed graph? (Y/N)  ";
	cin >> dir;
	if ((dir == "Y") || (dir == "y"))
		direct = true;
	else
		direct = false;

	adj_matrix myGraph(nodes, direct);

	menu(myGraph);
}

void menu(adj_matrix myGraph){
	// display menu
	cout << "Please choose one of the following: " << endl;
	cout << "1. Create edge" << endl;
	cout << "2. Remove edge" << endl;
	cout << "3. Determine if there is an edge between two nodes" << endl;
	cout << "4. Display graph" << endl;
	cout << "5. Display graph (edges only)" << endl;
	//cout << "8. Import graph from file" << endl;
	//cout << "7. Export graph to file" << endl;
	cout << "0. Quit" << endl;
	cin >> input;
	cout << endl;

	if ((input == "1") || (input == "2") || (input == "3")){
		cout << "Please enter the number associated with the node at the start of the edge: ";
		cin >> start;
		cout << endl;
		from = atoi(start.c_str());

		cout << "Please enter the number associated with the node at the other end of the edge: ";
		cin >> finish;
		cout << endl;
		to = atoi(finish.c_str());
	}
	if (input == "1")
		myGraph.addEdge(from, to);
	else if (input == "2")
		myGraph.removeEdge(from, to);
	else if (input == "3")
		myGraph.checkEdge(from, to);
	else if (input == "4")
		myGraph.print(true);	//true: we do want zeros
	else if (input == "5")
		myGraph.print(false);		//false: we don't want zeros
	//else if (input == "6")
	//	myGraph.print();
	//else if (input == "7")
	else if (input == "0"){
		myGraph.~myGraph();
		cout << "Your graph has been deleted." << endl;
		return;
	}
	else
		cout << "I don't understand." << endl << endl << endl;

	menu(myGraph);

}