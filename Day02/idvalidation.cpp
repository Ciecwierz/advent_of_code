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

		const auto len = s.length();

		if (s[0] == '0')
			vec.push_back(i);

		letters = 1;	

		do 
		{
		
			changeString(repeat, s, letters);
			

			auto res = std::string_view(s).substr(letters).find(repeat);
			if (res == 0)
			{
				letters += repeat.size();
				if (std::string_view(s).substr(letters).empty())
				{
					vec.push_back(i);
					break;
				}
				else if(std::string_view(s).substr(letters).compare(repeat) == 0 && std::string_view(s).substr(letters).length() == repeat.length())
				{
					vec.push_back(i);
					break;
				}
		
				
			}


			else if (res == std::string::npos)
				break;
			else
				letters++;
		
			
		} while (letters < len);
		
		

	}

	for (auto x : vec)
	{
		sum += x;
	}

	return sum;
}


void changeString(std::string_view& rep, const std::string& s, const std::size_t letters)
{
	std::string_view sv{ s };

	if (rep.empty())
	{
		rep = sv.substr(0, letters);
		return;
	}

	if (letters < rep.size() ||
		sv.compare(letters - rep.size(), rep.size(), rep) != 0)
	{
		rep = sv.substr(0, letters);
	}
}