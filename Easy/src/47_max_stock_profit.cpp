/*
Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

Date: 24/05/2020
Time: 15:25 to 15:42
*/

#include <array>
#include "const.h"

int MaxStockProfit(std::array<int, 6> values)
{
	int max = 0;
	int arrSize = values.size();

	for (int i = arrSize - 1; i > -1; --i)
	{
		for (int j = i - 1; j > -1; --j)
		{
			int profit = values[i] - values[j];

			if (profit > max)
				max = profit;
		}
	}

	return max;
}

//#ifdef _47_Max_Stock_Profit
int main()
{
	std::array<int, 6> stock = { 1, 3, 5, 9, 2, 12 };

	std::cout << MaxStockProfit(stock) << std::endl;
}
//#endif
