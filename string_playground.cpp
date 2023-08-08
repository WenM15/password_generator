#include <cstdlib>
#include <iostream>

void str_display(const char* charArrayP) {
	int index = 0;
	while (charArrayP[index] != '\0') {
		std::cout << charArrayP[index];
		index++;
	}
}

int str_measure(const char* charArrayP) {
	int index = 0;
	while (charArrayP[index] != '\0') {
		index++;
	}
	return index;
}

bool str_clone(const char* sourceArrayP, char** targetArrayPP) {

	int strLength = str_measure(sourceArrayP);
	*targetArrayPP = (char*)malloc(strLength + 1); //+1 is for '\0'
	if (*targetArrayPP == nullptr) {
		return false;
	}

	int index = 0;
	while (sourceArrayP[index] != '\0') {
		(*targetArrayPP)[index] = sourceArrayP[index];
		++index;
	}
	(*targetArrayPP)[index] = '\0';
	return true;
}

char* str_fuse(const char* charArrayP1, const char* charArrayP2) {
	
	int firstLength = 0; 
	int secondLength = 0; 

	if (charArrayP1 != nullptr) {
		firstLength = str_measure(charArrayP1);
	}

	if (charArrayP2 != nullptr) {
		secondLength = str_measure(charArrayP2);
	}

	char* fusedArray = (char*)malloc(firstLength + secondLength + 1);

	int i = 0;
	int j = 0;
	while (j <= firstLength - 1) {
		fusedArray[i] = charArrayP1[j];
		i++;
		j++;
	}
	j = 0;
	while (j <= secondLength - 1) {
		fusedArray[i] = charArrayP2[j];
		i++;
		j++;
	}
	
	fusedArray[i] = '\0';
	return fusedArray;
}