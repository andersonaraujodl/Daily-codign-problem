/*
55 - EASY

Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?

Date: 03/06/2020
Time: 19h25 to 19h56 = 35min
*/

#include "const.h"
#include <string>
#include <random>
#include <unordered_map>

//Randomaze a Character
char random_alpha_char()
{
	static const char alphanum[] =
		"0123456789"
		"abcdefghijklmnopqrstuvxyz"
		"ABCDEFGHIJKLMNOPQRSTUVXYZ";

	static size_t count = (sizeof(alphanum) / sizeof(alphanum[0])) - 2;
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> dis(0, count);

	return alphanum[dis(gen)];
}

std::unordered_map<std::string, std::string> savedURLs; //key = shorten url, value = original url

std::string ShortenURL(std::string url)
{
	std::unordered_map<std::string, std::string>::iterator it = savedURLs.begin();

	while (it != savedURLs.end())
	{
		if (url == it->second)
			return it->first;

		++it;
	}

	std::string shortUrl = "";

	while (shortUrl.size() < 6)
	{
		shortUrl += random_alpha_char();
	}

	std::unordered_map<std::string, std::string>::iterator hasKey = savedURLs.find(shortUrl);

	if (hasKey != savedURLs.end())
		ShortenURL(url);

	savedURLs[shortUrl] = url;

	return shortUrl;
}

std::string RestoreURL(std::string shortenUrl)
{
	std::unordered_map<std::string, std::string>::iterator hasKey = savedURLs.find(shortenUrl);

	if (hasKey != savedURLs.end())
		return (hasKey->second);

	return "URL not found!";
}

#ifdef _55_URL_Shrotener
int main()
{
    std::string link = "www.google.com.br";
	std::string myWebsite = "www.araujoanderson.com";
	std::string google = "www.google.com.br";

    std::cout << "Shorten Link: " << ShortenURL(link) << std::endl;
	std::cout << "Shorten Link: " << ShortenURL(myWebsite) << std::endl;
	std::cout << "Shorten Google: " << ShortenURL(google) << std::endl << std::endl;

	std::cout << "Restored MyWebsite: " << RestoreURL(ShortenURL(myWebsite)) << std::endl;
	std::cout << "Restored Google: " << RestoreURL(ShortenURL(google)) << std::endl;
}
#endif