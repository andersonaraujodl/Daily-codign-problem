/*
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

Date: 20/07/2020
Time: 18:15 to 19h (45 minutes T_T But hey! It was with bug fixes)
*/

#include "const.h"

#define SIZE_ARRAY(array) (sizeof(array)/sizeof(array[0]))

void SortSequence(char* arr, size_t size)
{
	if (size <= 1)
		return;

	int begin = 0;
	int end = size - 1;

	while (arr[begin] == 'R')
	{
		++begin;
	}

	int i = begin;

	while (arr[end] == 'B')
	{
		--end;
	}

	char holder;
	while (i <= end)
	{
		if (arr[i] == 'R')
		{
			holder = arr[begin];
			arr[begin] = arr[i];
			arr[i] = holder;
			++begin;
			++i;
		}
		else if (arr[i] == 'B')
		{
			holder = arr[end];
			arr[end] = arr[i];
			arr[i] = holder;
			--end;
		}
		else
		{
			++i;
		}
	}
}

#ifdef _35_SortRGB
int main()
{
	char a[] = { 'G', 'B', 'R', 'R', 'B', 'R', 'G' };

	SortSequence(a, SIZE_ARRAY(a));

	for (size_t i = 0; i < SIZE_ARRAY(a); ++i)
		std::cout << a[i] << ", ";

	std::cout << std::endl;

	char b[] = { 'B', 'B', 'G', 'R', 'B', 'R', 'G', 'B', 'G', 'B', 'R', 'B' };

	SortSequence(b, SIZE_ARRAY(b));

	for (size_t i = 0; i < SIZE_ARRAY(b); ++i)
		std::cout << b[i] << ", ";

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}
#endif