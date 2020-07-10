/*
Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.

Date: 10/07/2020
Time: From 15h20 to 15h50
*/

#include "const.h"
#include <vector>
#define ARRAY_SIZE(array) sizeof(array)/sizeof(array[0])

std::vector<int> result;

void MaxFromSubArrays(int* arr, size_t size, int k, int startingIndex = 0)
{
	if (k > size)
	{
		std::cout << "Invalid subarray size" << std::endl;
	}
	
	int count = 0;
	int max = INT_MIN;

	while (count < k)
	{
		if (arr[startingIndex + count] > max)
			max = arr[startingIndex + count];

		++count;
	}

	result.push_back(max);
	if (++startingIndex <= size - k)
	{
		MaxFromSubArrays(arr, size, k, startingIndex);
	}
}

int main()
{
	int array1[] = { 10, 5, 2, 7, 8, 7 };
	int k = 3;

	MaxFromSubArrays(array1, ARRAY_SIZE(array1), k);

	std::cout << "The highets values from the subarrays of size " << k << " are: " << std::endl;
	for (size_t i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << ", ";
	}
}