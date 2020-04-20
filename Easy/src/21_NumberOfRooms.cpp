/*
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

Date: 20/04/2020
Total Time: 25min
*/

#include<list>
#include <iostream>
#include "const.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

typedef struct ClassInterval
{
	int begin, end;
}class_interval_t;

int checkIntersections(class_interval_t intervals[], int size)
{
	if (size <= 0)
		return 0;

	int numOfRooms = 1;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (j <= i)
				continue;

			if (intervals[i].begin >= intervals[j].begin && intervals[i].begin <= intervals[j].end)
			{
				++i;
				++numOfRooms;
			}
		}
	}

	return numOfRooms;
}

#ifdef _21_NumberOfRooms
int main()
{
	class_interval_t intervals[] = { { 30, 75 }, { 0, 50 }, { 60, 150 }};
	
	std::cout << checkIntersections(intervals, ARRAY_SIZE(intervals)) << std::endl;

	return 0;
}
#endif