#include <string>

using namespace std;

//framework arrays for building scales
//chromatic octave using sharps
const string sharp_octave[12] = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
//chromatic octave using flats
const string flat_octave[12] = { "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B" };

//to find scale_composition
const string sharp_major_keys[7] = { "G", "D", "A", "E", "B", "F#", "C#" };
const string flat_major_keys[7] = { "Cb", "Gb", "Db", "Ab", "Eb", "Bb", "F" };
const string sharp_natural_minor_keys[6] = { "A", "E", "B", "F", "C#", "G#" };
const string flat_natural_minor_keys[6] = { "D", "G", "C", "F", "Bb", "Eb" };