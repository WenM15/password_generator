#include "password_condition.h"
#include <cstdlib>
#include <iostream>
#include "string_playground.h"
using namespace std;

void setPwLength(int pwLength, char** pwStoragePP) {
	free(*pwStoragePP);
	*pwStoragePP = (char*)malloc(pwLength + 1);
}

void specialCharToggle(bool* specialCharState) {
	if (*specialCharState == true) {
		*specialCharState = false;
	}
	else {
		*specialCharState = true;
	}
}

void numToggle(bool* numState) {
	if (*numState == true) {
		*numState = false;
	}
	else {
		*numState = true;
	}
}

void uppercaseToggle(bool* upperState) {
	if (*upperState == true) {
		*upperState = false;
	}
	else {
		*upperState = true;
	}
}

void lowercaseToggle(bool* lowerState) {
	if (*lowerState == true) {
		*lowerState = false;
	}
	else {
		*lowerState = true;
	}
}

void displayToggle(bool specialCharState, bool numState, bool upperState, bool lowerState) {
	bool stateArray[4] = { specialCharState, numState, upperState, lowerState };
	
	//One iteration = One line of display
	for (int i = 0; i <= 3; i++) {
		char* attributeString = nullptr;
		char specialCharString[19] = "Special characters";
		char numString[8] = "Numbers";
		char upperString[18] = "Uppercase letters";
		char lowerString[18] = "Lowercase letters";

		if (i == 0) {
			while (!str_clone(specialCharString, &attributeString));
		}
		else if (i == 1) {
			while (!str_clone(numString, &attributeString));
		}
		else if (i == 2){
			while (!str_clone(upperString, &attributeString));
		}
		else {
			while (!str_clone(lowerString, &attributeString));
		}

		char* stateString = nullptr;
		char trueState[8] = "enabled";
		char falseState[9] = "disabled";
		
		if (stateArray[i] == 1) {
			while (!str_clone(trueState, &stateString));
		}
		else {
			while (!str_clone(falseState, &stateString));
		}

		int j = 0;
		while (attributeString[j] != '\0') {
			cout << attributeString[j];
			j++;
		}
		cout << " ";
		j = 0;
		while (stateString[j] != '\0') {
			cout << stateString[j];
			j++;
		}
		cout << "\n";
		free(attributeString);
		free(stateString);
	}
	cout << "\n";
}