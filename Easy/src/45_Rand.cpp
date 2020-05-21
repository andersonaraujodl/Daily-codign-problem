/*
Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, implement a function rand7() that returns an integer from 1 to 7 (inclusive).

Date: 20/05/2020
Time: 23:45 to 00:10 + 15 minutos to some optimization
*/
#include "const.h"
#include <random>
#include <iostream>

//Created my rand5 funcion using <radom>
int rand5()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> rand(1, 5);

	int i = rand(rd);
	return i;
}

int rand7()
{
	int i = 5 * rand5() + rand5() - 5; 

	//To keep distribution
	if (i < 22)
		return i % 7 + 1;

	return rand7();
}

#ifdef _45_Rand
int main()
{
	const int total_runs = 100000;
	int pesos[7] = { 0 };

	for (int i = 0; i < total_runs; ++i)
	{
		int valor = rand7();
		//std::cout << valor << ", ";

		++pesos[valor - 1];
	}

	std::cout << "Pesos:" << std::endl;

	for (int i = 0; i < 7; ++i)
	{
		std::cout << i + 1 << "=" << pesos[i] << ", ";
	}
}
#endif