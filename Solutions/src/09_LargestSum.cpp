/*
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

Date: 23/06/2020
Time: 18:25 to 19h01
*/

#include "const.h";

#define ARRAY_SIZE(array) (sizeof(array)/sizeof(array[0]))

int maxSum(int arr[], int &size)
{
	int sum = arr[0];

	for (int i = 2; i < size; ++i)
	{
		if (sum <= 0 && arr[i - 1] > sum)
		{
			sum = arr[i - 1];
		}
		else if (i + 1 < size)
		{
			if (arr[i] > arr[i + 1])
			{
				if(sum > 0 && arr[i] > 0)
					sum += arr[i];
			}
			else
			{
				if (sum < 0 && arr[i + 1] > sum)
				{
					sum = arr[i + 1];
					++i;
				}
				if (sum > 0 && arr[i + 1] > 0)
				{
					sum += arr[i + 1];
					++i;
				}
			}
		}
		else 
		{
			//if arr[i] < 0 it will decrese the number
			if(arr[i] > 0)
				sum += arr[i];
		}
	}

	return sum;
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