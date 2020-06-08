/*
01 - EASY

Given a list of numbersand a number k, return whether any two numbers from the list add up to k.
For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass ?

Date: 07/04
Time spent: 15min with bonus - after I realized what they meant with "one pass" (assuming it is in one loop interaction throught the list)
*/

#include <list>
#include "const.h"

bool hasSum(const std::list<int>* myList, int k)
{
	if (myList->empty()) return false;

	for (std::list<int>::const_iterator it = myList->begin(); it != myList->end(); ++it)
		if ((std::find(myList->begin(), myList->end(), k - *it) != myList->end())) return true;

	return false;
}

void printResult(bool res, int k)
{
	char buff[50 + 1];
	char aux[10 + 1];

	if (!res)
		strncpy_s(aux, "not ", sizeof(aux));
	else
		strncpy_s(aux, "", sizeof(aux));

	snprintf(buff, sizeof(buff), "%i is %sformed by two values on the given List", k, aux);

	std::cout << buff << std::endl;
}

#ifdef _01_CheckSumInArray
int main()
{
	std::list<int> myFirstList;
	std::list<int> mySecondList = { 11, 15, 7, 3 };
	std::list<int> myThirdList = { 10, 15, 3, 7 };

	int k = 17;

	printResult(hasSum(&myFirstList, k), k);
	printResult(hasSum(&mySecondList, k), k);
	printResult(hasSum(&myThirdList, k), k);

	return 0;
}
#endif