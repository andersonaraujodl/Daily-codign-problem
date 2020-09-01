/*
#40 - Hard
This problem was asked by Google.

Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.

Time: from 18h20 to 18h40
*/

#include <vector>
#include "const.h"
#include <algorithm>

int FindSingleInteger(std::vector<int> values)
{
	if (values.size() == 1)
		return values[0];

	std::sort(values.begin(), values.end());

	for (size_t i = 0; i < values.size() - 1; i+=3)
	{
		if (i > 0 && values[i] == values[i - 1])
		{
			return INT_MAX; //array with error -> more then 3 in the sequence
		}

		if (values[i] != values[i + 1])
			return values[i];
	}

	return values[values.size() - 1];
}

//#ifdef _40_SinglInteger
int main()
{
	std::vector<int> v1 { 1 };
	std::vector<int> v2 { 6, 6, 3, 3, 3, 6, 9 };
	std::vector<int> v3 { 6, 6, 6, 3, 3, 3, 6, 9 };
	std::vector<int> v4 { 13, 19, 13, 13 };
	std::vector<int> v5 { 2, 1, 1, 1 };
	std::vector<int> v6 { 5, 9, 9, 9 };
	std::vector<int> v7{ 11, 9, 99, 3, 3, 3 };


	std::cout << "V1: " << FindSingleInteger(v1) << std::endl;
	std::cout << "V2: " << FindSingleInteger(v2) << std::endl;
	std::cout << "V3: " << FindSingleInteger(v3) << std::endl;
	std::cout << "V4: " << FindSingleInteger(v4) << std::endl;
	std::cout << "V5: " << FindSingleInteger(v5) << std::endl;
	std::cout << "V6: " << FindSingleInteger(v6) << std::endl;
	std::cout << "V7: " << FindSingleInteger(v7) << std::endl;

}
//#endif