#pragma once
#include <iostream>
using namespace std;

enum DataType {
	NUMBER = 0x1,
	SYMBOL = 0x2,
	LETTER = 0x4,
	LWCASE = 0x8,
	UPCASE = 0x10,
	SPACE = 0x20
};

bool doesStringOnlyContain(const string& s, unsigned int DataType);


bool isInputValid(const string& s, const unsigned int targetLength);

bool  stringToCharArray(const string& source, char dest[], const unsigned int targetLength);



