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
	std::uniform_real_distribution<float> rand(1.0, 5.0);

	int i = (int)rand(rd);

	std::cout << "Rand 5: " << i << std::endl;
	return i;
}

int rand7()
{
	int i = ((rand5() + rand5()) * 5) % 7;
	
	i = (i == 0) ? 7 : i;

	std::cout << "Rand 7: " << i << std::endl;
	return i;
}

#ifdef _45_Rand
int main()
{
	std::cout << rand7() << std::endl;
}
#endif