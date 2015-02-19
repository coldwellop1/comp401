#include "stdafx.h"
#include "adj_matrix.h"

using namespace std;

//Destructor
adj_matrix::~adj_matrix(){
}

//Constructor: accepts positive integer representing the number of nodes in the graph.
adj_matrix::adj_matrix(int n, bool d){
	this->nodeCount = n;
	this->directed = d;

	//create an integer array of length n
	matrix = new int*[nodeCount];

	// create arrays of length n within each block of the first array, creating a matrix.
	for (int i = 0; i < nodeCount; i++){
		matrix[i] = new int[nodeCount];
	}

	// initialize the matrix
	for (int i = 0; i < nodeCount; i++){
		for (int j = 0; j < nodeCount; j++){
			matrix[i][j] = 0;
		}
	}
}

//Public function to add an edge to the graph.
//Checks that the selected nodes are valid and that there is no edge already there.
//Calls helper function to add edge.
void adj_matrix::addEdge(int from, int to){
	//check that values are valid
	if ((0 >= from) || (from > nodeCount) || (0 >= to) || (to > nodeCount))
		cout << "Error.  Invalid Input." << endl;

	//check that edge does not already exist
	else if (checkEdge_h(from - 1, to - 1))
		cout << "There already exists an edge from node " << from << " to node " << to << "." << endl;

	//place edge(s)
	else{
		addEdge_h(from - 1, to - 1);
		if (directed == true)
			cout << "Added " << from << "->" << to << "." << endl;
		else
			cout << "Added " << from << "--" << to << "." << endl;
	}
}

//Private helper function for adding an edge.  Accesses private data member 'matrix' 
//and assigns the integer 1 to matrix[from][to] 
void adj_matrix::addEdge_h(int from, int to){
	matrix[from][to] = 1;

	// if graph is NOT directed, place a second edge going in the other direction
	if (directed == false)
		matrix[to][from] = 1;
}

//Public function to check if an edge is present between two nodes.
//Calls helper function to check edge
//Returns true if there exists an edge and false if there is no edge.
bool adj_matrix::checkEdge(int from, int to){
	if (checkEdge_h(from - 1, to - 1))
		return true;
	else
		return false;
}

//Private helper function for checking if an edge exists on the graph.  Accesses 
//private data member 'matrix'
bool adj_matrix::checkEdge_h(int from, int to){
	if (matrix[from][to] == 1)
		return true;
	else
		return false;
}

//Public function to remove an edge from the graph.
//Checks that nodes are valid and the edge exists in the graph.  Removes edge if 
//it exists.
void adj_matrix::removeEdge(int from, int to){
	//check that values are valid
	if ((0 >= from) || (from > nodeCount) || (0 >= to) || (to > nodeCount))
		cout << "Error.  Invalid Input." << endl;

	//check that edge does not already exist
	else if (!checkEdge_h(from - 1, to - 1))
		cout << "There does not exist an edge from node " << from << " to node " << to << "." << endl;

	//remove edge(s)
	else{
		removeEdge_h(from - 1, to - 1);
		if (directed == true)
			cout << "Removed " << from << "->" << to << "." << endl;
		else
			cout << "Removed " << from << "--" << to << "." << endl;
	}
}

//Private helper function for removing an edge from the graph.  Accesses private 
//data member 'matrix'
void adj_matrix::removeEdge_h(int from, int to){
	matrix[from][to] = 0;

	// if graph is NOT directed, remove second edge going in other direction
	if (directed == false)
		matrix[to][from] = 0;
}

//Public function to display matrix of graph to the console
//Checks to make sure the nodeCount of the matrix is within the limits 
//to be displayed (0 < nodeCount < 20) Calls private function, accepts a bool, 
//depending on whether or not the user wishes to display just the edges (true) 
//or the whole matrix (false)
void adj_matrix::print(bool edges){
	if ((0 >= nodeCount) || (20 <= nodeCount)){
		cout << "ERROR: Matrix node count is outside given parameters.  To display, node count must be between 0 and 20." << endl;
	}
	else
		print_h(edges);
}

//Private helper function for displaying the matrix to the console
void adj_matrix::print_h(bool edges){
	//Display horizontal indices
	cout << "    ";
	for (int i = 1; i <= nodeCount; i++){
		cout << i;
		//FORMATTING: 3 spaces for 1 digit values, 2 spaces for 2 digit values.
		if (i < 10)
			cout << "   ";
		else
			cout << "  ";
	}
	cout << endl;

	//Display vertical indices and values within matrix
	for (int j = 0; j < nodeCount; j++){
		//FORMATTING: 3 spaces for 1 digit values, 2 spaces for 2 digit values.
		if (j < 9)
			cout << j + 1 << "   ";
		else
			cout << j + 1 << "  ";
		for (int k = 0; k < nodeCount; k++){
			//if we don't want to display 0's, insert space instead
			if ((edges == false) && (matrix[j][k] == 0))
				cout << " ";
			//otherwise, insert value of matrix[j][k] (0)
			else
				cout << matrix[j][k];
			//if we haven't reached the end of our line, print a gap to 
			//preceed the next value
			if (k + 1 != nodeCount)
				cout << "   ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
}

//Public function to check if graph is bipartite
//Finds first edge and calls helper function to determine bipartiteness
bool adj_matrix::is_bipartite(){
	//By definition, if a graph is bipartite, it cannot be directed
	if (directed)
		return false;
		
	//integers to hold edge end nodes
	int start = 0;
	int end = 0;

	//Find first edge in graph
	while ((matrix[start][end] == 0) && (start < nodeCount)){
		while ((matrix[start][end] == 0) && (end < nodeCount)){
			end++;
		}
		start++;
	}
	//Create array to hold groups
	int* groups = new int[nodeCount];
	
	//Populate array with -1 to represent an unassigned group
	for (int i = 0; i < nodeCount; i++)
		groups[i] = -1;
		
	return is_bipartite_h(start, groups);
}

//Private helper function for determining bipartedness
bool adj_matrix::is_bipartite_h(int start, int* groups[]){
	//create temporary integers for popping the front vertice from the queue and keeping track of what group we're using
	int temp;
	int currGroup;

	//Assign first node to first group
	groups[start] = 0;

	//Create a queue to add the vertices to as we connect edges to them
	queue <int> vertices;
	//Enqueue starting node
	vertices.push(start);

	//while the queue isn't empty, perform assignments 
	while (!vertices.empty()){
		//assign front node to temporary integer and remove from queue
		temp = vertices.front();
		vertices.pop();

		//find all ungrouped vertices with edges connecting to the vertice at the front of the queue
		for (int i = 0; i < nodeCount; i++){
			//determine if vertice is adjacent and has been grouped
			if ((matrix[temp][i] == 1) && (groups[i] == -1)){
				//figure out which group 'temp' is part of and assign the current vertice to be in the other
				if (groups[temp] == 1)
					groups[i] = 0;
				else
					groups[i] = 1;

				//push adjacent vertice onto queue
				vertices.push(i);
			}

			//Otherwise, if the vertice is adjacent and already assigned to a group, check to make sure the two adjacent vertices aren't part of the same group.   If they are, return false
			else if ((matrix[temp][i] == 1) && (groups[temp] == groups[i]))
				return false;
		}
	}
	//if the graph is bipartite so far(will be if we've gotten here) and there are any values that are still assigned -1, recall function with first index of groups that is still -1
	for(int i = 0; i < nodeCount; i++)
		if (groups[i] == -1)
			is_bipartite_h(i, groups);
			
	//Otherwise we've checked every node and the graph is bipartite
	return true;
}
