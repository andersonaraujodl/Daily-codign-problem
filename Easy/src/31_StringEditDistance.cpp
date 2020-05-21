/*
The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.

Date: 04/05/2020
Time: From 18:22 to 19:01 = 39min (considering all lowercase or uppercase)
*/

#include <string>
#include "const.h"

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int minimum(int a, int b, int c) {
	return min(min(a, b), c);
}

int CalculateEditDistance(std::string a, int aSize, std::string b, int bSize)
{
	//Assuming they will be all lowercase or all uppercase
	int cost = 0;

	if (aSize == 0)
		return bSize;

	if (bSize == 0)
		return aSize;

	//Check if one contains the other
	if (a.find(b) != std::string::npos || b.find(a) != std::string::npos)
		return abs(aSize - bSize);

	int smaller = (aSize > bSize) ? bSize : aSize;

	//After learning about the levenshtein algorithim, that's the opmized solution:
	/* test if last characters of the strings match */
	if (a[aSize - 1] == b[bSize- 1])
		cost = 0;
	else
		cost = 1;

	/* return minimum of delete char from s, delete char from t, and delete char from both */
	return minimum(CalculateEditDistance(a, aSize - 1, b, bSize) + 1,
		CalculateEditDistance(a, aSize, b, bSize - 1) + 1,
		CalculateEditDistance(a, aSize - 1, b, bSize - 1) + cost);
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

	std::string g = "lastwinter";
	std::string h = "summer";

	std::string i = "act";
	std::string j = "fact";

	std::string k = "keep";
	std::string l = "sweeper";

	std::cout << CalculateEditDistance(a, a.length(), b, b.length()) << std::endl;
	std::cout << CalculateEditDistance(c, c.length(), d, d.length()) << std::endl;
	std::cout << CalculateEditDistance(e, e.length(), f, f.length()) << std::endl;
	std::cout << CalculateEditDistance(g, g.length(), h, h.length()) << std::endl;
	std::cout << CalculateEditDistance(i, i.length(), j, j.length()) << std::endl;
	std::cout << CalculateEditDistance(k, k.length(), l, l.length()) << std::endl;

	return 0;
}
#endif