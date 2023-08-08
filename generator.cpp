#include "generator.h"
#include "string_playground.h"
#include <cstdlib>
#include <random>
#include <cctype>
#include <iostream>

int* gen_sequence(const int intArrayP[2], int* totalElement) {

	int firstElement = intArrayP[0];
	while (firstElement <= intArrayP[1]) {
		(*totalElement)++;
		firstElement++;
	}

	int* numSequence = (int*)malloc(*totalElement * sizeof(int));

	int index = 0;
	firstElement = intArrayP[0];
	while (firstElement <= intArrayP[1]) {
		numSequence[index] = firstElement;
		index++;
		firstElement++;
	}

	return numSequence;
}

int* gen_sequence(const int intArrayP[][2], const int row, int* totalElement) {

	int rowCount = 0;
	while (rowCount < row) {
		int firstElement = intArrayP[rowCount][0];
		while (firstElement <= intArrayP[rowCount][1]) {
			(*totalElement)++;
			firstElement++;
		}
		rowCount++;
	}
	
	int* numSequence = (int*)malloc(*totalElement * sizeof(int));

	int index = 0;
	rowCount = 0;
	while (rowCount < row) {
		int firstElement = intArrayP[rowCount][0];
		while (firstElement <= intArrayP[rowCount][1]) {
			numSequence[index] = firstElement;
			index++;
			firstElement++;
		}
		rowCount++;
	}
	
	return numSequence;
}

char* ASCII_decTOchar(const int* intArrayP, const int arraySize) {
	char* ASCIIarray = (char*)malloc(arraySize + 1);
	int i = 0;
	while(i < arraySize) {
		ASCIIarray[i] = (char)intArrayP[i];
		i++;
	}
	ASCIIarray[i] = '\0';
	return ASCIIarray;
}


char* gen_set(const bool specialCharState, const bool numState, const bool upperState, const bool lowerState, int* initialLength) {
	int* specialDecimal = nullptr;
	int* numDecimal = nullptr;
	int* upperDecimal = nullptr;
	int* lowerDecimal = nullptr;

	char* specialASCII = nullptr;
	char* numASCII = nullptr;
	char* upperASCII = nullptr;
	char* lowerASCII = nullptr;

	char* fullset = nullptr;

	if (specialCharState == 1) {
		int totalElement = 0;
		//convert range array to decimal array
		specialDecimal = gen_sequence(specialCharRange, 4, &totalElement);

		//add totalElement to the fullset's length
		*initialLength += totalElement;
		//convert decimal to ASCII array
		specialASCII = ASCII_decTOchar(specialDecimal, totalElement);

		fullset = str_fuse(fullset, specialASCII);
	}
	if (numState == 1) {
		int totalElement = 0;
		numDecimal = gen_sequence(numRange, &totalElement);
		*initialLength += totalElement;
		numASCII = ASCII_decTOchar(numDecimal, totalElement);
		fullset = str_fuse(fullset, numASCII);
	}
	if (upperState == 1) {
		int totalElement = 0;
		upperDecimal = gen_sequence(upperRange, &totalElement);
		*initialLength += totalElement;
		upperASCII = ASCII_decTOchar(upperDecimal, totalElement);
		fullset = str_fuse(fullset, upperASCII);
	}
	if (lowerState == 1) {
		int totalElement = 0;
		lowerDecimal = gen_sequence(lowerRange, &totalElement);
		*initialLength += totalElement;
		lowerASCII = ASCII_decTOchar(lowerDecimal, totalElement);
		fullset = str_fuse(fullset, lowerASCII);
	}
	
	//Testing purposes
	/*char nullChar[1] = { '\0' };
	fullset = str_fuse(fullset, nullChar);
	str_display(fullset);
	std::cout << '\n';*/
	return fullset;
}

void generate(int pwLength, bool specialCharState, bool numState, bool upperState, bool lowerState, char* pwStorageP) {
	int setSize = 0;
	char* pw_set = gen_set(specialCharState, numState, upperState, lowerState, &setSize);

	using uint32 = uint_least32_t;
	using mtengine = std::mt19937;

	std::random_device seedgen;
	const uint32 seed = seedgen();

	mtengine randomEngine(seed);
	std::uniform_int_distribution<int> distribution(0, setSize);

	int i = 0;
	while(i < pwLength) {
		pwStorageP[i] = pw_set[distribution(randomEngine)];
		i++;
	}
	pwStorageP[i] = '\0';
}