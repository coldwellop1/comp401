#include "stdafx.h"
#include "scale.h"


scale::~scale()
{
}

scale::scale(int scale_type, string root)
{
	//Assign root
	this->root = root;

	//Assign scale type
	if (scale_type == 1)
		scaleType = MAJOR;
	else if (scale_type == 2)
		scaleType = NATURAL_MINOR;
	else if (scale_type == 3)
		scaleType = HARMONIC_MINOR;

	init_scale();
}

void scale::init_scale(){
	if (scaleType == MAJOR){
		//find the root in the arrays of notes
		if (root == "C")
			pop_sh_Maj_scale();
		for (int i = 0; i < 7; i++){
			if (sharp_major_keys[i] == root)
				pop_sh_Maj_scale();
			else if (flat_major_keys[i] == root)
				pop_fl_Maj_scale();
		}
	}
	if ((scaleType == NATURAL_MINOR) || (scaleType == HARMONIC_MINOR)){
		//find the root in the ordered array of notes
		for (int i = 0; i < 6; i++){
			if (sharp_natural_minor_keys[i] == root)
				pop_sh_Min_scale();
			else if (flat_natural_minor_keys[i] == root)
				pop_fl_Min_scale();
		}
	}
}

void scale::pop_sh_Maj_scale(){
	//find root in ordered array of chromatic notes
	int i = 0;
	while ((i < 12) && (sharp_octave[i-1] != root)){
		if (sharp_octave[i] == root){
			//assign notes to steps of scale.  MOD 12 TO STAY WITHIN ARRAY.
			second = sharp_octave[(i + 2) % 12];	//2nd == 2 halfsteps above root
			third = sharp_octave[(i + 4) % 12];		//3rd == 4 halfsteps above root
			fourth = sharp_octave[(i + 5) % 12];	//4th == 5 halfsteps above root
			fifth = sharp_octave[(i + 7) % 12];		//5th == 7 halfsteps above root
			sixth = sharp_octave[(i + 9) % 12];		//6th == 9 halfsteps above root
			seventh = sharp_octave[(i + 11) % 12];	//7th == 11 halfsteps above root
		}
		i++;
	}

}

void scale::pop_fl_Maj_scale(){
	//find root in ordered array of chromatic notes
	int i = 0;
	while ((i < 12) && (flat_octave[i - 1] != root)){
		if (flat_octave[i] == root){
			//assign notes to steps of scale.  MOD 12 TO STAY WITHIN ARRAY.
			second = flat_octave[(i + 2) % 12];	//2nd == 2 halfsteps above root
			third = flat_octave[(i + 4) % 12];		//3rd == 4 halfsteps above root
			fourth = flat_octave[(i + 5) % 12];	//4th == 5 halfsteps above root
			fifth = flat_octave[(i + 7) % 12];		//5th == 7 halfsteps above root
			sixth = flat_octave[(i + 9) % 12];		//6th == 9 halfsteps above root
			seventh = flat_octave[(i + 11) % 12];	//7th == 11 halfsteps above root
		}
		i++;
	}

}

void scale::pop_sh_Min_scale(){

	//find root in ordered array of chromatic notes
	int i = 0;
	while ((i < 12) && (sharp_octave[i - 1] != root)){
		if (sharp_octave[i] == root){
			//assign notes to steps of scale.  MOD 12 TO STAY WITHIN ARRAY.
			second = sharp_octave[(i + 2) % 12];	//2nd == 2 halfsteps above root
			third = sharp_octave[(i + 3) % 12];		//3rd == 3 halfsteps above root
			fourth = sharp_octave[(i + 5) % 12];	//4th == 5 halfsteps above root
			fifth = sharp_octave[(i + 7) % 12];		//5th == 7 halfsteps above root
			sixth = sharp_octave[(i + 8) % 12];		//6th == 8 halfsteps above root
			if (scaleType == NATURAL_MINOR)
				seventh = sharp_octave[(i + 10) % 12];	//7th == 10 halfsteps above root
			else //(scaleType == HARMONIC_MINOR
				seventh = sharp_octave[(i + 11) % 12];	//7th == 11 halfsteps above root
		}
		i++;
	}
}

void scale::pop_fl_Min_scale(){
	//find root in ordered array of chromatic notes
	int i = 0;
	while ((i < 12) && (flat_octave[i - 1] != root)){
		if (flat_octave[i] == root){
			//assign notes to steps of scale.  MOD 12 TO STAY WITHIN ARRAY.
			second = flat_octave[(i + 2) % 12];		//2nd == 2 halfsteps above root
			third = flat_octave[(i + 3) % 12];		//3rd == 3 halfsteps above root
			fourth = flat_octave[(i + 5) % 12];		//4th == 5 halfsteps above root
			fifth = flat_octave[(i + 7) % 12];		//5th == 7 halfsteps above root
			sixth = flat_octave[(i + 8) % 12];		//6th == 8 halfsteps above root
			if (scaleType == NATURAL_MINOR)
				seventh = flat_octave[(i + 10) % 12];	//7th == 10 halfsteps above root
			else //(scaleType == HARMONIC_MINOR
				seventh = flat_octave[(i + 11) % 12];	//7th == 11 halfsteps above root
		}
		i++;
	}

}

void scale::print_scale(){
	print_scale_h();
}
void scale::print_scale_h(){

	cout << root << " ";
	if (scaleType == MAJOR)
		cout << "MAJOR SCALE:  ";
	else if (scaleType == NATURAL_MINOR)
		cout << "NATURAL MINOR SCALE:  ";
	else if (scaleType == HARMONIC_MINOR)
		cout << "HARMONIC MINOR SCALE:  ";
	cout << 
	"  " << root << "  " << second << "  " << third <<
	"  " << fourth << "  " << fifth << "  " << sixth <<
	"  " << seventh << endl << endl;
}

void scale::display_chords(){
	if (scaleType == MAJOR){
		cout << root << " DIATONIC TRAIDS: " << endl;
		cout << "I:	" << root << ":	" << root << "	" << third << "	" << fifth << endl << endl;
		cout << "ii:	" << second << "m:	" << second << "	" << fourth << "	" << sixth << endl << endl;
		cout << "iii:	" << third << "m:	" << third << "	" << fifth << "	" << seventh << endl << endl;
		cout << "IV:	" << fourth << ":	" << fourth << "	" << sixth << "	" << root << endl << endl;
		cout << "V:	" << fifth << ":	" << fifth << "	" << seventh << "	" << second << endl << endl;
		cout << "vi:	" << sixth << "m:	" << sixth << "	" << root << "	" << third << endl << endl;
		cout << "vii*:	" << seventh << "dim:	" << seventh << "	" << second << "	" << fourth << endl << endl;
	}
	if (scaleType == NATURAL_MINOR){
		cout << root << " DIATONIC TRAIDS: " << endl;
		cout << "i:	" << root << "m:	" << root << "	" << third << "	" << fifth << endl << endl;
		cout << "ii*:	" << second << "dim:	" << second << "	" << fourth << "	" << sixth << endl << endl;
		cout << "III:	" << third << ":	" << third << "	" << fifth << "	" << seventh << endl << endl;
		cout << "iv:	" << fourth << "m:	" << fourth << "	" << sixth << "	" << root << endl << endl;
		cout << "v:	" << fifth << "m:	" << fifth << "	" << seventh << "	" << second << endl << endl;
		cout << "VI:	" << sixth << ":	" << sixth << "	" << root << "	" << third << endl << endl;
		cout << "VII:	" << seventh << ":	" << seventh << "	" << second << "	" << fourth << endl << endl;
	}
	if (scaleType == HARMONIC_MINOR){
		cout << root << " DIATONIC TRAIDS: " << endl;
		cout << "i:	" << root << "m:	" << root << "	" << third << "	" << fifth << endl << endl;
		cout << "ii*:	" << second << "dim:	" << second << "	" << fourth << "	" << sixth << endl << endl;
		cout << "III:	" << third << ":	" << third << "	" << fifth << "	" << seventh << endl << endl;
		cout << "iv:	" << fourth << "m:	" << fourth << "	" << sixth << "	" << root << endl << endl;
		cout << "v:	" << fifth << "m:	" << fifth << "	" << seventh << "	" << second << endl << endl;
		cout << "VI:	" << sixth << ":	" << sixth << "	" << root << "	" << third << endl << endl;
		cout << "vvi*:	" << seventh << ":	" << seventh << "	" << second << "	" << fourth << endl << endl;
	}
}

void scale::tight_harmony(){
	cout << "Tight Harmony - enter 0 at any time to quit." << endl << "You may now enter your melody." << endl;

	//assign random values that don't represent any real notes.
	last = 0;
	tight_harmony_h();
}

void scale::tight_harmony_h(){
	cin >> now;
	//need to keep track of previous 2 notes and pick the 3rd or 6th that is closest to the most recent note.
	if (now == "0")
		return;
	if (now == root){
		_now = 1;
		opt_1 = third;	// a third up
		_opt_1 = 3;
		opt_2 = sixth;	// a sixth up
		_opt_2 = 6;
		opt_3 = fifth;	// a third down
		_opt_3 = 5;
		opt_4 = second;	// a sixth down
		_opt_4 = 2;
	}
	if (now == second){
		_now = 2;
		opt_1 = fourth;	// a third up
		_opt_1 = 4;
		opt_2 = seventh;	// a sixth up
		_opt_2 = 7;
		opt_3 = sixth;	// a third down
		_opt_3 = 6;
		opt_4 = third;	// a sixth down
		_opt_4 = 3;
	}
	if (now == third){
		_now = 3;
		opt_1 = fifth;	// a third up
		_opt_1 = 5;
		opt_2 = root;	// a sixth up
		_opt_2 = 1;
		opt_3 = seventh;	// a third down
		_opt_3 = 7;
		opt_4 = fourth;	// a sixth down
		_opt_4 = 4;
	}
	if (now == fourth){
		_now = 4;
		opt_1 = sixth;	// a third up
		_opt_1 = 6;
		opt_2 = second;	// a sixth up
		_opt_2 = 2;
		opt_3 = root;	// a third down
		_opt_3 = 1;
		opt_4 = fifth;	// a sixth down
		_opt_4 = 5;
	}
	if (now == fifth){
		_now = 5;
		opt_1 = seventh;	// a third up
		_opt_1 = 7;
		opt_2 = third;	// a sixth up
		_opt_2 = 3;
		opt_3 = second;	// a third down
		_opt_3 = 2;
		opt_4 = sixth;	// a sixth down
		_opt_4 = 6;
	}
	if (now == sixth){
		_now = 6;
		opt_1 = root;	// a third up
		_opt_1 = 1;
		opt_2 = fourth;	// a sixth up
		_opt_2 = 4;
		opt_3 = third;	// a third down
		_opt_3 = 3;
		opt_4 = seventh;	// a sixth down
		_opt_4 = 7;
	}
	if (now == seventh){
		_now = 7;
		opt_1 = second;	// a third up
		_opt_1 = 2;
		opt_2 = fifth;	// a sixth up
		_opt_2 = 5;
		opt_3 = fourth;	// a third down
		_opt_3 = 4;
		opt_4 = root;	// a sixth down
		_opt_4 = 1;
	}

	find_closest();
	last = _now;
	tight_harmony_h();
}

void scale::find_closest(){
	int dif1 = abs(last - _opt_1);
	int dif2 = abs(last - _opt_2);
	int dif3 = abs(last - _opt_3);
	int dif4 = abs(last - _opt_4);
	int smallest = dif1;	//start with 1
	string closest = opt_1;

	if (dif2 < smallest){
		smallest = dif2;
		closest = opt_2;
	}
	if (dif3 < smallest){
		smallest = dif3;
		closest = opt_3;
	}
	if (dif4 < smallest){
		smallest = dif4;
		closest = opt_4;
	}
	cout << "-----" << " " << closest << endl << endl;

}
/*
void scale::chordal_harmony(){
	cout << "Chordal Harmony - enter 0 at any time to quit." << endl << "You may now enter your melody." << endl;
	
	chordal_harmony_h();
}

void scale::chordal_harmony_h(){
	chordal_harmony_h();
}
*/