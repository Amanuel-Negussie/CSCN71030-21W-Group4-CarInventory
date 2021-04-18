#include "Validation.h"

// returns the types stringContains 
unsigned int stringContains(const string& s){
	int strLen = (int)s.length();
	unsigned int stringContain = 0;
	for (int i = 0; i < strLen; i++)
	{
		if ((stringContain & NUMBER) == 0 && s[i] >= '0' && s[i] <= '9') {
			stringContain += NUMBER;
		}
		else if ((stringContain & SYMBOL) == 0 && s[i] == '&') {
			stringContain += SYMBOL;
		}
		else if ((stringContain & LETTER) == 0 && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')) {
			stringContain += LETTER;
		}
		else if ((stringContain & SPACE) == 0 && s[i] == ' ') {
			stringContain += SPACE;
		}
	}

	return stringContain;
}

//takes two DataType paramaters and checks if all required types as well as optional
bool doesStringContainOnlyAndOptional(const string& s, unsigned int DataTypeOnly, unsigned int DataTypeOptional)
{
	//SPACE, LETTER, NUMBER. ONLY: LETTER. OPTIONAL: SPACE 
	//need LETTER, AND don't need SPACE  = RANGE = ONLY + OPTIONAL 
	unsigned int stringContain = stringContains(s);
	unsigned int range = DataTypeOnly & DataTypeOptional; 
	//RANGE: NUMBER, LETTER        110
	//FLAG:  NUMBER, LETTER, SPACE 111
	//RESULT SHOULD BE FALSE, IT'S OUT OF RANGE
	//RESULT: IF USING & AND	   110
	//RESULT: IF USING | OR		   111
	//CHECK AGAINST RANGE 110
	//IF RANGE != RESULT
	//RESULT WITH & 110 != 110
	//RESULT WITH | 110 != 111
	//OUT OF RANGE, RETURN FALSE

	//checking if stringContain is out of Range 
	if ((range | stringContain) != range)
		return false;
	//if string Contains DataTypeOnly
	if ((DataTypeOnly & stringContain) == DataTypeOnly)
		return true;
	else
		return false; 

	//return (range | stringContain != range) && (DataTypeOnly & stringContain == DataTypeOnly);
}

//does string contain only the specific types mentioned in datatpye
bool doesStringContainOnly(const string& s, unsigned int DataType)
{
	unsigned int stringContain = stringContains(s);
	return !(stringContain ^ DataType);
}

//At least one of the type in the range exist
bool doesStringContainAnyOf(const string& s, unsigned int DataType)
{
	unsigned int stringContain = stringContains(s);			
	bool check1 = (stringContain & DataType); //Checks of at least one of the type
	bool check2 = (stringContain | DataType) == DataType;	//Check for if in range		
	return check1 && check2;
}

//return check1>FALSE;

//
bool isStringInRange(const string& s, unsigned int DataType){
	unsigned int stringContain = stringContains(s);	
	return (stringContain | DataType) == stringContain;
}


bool isAgeValid(int age)
{
	return (age >= VALID_MIN_AGE && age < VALID_MAX_AGE);
}


bool  stringToCharArray(const string& source, char dest[], const unsigned int targetLength)
{

	if (!isInputValid(source, targetLength))
		return false;
	return (!strcpy_s(dest, targetLength, source.c_str()));

}

bool isInputValid(const string& s, const unsigned int targetLength)
{
	return (s.length() < targetLength);
}