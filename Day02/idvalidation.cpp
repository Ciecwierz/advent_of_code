#include <string>
#include <vector>
#include <string_view>
#include <format>
#include <charconv>
#include "idvalidation.h"

std::pair<unsigned long long, unsigned long long> convertID(const std::string& range)
{
	unsigned long long startID, lastID;
	
	const  std::size_t dashIndex = range.find(DASH);

	auto s_sid = std::string_view(range).substr(0, dashIndex); 
	auto s_lid = std::string_view(range).substr(dashIndex + 1, range.size() - dashIndex + 1);

	std::from_chars(s_sid.data(), s_sid.data() + s_sid.size(), startID);
	std::from_chars(s_lid.data(), s_lid.data() + s_lid.size(), lastID);

	std::pair<unsigned long long, unsigned long long> values = { startID, lastID };

	return values;
}

unsigned long long validate(unsigned long long first, unsigned long long last)
{
	std::string s;
	std::string_view repeat;
	std::size_t letters{ 0 };
	unsigned long long sum{ 0 };
	std::vector<unsigned long long> vec;
	vec.reserve(last - first + 1);

	for (auto i = first; i <= last; i++)
	{
		s = std::to_string(i);
		if (s[0] == '0')
			vec.push_back(i);

		letters = 0;
		

		do 
		{
			letters++;
			if (letters <= s.length())
				repeat = std::string_view(s).substr(0, letters);
			else
				break;
		
			
		} while (std::string_view(s).substr(letters, s.length() - 1).compare(repeat) != 0);
		
		if (letters - 1 != s.length())
			vec.push_back(i);

	}

	for (auto x : vec)
	{
		sum += x;
	}

	return sum;
}