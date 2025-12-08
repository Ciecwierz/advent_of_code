#pragma once
#include <cstdint>
#include <string>
#include <stdexcept>
class Password
{
protected:
	uint16_t countZeros = 0;
	virtual void decipher(const uint8_t) = 0;
	virtual void method_0x434C49434B( const uint16_t) = 0;
public:
	virtual ~Password() = default;
	uint16_t getPassword() const { return countZeros; }

};


enum class DIRECTION
{
	LEFT = 0,
	RIGHT
};

struct Instruction
{
	uint16_t num;
	DIRECTION dir;

	explicit Instruction(DIRECTION d, uint8_t n) : dir(d), num(n)
	{}
	Instruction() = default;
	~Instruction() = default;
	explicit Instruction( const std::string& s)
	{
		if (s[0] == 'L')
			this->dir = DIRECTION::LEFT;
		else if (s[0] == 'R')
			this->dir = DIRECTION::RIGHT;
		else
		{	
			throw std::invalid_argument("Wrong format");
		}
		this->num = std::stoi(s.substr(1, s.length() - 1));
	}
	Instruction& operator=(const Instruction& i)
	{
		this->dir = i.dir;
		this->num = i.num;
		return *this;
	}
	void set(DIRECTION d, uint8_t n)
	{
		this->dir = d;
		this->num = n;
	}
	void set(const std::string& s)
	{
		if (s[0] == 'L')
			this->dir = DIRECTION::LEFT;
		else if (s[0] == 'R')
			this->dir = DIRECTION::RIGHT;
		else
		{
			throw std::invalid_argument("Wrong format");
		}
		this->num = std::stoi(s.substr(1, s.length() - 1));
	}
};



