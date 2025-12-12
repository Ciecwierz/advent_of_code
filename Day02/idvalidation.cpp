#include <string>
#include <vector>

#include "idvalidation.h"

std::pair<unsigned long long, unsigned long long> convertID(const std::string range)
{
	unsigned long long startID, lastID;
	
	const  std::size_t dashIndex = range.find(DASH);
	startID = std::stoull(range.substr(0, dashIndex));
	lastID = std::stoull(range.substr(dashIndex + 1, range.size() - dashIndex + 1));

	std::pair<unsigned long long, unsigned long long> values = { startID, lastID };

	return values;
}

unsigned long long validate(unsigned long long first, unsigned long long last)
{
	std::string s;
	std::string repeat;
	std::size_t letters{ 0 };
	unsigned long long sum{ 0 };
	std::vector<unsigned long long> vec;

	for (auto i = first; i <= last; i++)
	{
		s = std::to_string(i);
		if (s[0] == '0')
			vec.push_back(i);

		letters = 0;
		repeat.clear();

		do 
		{
			letters++;
			if (letters <= s.length())
				repeat = s.substr(0, letters);
			else
				break;
		
			
		} while (s.substr(letters, s.length() - 1).compare(repeat) != 0);
		
		if (letters - 1 != s.length())
			vec.push_back(i);

	}

	for (auto x : vec)
	{
		sum += x;
	}

	return sum;
}