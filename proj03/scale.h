#include <string>
#include "scale_library.h"
#include <iostream>
#pragma once

using namespace std;

class scale
{
public:
	scale(int scale_type, string root);
	~scale();

	// calls helper function print_scale_h
	void print_scale();
	void display_chords();
	void tight_harmony();
	void chordal_harmony();

private:
	enum SCALE_TYPE{
		MAJOR,
		NATURAL_MINOR,
		HARMONIC_MINOR
	};

	SCALE_TYPE scaleType;
	string root;
	string second;
	string third;
	string fourth;
	string fifth;
	string sixth;
	string seventh;

	//variables for holding the current melody note and the previous 2 harmony notes.
	string now;
	int _now;
	int last;
	int _last;

	//there will be 4 options for the harmony to each note
	string opt_1, opt_2, opt_3, opt_4;
	int _opt_1, _opt_2, _opt_3, _opt_4;

	//calls required functions to populate the scale
	void init_scale();

	//populate scales (sh if scale will have sharps, fl if scale will have flats)
	void pop_sh_Maj_scale();
	void pop_fl_Maj_scale();
	void pop_sh_Min_scale();
	void pop_fl_Min_scale();

	//print helper function
	void print_scale_h();

	//harmony helper functions
	void tight_harmony_h();
	void chordal_harmony_h();

	//find closest harmonic tone for tight harmony
	void find_closest();
};

