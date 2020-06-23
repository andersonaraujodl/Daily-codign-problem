/*
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

Date: 23/06/2020
Time: 18:25 to 19h01 - I found out my solution didn't work nicely, and found this simple solution that works perfectly
*/

#include "const.h";

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

int maxSum(int arr[], int &size)
{
	int incl = arr[0];
	int excl = 0;
	int excl_new;
	int i;

	for (i = 1; i < size; i++)
	{
		// current max excluding i
		excl_new = (incl > excl) ? incl : excl;

		// current max including i
		incl = excl + arr[i];
		excl = excl_new;
	}

	return ((incl > excl) ? incl : excl);
}

#ifdef _09_LargestSum
int main()
{
	int a[] = { 2, 4, 6, 2, 5 };
	int sizeA = ARRAY_SIZE(a);

	int b[] = { 5, 1, 1, 5 };
	int sizeB = ARRAY_SIZE(b);

	int c[] = { 0, 1, 1, 5 };
	int sizeC = ARRAY_SIZE(c);

	std::cout << "Max Sum of A: " << maxSum(a, sizeA) << std::endl;
	std::cout << "Max Sum of B: " << maxSum(b, sizeB) << std::endl;
	std::cout << "Max Sum of C: " << maxSum(c, sizeC) << std::endl;
}
#endif;