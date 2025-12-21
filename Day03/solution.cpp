#include "solution.h"
#include <string_view>
#include <vector>
#include <algorithm>

std::size_t getJoltage(std::string&& line)
{

	size_t offset{ 0 };
	
	size_t num{ 0 };
	constexpr auto digitsToGet{ 12 };

	std::vector<std::pair<Size, Type>>pairs;
	pairs.reserve(digitsToGet);

	for (std::size_t i = 0; i < digitsToGet; i++)
	{
		auto p = getPositionAndValue(line, offset, digitsToGet - 1 - i);

		
		offset = p.first + 1;

		
		 
		pairs.push_back(p);
		
	}

	Joltage joltage(std::move(pairs));

	return  joltage.getNumber();
}


std::pair<Size, Type> getPositionAndValue(const std::string_view& sv, const Size _offset, const Size _ignore)
{
	const auto len = sv.length();

	if (_offset > len || _ignore > len)
	{
		throw std::invalid_argument("Offset exceeds string length!\n");
	}

	Size pos {0};
	Type val { 0 };
	

	for (Size i = _offset; i < len - _ignore; ++i)
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
	std::size_t num{ 0 };

	auto powerOfTen = orderedDigits.size() - 1;
	for (const auto& d : orderedDigits)
	{
		//printf("%d\n", d.second );
		num += d.second * pow(10, powerOfTen--);

	}
	return num;
}


Joltage::Joltage(PairList&& vec)
	: orderedDigits(std::move(vec))
{		
	using Pair = std::pair<Size, Type>;

	std::sort(orderedDigits.begin(), orderedDigits.end(), [](const Pair& a, const  Pair& b)
		{
			return a.first < b.first;
		});

}
Joltage::Joltage(std::initializer_list<std::pair<Size, Type>> pairs)
{
	printf("Initializer list constructor.\n");
	orderedDigits.reserve(pairs.size());
	auto it = orderedDigits.begin();
	
	for (auto p : pairs )
	{
		*it++ = std::move(p);

	}
	using Pair = std::pair<Size, Type>;
	std::sort(orderedDigits.begin(), orderedDigits.end(), [](const Pair& a, const  Pair& b)
		{
			return a.first < b.first;
		});
}