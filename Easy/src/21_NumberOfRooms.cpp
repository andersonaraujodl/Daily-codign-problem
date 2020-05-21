/*
Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

Date: 20/04/2020
Total Time: 25min
*/

#include<list>
#include "const.h"

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

typedef struct ClassInterval
{
	int begin, end;
}class_interval_t;

int checkIntersections(class_interval_t intervals[], int size)
{
	if (size == 0 || size == 1)
		return size;

	int numOfRooms = 1;

	for (int i = 1; i < size; ++i)
	{
		int intersections = 0;

		for (int j = 0; j < size; ++j)
		{
			if (intervals[i].begin >= intervals[j].begin && intervals[i].begin <= intervals[j].end)
			{
				++intersections;
			}

			if (intersections >= numOfRooms)
			{
				++numOfRooms;
				break;
			}
		}
	}

	return numOfRooms;
}

#ifdef _21_NumberOfRooms
int main()
{
/*
		30------------------ - 75 - 3
0----------50 - 2
		        60------------------150 - 4
  20-------- 55 - 4
		                            150------170 - 2
		                                     170----180 - 2
		                                         175---185 - 3
													   185---190 - 3
0-----------------------------------------------------------189 - 1

*/

	class_interval_t intervals[] = { {30,75}, {0,50}, {60,150}, {20,55}, {150, 170}, {170, 180}, {175, 185}, {185, 190}, {1, 189} };
	
	std::cout << checkIntersections(intervals, ARRAY_SIZE(intervals)) << std::endl;

	return 0;
}
#endif