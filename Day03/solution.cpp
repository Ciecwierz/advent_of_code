#include "solution.h"
#include <string_view>
#include <vector>

std::size_t getJoltage(std::string&& line)
{

	size_t offset{ 0 };
	
	size_t num{ 0 };
	constexpr auto digitsToGet{ 2 };

	std::vector<std::pair<Size, Type>>pairs;
	pairs.reserve(digitsToGet);

	for (std::size_t i = 0; i < digitsToGet; i++)
	{
		auto p = getPositionAndValue(line, offset);

		
		line.at(p.first) = '0';

		if (p.first != line.length() -1)
			offset = p.first + 1;

		pairs.push_back(p);
		
	}

	Joltage joltage({ pairs[0], pairs[1] });

	return  joltage.getNumber();
}


std::pair<Size, Type> getPositionAndValue(const std::string_view& sv, const Size _offset)
{

	
	const auto len = sv.length();

	if (_offset > len)
	{
		throw std::invalid_argument("Offset exceeds string length!\n");
	}

	Size pos;
	Type val = 0;
	

	for (Size i = _offset; i < len; ++i)
	{
		const auto toInt = sv[i] - '0';
		if (toInt > val)
		{
			pos = i;
			val= toInt;
		}

	}

	return std::make_pair( pos, val );

}




std::size_t Joltage::getNumber() const
{
	std::size_t num = decimal * 10 + ones;
	return num;

}