/*
Problem Description:

Given a list of numbersand a number k, return whether any two numbers from the list add up to k.
For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass ?

Date: 07/04
Time spent: From 22h10 to 22h22
*/

#include <list>
#include <iostream>

bool hasSum(std::list<int> myList, int k)
{
	for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
	{
		if ((std::find(myList.begin(), myList.end(), k - *it) != myList.end())) return true;
	}

	return false;
}

int main()
{
	std::list<int> myList = { 11, 15, 7, 3 };
	int k = 17;

	std::cout << hasSum(myList, k) << std::endl;
	return 0;
}