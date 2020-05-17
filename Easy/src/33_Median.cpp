/*Compute the running median of a sequence of numbers. That is, given a stream of numbers, print out the median of the list so far on each new element.

Recall that the median of an even - numbered list is the average of the two middle numbers.

For example, given the sequence[2, 1, 5, 7, 2, 0, 5], your algorithm should print out :

2
1.5
2
3.5
2
2
2

date: 10/05/2020
Time: 25 (wrong answer) + 15min to fix it using vector lib.

*/

#include <vector> 
#include <iostream>
#include <algorithm>
#include "const.h"

void GetMedians(std::vector<int> disordSequence)
{
	if (disordSequence.size() == 0)
		std::cout << "Empty List";

	if (disordSequence.size() == 1)
		std::cout << disordSequence.front();

	std::vector<int> orderSequence;

	for (std::vector<int>::iterator it = disordSequence.begin(); it != disordSequence.end(); ++it)
	{
		orderSequence.push_back(*it);
		int size = orderSequence.size();
		std::sort(orderSequence.begin(), orderSequence.end());

	    int middleIndex = size / 2;

		if (size % 2)
		{
			std::cout << orderSequence[middleIndex] << std::endl;
		}
		else
		{
			int secondMiddleIndex = middleIndex - 1;
			std::cout << (((float)orderSequence[middleIndex] + orderSequence[secondMiddleIndex]) / 2.0f) << std::endl;
		}
	}
}

#ifdef _33_Median
int main()
{
	std::vector<int> sequence = {2, 1, 5, 7, 2, 0, 5};

	GetMedians(sequence);
	
	return 0;
}
#endif