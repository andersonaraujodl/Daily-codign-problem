/*
Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

You can modify the input array in-place.

Date: 10/06/2020
Time: from 23:30 to 23:50
*/

#include <vector>
#include <algorithm>
#include "const.h"

int FindMissingInt(std::vector<int> &vec)
{
	std::sort(vec.begin(), vec.end(), [](int& a, int& b) { return (a <= 0) ? (b < a) : (a < b); });

	int missing = 1;

	for(const auto &e : vec)
	{
		if (e == missing)
			++missing;
		else if (missing > 1)
			return missing;
	}

	return missing;
}

#ifdef _04_MissingInteger
int main()
{
	std::vector<int> caseTest1 = {3, 4, -1};
	std::vector<int> caseTest2 = { 1, 2, 0};
	std::vector<int> caseTest3 = { -1 };
	std::vector<int> caseTest4 = { 6, 2, 5, 4, 1, 3, 7 };
	std::vector<int> caseTest5 = { 6, 2, 5, 1, 3, 7 };

	std::cout << "First missing positive int is: " << FindMissingInt(caseTest1)  << std::endl;
	std::cout << "First missing positive int is: " << FindMissingInt(caseTest2) << std::endl;
	std::cout << "First missing positive int is: " << FindMissingInt(caseTest3) << std::endl;
	std::cout << "First missing positive int is: " << FindMissingInt(caseTest4) << std::endl;
	std::cout << "First missing positive int is: " << FindMissingInt(caseTest5) << std::endl;
}
#endif