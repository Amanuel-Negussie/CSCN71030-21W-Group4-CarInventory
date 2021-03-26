#include "Validation.h"

bool doesStringOnlyContain(const string& s, unsigned int DataType)
{
	int strLen = s.length();
	unsigned int stringContains = 0;
	for (int i = 0; i < strLen; i++)
	{
		if ((stringContains & NUMBER) == 0 && s[i] >= '0' && s[i] <= '9') {
			stringContains += NUMBER;
		}
		else if ((stringContains & SYMBOL) == 0) {
			stringContains += SYMBOL;
		}
		else if ((stringContains & LETTER) == 0) {
			stringContains += LETTER;
		}
		else if ((stringContains & SPACE) == 0) {
			stringContains += SPACE;
		}

	}
	return stringContains & DataType;
}