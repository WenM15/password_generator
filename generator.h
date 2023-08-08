#ifndef generator
#define generator
const int specialCharRange[4][2] = {
		{33,47},
		{58,64},
		{91,96},
		{123,126}
};
const int numRange[2] = { 48,57 };
const int upperRange[2] = { 65,90 };
const int lowerRange[2] = { 97,122 };
int* gen_sequence(const int intArrayP[2], int*);
int* gen_sequence(const int intArrayP[][2], const int, int*);
char* ASCII_decTOchar(const int*, const int);
char* gen_set(const bool, const bool, const bool, const bool, int*);
void generate(int, bool, bool, bool, bool, char*);

#endif