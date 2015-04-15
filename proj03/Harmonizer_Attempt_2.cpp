// Harmonizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "scale.h"

using namespace std;

void thirdMenu(scale ourScale);

string user_input_1, user_input_2, user_input_3, user_input_4;
int type, choice;	// 1 if Major, 2 if Natural Minor
string root;

void main(){
	//Print title to console
	cout << "The Harmonizer" << endl
		<< "==============" << endl;

	//First Menu -- Major or Natural Minor Scale?
	cout << "Please select a type of scale to work with: " << endl
		<< "	1. Major" << endl
		<< "	2. Natural Minor" << endl
		<< "	3. Harmonic Minor" << endl;

	cin >> user_input_1;
	cout << endl << endl << endl;

	type = stoi(user_input_1);

	if ((type != 1) && (type != 2) && (type != 3)){
		cout << "I don't understand.  Let's try again..." << endl;
		main();
	}

	//Second Menu -- What is the root?
	cout << "Select the root of the scale: " << endl
		<< "	1. C				7. F# " << endl
		<< "	2. G				8. F " << endl
		<< "	3. D				9. Bb " << endl
		<< "	4. A				10. Eb " << endl
		<< "	5. E				11. Ab " << endl
		<< "	6. B				12. Db" << endl
		<< "	**Please Note: Ab and Db do not have minor scales" << endl;

	cin >> user_input_2;
	cout << endl << endl << endl;

	choice = stoi(user_input_2);
	
	switch (choice) {
		case 1: 
			root = "C";
			break;
		case 2: 
			root = "G";
			break;
		case 3: 
			root = "D";
			break;
		case 4: 
			root = "A";
			break;
		case 5: 
			root = "E";
			break;
		case 6: 
			root = "B";
			break;
		case 7: 
			root = "F#";
			break;
		case 8: 
			root = "F";
			break;
		case 9: 
			root = "Bb";
			break;
		case 10: 
			root = "Eb";
			break;
		case 11: 
			root = "Ab";
			break;
		case 12: 
			root = "Db";
			break;
	}

	scale ourScale(type, root);

	thirdMenu(ourScale);
	system("PAUSE");
}

void thirdMenu(scale ourScale){
	//Third Menu -- What's next?
	cout << "What's Next?" << endl;
	cout << "	1. Display the scale's chords" << endl;
	cout << "	2. Print the scale's notes" << endl;
	cout << "	3. Create a harmony in this key" << endl;
	cout << "	4. " << endl;
	cout << "	5. " << endl;
	cout << "	6. Quit" << endl;
	cin >> user_input_3;
	cout << endl;

	choice = stoi(user_input_3);

	switch (choice){
	case 1:
		ourScale.display_chords();
		thirdMenu(ourScale);
		break;
	case 2:
		ourScale.print_scale();
		thirdMenu(ourScale);
		break;
	case 3:
		cout << "We will write a tight harmony to go along with the notes you enter.  This means we will create a harmony line that is made up of notes that are 3rds and 6ths away from the melodic note." << endl;
		ourScale.tight_harmony();
		thirdMenu(ourScale);
		break;
	case 4:
		thirdMenu(ourScale);
		break;
	case 5:
		thirdMenu(ourScale);
		break;
	case 6: 
		return;
	}
}