#pragma once
#include <string>
#include <utility>
#include <string_view>
#include <initializer_list>
#include <stdexcept>

using Type = unsigned char;
using Size = std::size_t;


std::size_t getJoltage(std::string&&);
std::pair<Size, Type> getPositionAndValue(const std::string_view&, const Size);



class Joltage
{

private:
	//format 
	
	Type decimal;
	Type ones;
	Size pos_A;
	Size pos_B;

	

public:
	explicit Joltage(std::initializer_list<std::pair<Size, Type>>pairs)
	{
		auto it = pairs.begin();
		pos_A = it->first;
		it++;
		pos_B = it->first;

		if (pos_A < pos_B)
		{
			it = pairs.begin();
			decimal = it->second;
			it++;
			ones = it->second;
		}
		else if (pos_A > pos_B)
		{
			decimal = it->second;
			it--;
			ones = it->second;
		}
		else
		{
			throw std::invalid_argument("Both digits share the same position in string\n");
		}
		
	}

	Size getNumber() const;

	~Joltage() = default;

};
 