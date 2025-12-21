#pragma once
#include <string>
#include <utility>
#include <string_view>
#include <initializer_list>
#include <stdexcept>
#include <vector>

using Type = unsigned char;
using Size = std::size_t;


std::size_t getJoltage(std::string&&);
std::pair<Size, Type> getPositionAndValue(const std::string_view&, const Size, const Size);



class Joltage
{
	using PairList = std::vector < std::pair<Size, Type>>;
private:
	
	PairList orderedDigits;
public:
	explicit Joltage(PairList&& list);
	
	explicit Joltage(std::initializer_list<std::pair<Size, Type>> pairs);

	Size getNumber() const;

	~Joltage() = default;

};
 