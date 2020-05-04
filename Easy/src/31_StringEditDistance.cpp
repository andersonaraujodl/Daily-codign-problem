/*
The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.

Date: 04/05/2020
Time: From 18:22 to 19:01 = 39min (considering all lowercase or uppercase)
*/

#include <iostream>
#include <string>
#include "const.h"

int CalculateEditDistance(std::string a, std::string b)
{
	//Assuming they will be all lowercase or all uppercase

	int aSize = a.length();
	int bSize = b.length();

	if (aSize == 0)
		return bSize;

	if (bSize == 0)
		return aSize;

	//Check if one contains the other
	if (a.find(b) != std::string::npos || b.find(a) != std::string::npos)
		return abs(aSize - bSize);

	int smaller = (aSize > bSize) ? bSize : aSize;

	int editDistance = 0;

	for (int i = 0; i < smaller; ++i)
	{
		//Doesn't matter if you are gonna move or change the letter, it counts the same way
		if (a[i] != b[i])
			++editDistance;
	}

	editDistance += abs(aSize - bSize);

	return editDistance;
}
#ifdef _31_StringEditDistance
int main()
{
	std::string a = "kitten";
	std::string b = "sitting";

	std::string c = "";
	std::string d = "sitting";

	std::string e = "fac";
	std::string f = "art";

	std::string g = "winter";
	std::string h = "summer";

	std::string i = "act";
	std::string j = "fact";

	std::cout << CalculateEditDistance(a, b) << std::endl;
	std::cout << CalculateEditDistance(c, d) << std::endl;
	std::cout << CalculateEditDistance(e, f) << std::endl;
	std::cout << CalculateEditDistance(g, h) << std::endl;
	std::cout << CalculateEditDistance(i, j) << std::endl;

	return 0;
}
#endif