/*
Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.

Date: 01/05/2020
Keywords: Run-lengh; Encoding
Time: from 16:15 to
*/
#include <iostream>
#include <string>

std::string encode(std::string c)
{
	if (c.empty())
		return "INVALID FORMAT";

	if (c.size() == 1)
		return "1" + c;

	int count = 0;
	std::string result = "";
	char currentChar = c[0];

	for (size_t i = 0; i < c.size(); ++i)
	{
		if (c[i] == currentChar)
		{
			++count;
			continue;
		}

		result += std::to_string(count) + c[i-1];
		currentChar = c[i];
		count = 1;
	}

	result += std::to_string(count) + c[c.size() - 1];
	return result;
}

std::string decode(std::string c)
{
	std::string result = "";

	for (size_t i = 0; i < c.size(); ++i)
	{
		if (isdigit(c[i]))
		{
			for (size_t j = 0; j < (int)c[i]; ++j)
				result += c[i + 1];
		}
	}

	return result;
}

#ifdef _29_RunLengthEncoding
int main()
{
	std::string a = "AAAABBBCCDAA";

	std::cout << encode(a) << std::endl;
	std::cout << decode(encode(a)) << std::endl;

	return 0;
}
#endif