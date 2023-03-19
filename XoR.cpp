#include "XoR.h"

char XoR::twoValuesCalc(char a, char b)
{
	if (a == b) {
		return '0';
	}
	return '1';
}

char XoR::stringValueCalc(std::vector<char> vectInt)
{	
	char valueToReturn = vectInt.at(0);
	for (int i = 1; i < vectInt.size() - 1; i++) {
		valueToReturn = twoValuesCalc(valueToReturn, vectInt.at(i));
	}
	return valueToReturn;
}
