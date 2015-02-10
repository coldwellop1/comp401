// Emily S. Rose
// Wheaton College Class of 2015
// Computer Science Senior Seminar
// February 2015
//
// CONTENTS:
// bipartite_graphs.cpp contains the main driver code for creating a graph on the console.  The program provides the user with the options of creating their own graph or importing one from a file.  The user is then able to add and delete edges between nodes, check for the existance of an edge, display the entire graph to the console, or display the graph by only showing the existing edges between nodes. 
//
// REQUIRED IMPORT FILE FORMAT: 
// Any file to be imported into this program as graph data must have the following format:
//	- The first line must include ONLY the number of nodes in the graph
//	- The second line must include either a 1 (Yes) or a 0 (No), representing 

#include "stdafx.h"
#include "adj_matrix.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
void menu(adj_matrix myGraph);

// variables we will need:
string userInput, line, choice;
int nodeCount, from, to, commaLoc, i;
bool direct;

void main(){
	// display menu to console
	cout << "Please select one of the following: " << endl;
	cout << "   (A) Create graph from scratch" << endl;
	cout << "   (B) Import graph from file" << endl;

	// get selection from user
	cin >> userInput;
	cout << endl << endl << endl;


	// Create Graph from Scratch
	if ((userInput == "a") || (userInput == "A")){
		cout << "Creating a graph from scratch" << endl;
		cout << "-----------------------------" << endl;

		// get nodeCount from user
		cout << "If you wish to display your graph on the console at any point, you will need to use 19 nodes or fewer.  How many nodes would you like your graph to have?" << endl;
		cin >> userInput;
		cout << endl;

		nodeCount = atoi(userInput.c_str());	// assign value to nodeCount variable

		// directed graph?
		cout << "Would you like this graph to be directed? (Y/N)" << endl;
		cin >> userInput;
		cout << endl;

		if ((userInput == "Y") || (userInput == "y"))
			direct = true;
		else
			direct = false;

		adj_matrix myGraph(nodeCount, direct);

		menu(myGraph);
	}

	// Import Graph from File
	else if ((userInput == "B") || (userInput == "b")){
		cout << "Importing a graph from file" << endl;
		cout << "---------------------------" << endl;

		// get file name from user
		cout << "Please enter the file name or path to the file: ";
		cin >> userInput;
		cout << endl;

		// open filestream
		fstream fin;
		i = 0;
		fin.open(userInput);
		if (fin.is_open()){
			while ((!fin.eof()) && (i < 2)){
				getline(fin, line);

				if (i == 0){
					nodeCount = atoi(line.c_str());
				}

				else{ //(i == 1)
					if (atoi(line.c_str()) == 1)
						direct = true;
					else
						direct = false;
				}
				i++;
			}

			adj_matrix myGraph(nodeCount, direct);
			while (!fin.eof()){
				getline(fin, line);
				if (line == ""){}	// skip blank lines

				else{
					commaLoc = line.find(",");
					from = atoi((line.substr(0, commaLoc)).c_str());	// convert first value to integer and store in 'from'
					to = atoi((line.substr(commaLoc + 2, line.length())).c_str());
					myGraph.addEdge(from, to);
				}
				i++;
			}
			cout << "Read successful." << endl;
			fin.close();
			menu(myGraph);
		}
		else{
			cout << "Cannot open file." << endl;
		}
	}

	else{
		main();
	}
}

void menu(adj_matrix myGraph){
	cout << endl << endl << endl;

	// display menu
	cout << "Please choose one of the following: " << endl;
	cout << "1. Create edge" << endl;
	cout << "2. Remove edge" << endl;
	cout << "3. Determine if there is an edge between two nodes" << endl;
	cout << "4. Display graph" << endl;
	cout << "5. Display graph (edges only)" << endl;
	//cout << "6. Export graph to file" << endl;
	cout << "0. Quit" << endl;
	cin >> userInput;
	cout << endl;

	//store userInput to 'choice'
	choice = userInput;

	if ((userInput == "1") || (userInput == "2") || (userInput == "3")){
		cout << "Please enter the number associated with the node at the start of the edge: ";
		cin >> userInput;
		cout << endl;
		from = atoi(userInput.c_str());

		cout << "Please enter the number associated with the node at the other end of the edge: ";
		cin >> userInput;
		cout << endl;
		to = atoi(userInput.c_str());
	}
	if (choice == "1")
		myGraph.addEdge(from, to);
	else if (choice == "2")
		myGraph.removeEdge(from, to);
	else if (choice == "3")
		myGraph.checkEdge(from, to);
	else if (choice == "4"){
		cout << "Your Graph" << endl;
		cout << "-------------------" << endl;
		myGraph.print(true);	//true: we do want zeros
		system("pause");
	}
	else if (choice == "5"){
		cout << "Your Graph" << endl;
		cout << "-------------------" << endl;
		myGraph.print(false);		//false: we don't want zeros
		system("pause");
	}
	else if (choice == "0"){
		myGraph.~myGraph();
		return;
	}

	menu(myGraph);
}
