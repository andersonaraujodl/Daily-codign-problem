/*
02 - HARD

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], the expected output would be[2, 3, 6].

Follow - up: what if you can't use division?

Date: 08/06/2020
Time: from 19h26 to 19h52 //with division
from 19h56 to 
*/

#include <algorithm>
#include "const.h"

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

void ProductArrayWithDivision(int * arr, int size)
{
	if (size == 1)
		std::cout << "The output array is: 0" << std::endl;

	int product = 1;

	for (int i = 0; i < size; ++i)
		product *= arr[i];

	int* productArr = new int[size];

	//Add result to temp Array
	for (int i = 0; i < size; ++i)
		productArr[i] = product/arr[i];

	//Print result
	for (int i = 0; i < size; ++i)
		std::cout << productArr[i] << std::endl;
}

void ProductArrayWithoutDivision(int* arr, int size)
{
	//TODO
}

#ifdef _02_ArrayOfProducts
int main()
{
	int firstTest[] = { 1, 2, 3, 4, 5 };
	int secondTest[] = { 3, 2, 1 };

	ProductArrayWithDivision(firstTest, ARRAY_SIZE(firstTest));

	ProductArrayWithDivision(secondTest, ARRAY_SIZE(secondTest));
}
#endif