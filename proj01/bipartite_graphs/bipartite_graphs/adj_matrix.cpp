#include "stdafx.h"
#include "adj_matrix.h"

using namespace std;


adj_matrix::~adj_matrix ()
{
}


// Constructor: accepts POSITIVE integer representing the number of nodes in the graph
adj_matrix::adj_matrix (int n, bool d)
{
	this->nodeCount = n;
	this->directed = d;

	// create an array of length n
	matrix = new int* [nodeCount];

	// create arrays of length n within each block of the first array, creating a matrix.
	for (int i = 0; i < nodeCount; i++){
		matrix[i] = new int [nodeCount];
	}

	// initialize the matrix
	this->initialize();
}


// assign a value of zero to each pair of coordinates in the matrix.
void adj_matrix::initialize()
{
	for (int i = 0; i < nodeCount; i++)
		for (int j = 0; j < nodeCount; j++)
			matrix[i][j] = 0;
}


void adj_matrix::addEdge(int from, int to)
{
	// check that values are valid
	if ((0 >= from) || (from > nodeCount) || (0 >= to) | (to > nodeCount))
		cout << "Error. Invalid Input." << endl;

	// check that edge does not already exist
	else if (checkEdge(from, to))
		cout << "There already exists an edge from node " << from << " to node " << to << "." << endl;

	// place edge(s)
	else
		addEdge_h(from-1, to-1);	
}


// add edge helper function
void adj_matrix::addEdge_h(int from, int to)
{
	matrix[from][to] = 1;

	// if graph is NOT directed, place second edge going in other direction
	if (directed == false)
		matrix[to][from] = 1;
}


bool adj_matrix::checkEdge(int from, int to){
	return checkEdge_h(from-1, to-1);
}


// if user input values are valid and there exists an edge from 'from' to 'to, return true. Otherwise return false.
bool adj_matrix::checkEdge_h(int from, int to){
	int edgeVal = matrix[from][to];
	if (edgeVal == 1)
			return true;
	else
		return false;
}


void adj_matrix::removeEdge(int from, int to)
{
	// check that values are valid
	if ((0 >= from) || (from > nodeCount) || (0 >= to) || (to > nodeCount))
		cout << "Error. Invalid Input." << endl;

	// check that edge exists
	else if (!checkEdge(from, to))
		cout << "There does not exist an edge from " << from << " to " << to << "." << endl;

	// remove edge(s)
	else
		removeEdge_h(from-1, to-1);
}


// remove edge helper function
void adj_matrix::removeEdge_h(int from, int to)
{
	matrix[from][to] = 0;

	// if graph is NOT directed, remove second edge going in other direction
	if (directed == false)
		matrix[to][from] = 0;
}


// display graph
void adj_matrix::print(bool zeros){
	print_h(zeros);
}


// graph display helper function
void adj_matrix::print_h(bool zeros)
{
	if (0 >= nodeCount){
		cout << "ERROR: matrix is too small to display." << endl;
		return;
	}
	else if (nodeCount > 99){
		cout << "ERROR: matrix is too large to display." << endl;
		return;
	}

	// print out horizontal indices
	cout << "    ";
	for (int i = 1; i <= nodeCount; i++){
		cout << i;
		if (i < 10)	// FORMATTING: 3 spaces for 1 digit values, 2 spaces for 2 digit values.
			cout << "   ";
		else
			cout << "  ";

	}
	cout << endl;

	// print out vertical indices and values within matrix.
	for (int j = 0; j < nodeCount; j++){
		if (j < 9)	// FORMATTING: 3 spaces for 1 digit values, 2 spaces for 2 digit values.
			cout << j+1 << "   ";
		else
			cout << j+1 << "  ";
		for (int k = 0; k < nodeCount; k++){
			if ((zeros == false) && (matrix[j][k] == 0))
				cout << " ";
			else
				cout << matrix[j][k];
			if (k+1 != nodeCount)
				cout << "   ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}


void adj_matrix::readFile(string filename){
	fstream fin;
	string line, from, to;
	int strt, fnsh;
	int commaLoc;
	fin.open(filename);
	if (fin.is_open()){
		while (!fin.eof()){
			getline(fin, line);
			if (line == ""){} //skip blank lines
			else{
				commaLoc = line.find(',');
				from = line.substr(0, commaLoc);
				to = line.substr(commaLoc + 2, line.length());
				strt = atoi(from.c_str());
				fnsh = atoi(to.c_str());
				
			}
		}
	}
	else{
		cout << "Cannot open file." << endl;
		return;
	}
	cout << "Read successful." << endl;

}