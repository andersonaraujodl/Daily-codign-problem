/*
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].

Date: 20/07/2020
Time: 18:15 to 
*/

#include "const.h"

#define SIZE_ARRAY(array) (sizeof(array)/sizeof(array[0]))

void SortSequence(char *arr, size_t size)
{
	int begin = 0;
	int end = size - 1;

	for (int i = 0; i < end; ++i)
	{
		if (arr[i] == 'R')
		{
			char holder = arr[begin];
			arr[begin] = arr[i];
			arr[i] = holder;
			++begin;
		}
		else if (arr[i] == 'B')
		{
			char holder = arr[end];
			arr[end] = arr[i];
			arr[i] = holder;
			--end;
		}
	}
}

int main()
{
	char a[] = { 'G', 'B', 'R', 'R', 'B', 'R', 'G' };

	SortSequence(a, SIZE_ARRAY(a));

	for (size_t i = 0; i < SIZE_ARRAY(a); ++i)
		std::cout << a[i] << ", ";
}