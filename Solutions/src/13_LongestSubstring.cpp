/*
 Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
 
 For example, given s = "abcbabbccbb" and k = 2, the longest substring with k distinct characters is "bcb".

 Date: 29/06/2020
 Time: From 19h30 to 20h06 (this is not optmized T_T)
*/

#include "const.h"

std::string LongestString(std::string s, int k)
{
	std::string longestString;

	for (int i = 0; i < s.size(); ++i)
	{
		std::string subString;
		subString += s[i];
		int uniqueChar = 1;

		for (int j = i + 1; j < s.size(); ++j)
		{
			if (subString.find(s[j]) != std::string::npos)
			{
				subString += s[j];
			}
			else
			{
				if (uniqueChar < k)
				{
					subString += s[j];
					++uniqueChar;
				}
				else
				{
					break;
				}
			}
		}

		if (subString.size() > longestString.size())
			longestString = subString;
	}

	return longestString;
}

int main()
{
	std::string test1 = "abcba"; //->bcb
	std::string test2 = "abcbabbccbb"; //->bbccbb
	std::string test3 = "hehhaiaii"; // ->aiaii
	std::string test4 = "aabcbcbcbcbcbabc"; // 2 ->bcbcbcbcbcb  ~ 3 -> aabcbcbcbcbcbabc
	std::string test5 = "uxiiayhwuahu"; // ->uxii

	std::cout << "abcba (2) - " << LongestString(test1, 2) << std::endl;
	std::cout << "abcbabbccbb (2) - " << LongestString(test2, 2) << std::endl;
	std::cout << "hehhaiaii (2) - " << LongestString(test3, 2) << std::endl;
	std::cout << "aabcbcbcbcbcbabc (2) - " << LongestString(test4, 2) << std::endl;
	std::cout << "aabcbcbcbcbcbabc (3) - " << LongestString(test4, 3) << std::endl;
	std::cout << "uxiiayhwuahu (3) - " << LongestString(test5, 3) << std::endl;
	std::cout << "uxiiayhwuahu (4) - " << LongestString(test5, 4) << std::endl;

}