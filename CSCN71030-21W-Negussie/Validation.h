#pragma once
#include <iostream>
using namespace std;

#define VALID_MAX_AGE 110
#define VALID_MIN_AGE 18

enum DataType {
	NONE = 0x0,
	NUMBER = 0x1,
	SYMBOL = 0x2,
	LETTER = 0x4,
	LWCASE = 0x8,
	UPCASE = 0x10,
	SPACE = 0x20
};

unsigned int stringContains(const string& s);

bool doesStringContainOnlyAndOptional(const string& s, unsigned int DataTypeOnly, unsigned int DataTypeOptional);

bool doesStringContainOnly(const string& s, unsigned int DataType);

bool doesStringContainAnyOf(const string& s, unsigned int DataType);

bool isStringInRange(const string& s, unsigned int DataType);

bool isInputValid(const string& s, const unsigned int targetLength);

bool isAgeValid(int age);

bool  stringToCharArray(const string& source, char dest[], const unsigned int targetLength);
