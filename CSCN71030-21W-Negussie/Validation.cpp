#include "Validation.h"

bool doesStringOnlyContain(const string& s, unsigned int DataType)
{
	int strLen = (int)s.length();
	unsigned int stringContains = 0;
	for (int i = 0; i < strLen; i++)
	{
		if ((stringContains & NUMBER) == 0 && s[i] >= '0' && s[i] <= '9') {
			stringContains += NUMBER;
		}
		else if ((stringContains & SYMBOL) == 0 && s[i] == '&') {
			stringContains += SYMBOL;
		}
		else if ((stringContains & LETTER) == 0 && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')) {
			stringContains += LETTER;
		}
		else if ((stringContains & SPACE) == 0 && s[i] == ' ') {
			stringContains += SPACE;
		}

	}
	return !(stringContains ^ DataType);
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