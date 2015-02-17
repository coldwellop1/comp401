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
	this->blue = new int[nodeCount];
	this->red = new int[nodeCount];
	this->bipartite = true;	//a graph is bipartite until it isn't anymore.

	// create an array of length n
	matrix = new int* [nodeCount];

	// create arrays of length n within each block of the first array, creating a matrix.
	for (int i = 0; i < nodeCount; i++){
		matrix[i] = new int [nodeCount];
	}

	// initialize the matrix and color arrays
	this->initialize();
}


// assign a value of zero to each pair of coordinates in the matrix.
void adj_matrix::initialize()
{
	// initialize matrix
	for (int i = 0; i < nodeCount; i++)
		for (int j = 0; j < nodeCount; j++)
			matrix[i][j] = 0;

	//initialize color arrays
	for (int i = 0; i < nodeCount; i++){
		this->blue[i] = 0;
		this->red[i] = 0;
	}
}


void adj_matrix::addEdge(int from, int to)
{
	// check that values are valid
	if ((0 >= from) || (from > nodeCount) || (0 >= to) | (to > nodeCount))
		cout << "Error. Invalid Input." << endl;

	// check that edge does not already exist
	else if (checkEdge_h(from-1, to-1))
		cout << "There already exists an edge from node " << from << " to node " << to << "." << endl;

	// place edge(s)
	else{
		addEdge_h(from - 1, to - 1); 
		if (directed == true){
			cout << "Added " << from << "->" << to << "." << endl;
		}
		else{
			cout << "Added " << from << "--" << to << "." << endl;
		}
	}
}


// add edge helper function
void adj_matrix::addEdge_h(int from, int to)
{
	matrix[from][to] = 1;

	// if graph is NOT directed, place second edge going in other direction
	if (directed == false){
		matrix[to][from] = 1;
		check_bipartite(from + 1, to + 1);
	}
	if ((directed == true) && (matrix[to][from] == 0))
		check_bipartite(from + 1, to + 1);

}


bool adj_matrix::checkEdge(int from, int to){
	if (checkEdge_h(from - 1, to - 1)){
		return true;
	}
	else{
		return false;
	}

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
	else if (!checkEdge_h(from-1, to-1))
		cout << "There does not exist an edge from " << from << " to " << to << "." << endl;

	// remove edge(s)
	else{
		removeEdge_h(from - 1, to - 1);
		if (directed == true){
			cout << "Removed " << from << "->" << to << "." << endl;
		}
		else{
			cout << "Removed " << from << "--" << to << "." << endl;
		}
	}
}


// remove edge helper function
void adj_matrix::removeEdge_h(int from, int to)
{
	if ((!directed) || ((directed) && (!checkEdge(to-1, from-1))))	//if it is NOT directed or if it IS directed and there is no edge going the other way, remove from color arrays
		remove_bipart_checker(from, to);

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

bool adj_matrix::is_bipartite(){
	return bipartite;
}


void adj_matrix::check_bipartite(int from, int to){
	if (from == to)
		return;

	bool fr = false;	//if 'from' node is red
	bool tr = false;	//if 'to' node is red
	bool fb = false;	//if 'from' node is blue
	bool tb = false;	//if 'to' node is blue
	int index = 0;

	for (int i = 0; i < nodeCount; i++){
		if (red[i] == from){	//if 'from' node is red
			fr = true;
		}
		if (red[i] == to){		//if 'to' node is red
			tr = true;
		}
		if (blue[i] == from){	//if 'from' node is blue
			fb = true;
		}
		if (blue[i] == to){		//if 'to' node is blue
			tb = true;
		}
	}

	if (((fr == true) && (tr == true)) || ((fb == true) && (tb == true)) || ((fr == true) && (fb == true)) || ((tr == true) && (tb == true))){	//if nodes are the same color or one node appears in both, graph is no longer bipartite
		bipartite = false;
	}

	else if ((fr == false) && (fb == false)){	//if 'from' node is not yet in array
		if (tr == true){	//if 'to' node is red
			while (blue[index] != 0){	//find the next empty spot in blue.
				index++;
			}
			blue[index] = from;
			index = 0;		//reset index
		}
		else if (tb == true){	//if 'to' node is blue
			while (red[index] != 0){	//find the next empty spot in red.
				index++;
			}
			red[index] = from;
			index = 0;		//reset index
		}
		else{	//if neither node is in an array
			while (red[index] != 0){
				index++;
			}
			red[index] = from;	//add 'from' node to next empty spot in red.
			index = 0;		//reset index
			while (blue[index] != 0){
				index++;
			}
			blue[index] = to;	//add 'to' node to next empty spot in blue.
			index = 0;		//reset index
		}
	}

	else if ((tr == false) && (tb == false)){	//if 'to' node is not yet in array
		if (fr == true){	//if 'from' node is red
			while (blue[index] != 0){	//find the next empty spot in blue.
				index++;
			}
			blue[index] = to;
			index = 0;		//reset index
		}
		else if (fb == true){	//if 'from' node is blue
			while (red[index] != 0){	//find the next empty spot in red.
				index++;
			}
			red[index] = to;
			index = 0;		//reset index
		}
	}
	else{}//nodes are different, bipartite status does not change
}

void adj_matrix::check_bipartite(){
	adj_matrix temp(nodeCount, directed);
}






void adj_matrix::remove_bipart_checker(int from, int to){
	//check if this was the only edge for from or for to
	bool edgelessFrom = true;
	bool edgelessTo = true;

	for (int i = 0; i < nodeCount; i++){
		if (matrix[from][i] == 1)
			edgelessFrom = false;
		if (matrix[i][to] == 1)
			edgelessTo = false;
	}

	if (edgelessTo == true){
		for (int i = 0; i < nodeCount; i++){
			if (red[i] == to)
				red[i] = 0;
			if (blue[i] == to)
				blue[i] == 0;
		}
	}
	if (edgelessFrom == true){
		for (int i = 0; i < nodeCount; i++){
			if (red[i] == from)
				red[i] = 0;
			if (blue[i] == from)
				blue[i] = 0;
		}
	}

	//cross-reference arrays to check if graph is bipartite IF it was not already
	bool recheck_bipartite = true;

	if (bipartite == false){
		for (int i = 0; i < nodeCount; i++){
			for (int j = 0; j < nodeCount; j++){
				if ((red[i] == blue[j]) && (red[i] != 0))	//if the same number is in both arrays and it is not zero
					recheck_bipartite = false;
			}
		}
		bipartite = recheck_bipartite;
	}

}

void adj_matrix::printArrays(){
	cout << "Red:  ";
	for (int i = 0; i < nodeCount-1; i++){
		cout << red[i];
		if (red[i] >= 10)
			cout << ", ";
		else
			cout << ",  ";
	}
	cout << red[nodeCount - 1] << endl;

	cout << "Blue: ";
	for (int i = 0; i < nodeCount - 1; i++){
		cout << blue[i];
		if (blue[i] >= 10)
			cout << ", ";
		else
			cout << ",  ";
	}
	cout << blue[nodeCount - 1] << endl;

}