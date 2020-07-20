/*
Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", your function should return true. The same regular expression on the string "raymond" should return false.

Given the regular expression ".*at" and the string "chat", your function should return true. The same regular expression on the string "chats" should return false.

Date: 13/07/2020
Time: from 19h20 to 19h58 = 38min */

#include "const.h"

bool validateRegex(std::string original, std::string regex)
{
	if (regex.size() == 0)
		return true;

	if (regex.size() > original.size())
		return false;

	int j = original.size() - 1;

	for (int i = regex.size() - 1; i >= 0; --i)
	{
		if (regex[i] == '*')
		{
			while (j >= i)
			{
				--j;
			}
		}
		else if (regex[i] == '.')
		{
			--j;
			continue;
		}
		else if (original[j] != regex[i])
		{
			return false;
		}
		else
		{
			--j;
		}
	}

	return true;
}

#ifdef _25_RegexValidation
int main()
{
	std::string original1 = "chat";
	std::string original2 = "chats";
	std::string original3 = "chaaeaeeat";
	std::string regex1 = ".*at";

	std::string original4 = "ray";
	std::string original5 = "raymond";
	std::string original6 = "raeay";
	std::string regex2 = "ra.";
	std::string regex3 = "ra*";

	std::cout << "Validate " << original1 << " with Regex: " << regex1 << ": " << validateRegex(original1, regex1) << std::endl;
	std::cout << "Validate " << original2 << " with Regex: " << regex1 << ": " << validateRegex(original2, regex1) << std::endl;
	std::cout << "Validate " << original3 << " with Regex: " << regex1 << ": " << validateRegex(original3, regex1) << std::endl;

	std::cout << "Validate " << original4 << " with Regex: " << regex2 << ": " << validateRegex(original4, regex2) << std::endl;
	std::cout << "Validate " << original5 << " with Regex: " << regex2 << ": " << validateRegex(original5, regex2) << std::endl;
	std::cout << "Validate " << original6 << " with Regex: " << regex2 << ": " << validateRegex(original6, regex2) << std::endl;
	std::cout << "Validate " << original6 << " with Regex: " << regex3 << ": " << validateRegex(original6, regex3) << std::endl;
}
#endif