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
	if (directed == false)
		matrix[to][from] = 1;
}


bool adj_matrix::checkEdge(int from, int to){
	if (checkEdge_h(from - 1, to - 1)){
		cout << "Edge Exists." << endl;
		return true;
	}
	else{
		cout << "No Edge Found." << endl;
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

bool adj_matrix::check_bipartite()
{
	return check_bipartite_h();
}

bool adj_matrix::check_bipartite_h()
{
	int *red = new int[nodeCount];	
	int *blue = new int[nodeCount];
	bool color = false;	// false = red, true = blue
	int redCount = 0;
	int blueCount = 0;
	
	//populate arrays and check for overlapping values between arrays
	for (int i = 0; i < nodeCount; i++){
		for (int j = 0; j < nodeCount; j++)
			if (matrix[i][j] == 1){
				if (color){	//if we're doing blue now
					for (int k = 0; k < redCount; k++){
						if (red[k] == i)
							return false;	//if the value already exists in the other array, it is not bipartite.
					}
					for (int k = 0; k < blueCount; k++){
						if (blue[k] == i){}	//if the value already exists in the array, it will not be added again
						else{				// add the value to the array
							blue[blueCount] = i;
							blueCount++;
							color = true;	//switch to blue
						}
					}
				}
				else{		//if we're doing red now
					for (int k = 0; k < blueCount; k++){
						if (blue[k] == i)
							return false;	//if the value already exists in the other array, it is not bipartite.
					}
					for (int k = 0; k < redCount; k++){
						if (red[k] == i){}	//if the value already exists in the array, it will not be added again
						else{				// add the value to the array
							red[redCount] = i;
							redCount++;
							color = true;	//switch to blue
						}
					}
				}
				i = j;
				j = 0;
		}
	}
	return true;	//if it has not yet returned false, it is bipartite.
}
