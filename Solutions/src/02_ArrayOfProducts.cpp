/*
02 - HARD

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], the expected output would be[2, 3, 6].

Follow - up: what if you can't use division?

Date: 08/06/2020
Time: from 19h26 to 19h52 //with division
from 20h55 to 20h20 //without division, after reading someone's guidance online
*/

#include <algorithm>
#include "const.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

void ProductArrayWithDivision(int * arr, int * result, int size)
{
	if (size == 1)
		std::cout << "The output array is: 0" << std::endl;

	int product = 1;

	for (int i = 0; i < size; ++i)
		product *= arr[i];

	//Add result to result Array
	for (int i = 0; i < size; ++i)
		result[i] = product /arr[i];

}

void ProductArrayWithoutDivision(int* arr, int* result, int size)
{
	int* ascendingArr = new int[size];

	int product = 1;
	for (int i = 0; i < size; ++i)
	{
		ascendingArr[i] = product;
		product *= arr[i];
	}

	int* descendingArr = new int[size];

	product = 1;
	for (int i = size-1; i >= 0; --i)
	{
		descendingArr[i] = product;
		product *= arr[i];
	}

	for (int i = 0; i < size; ++i)
	{
		result[i] = ascendingArr[i] * descendingArr[i];
	}
}

void printArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << ",";
	}

	std::cout << std::endl;
}

#ifdef _02_ArrayOfProducts
int main()
{
	int firstTest[] = { 1, 2, 3, 4, 5 };
	int secondTest[] = { 3, 2, 1 };

	int* resultArray1 = new int[ARRAY_SIZE(firstTest)];
	int* resultArray2 = new int[ARRAY_SIZE(secondTest)];

	std::cout << "With Division: " << std::endl;
	ProductArrayWithDivision(firstTest, resultArray1, ARRAY_SIZE(firstTest));
	printArray(resultArray1, ARRAY_SIZE(firstTest));

	ProductArrayWithDivision(secondTest, resultArray2, ARRAY_SIZE(secondTest));
	printArray(resultArray2, ARRAY_SIZE(secondTest));

	std::cout << std::endl << "Without Division: " << std::endl;
	ProductArrayWithoutDivision(firstTest, resultArray1, ARRAY_SIZE(firstTest));
	printArray(resultArray1, ARRAY_SIZE(firstTest));

	std::cout << std::endl;

	ProductArrayWithoutDivision(secondTest, resultArray2, ARRAY_SIZE(secondTest));
	printArray(resultArray2, ARRAY_SIZE(secondTest));
}
#endif