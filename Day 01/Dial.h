#pragma once

#include "Password.h"
#define DIAL_DIVISION 100u


class Dial : public Password
{
	public:
		void rotate (const Instruction& inst);
		
		explicit Dial(uint8_t _startingNumber) : startingNumber(_startingNumber), currentNumber(_startingNumber), 
			previousNumber(_startingNumber)
		{
			
		}
		~Dial() = default;
	private:

		bool overflow = false;
		uint8_t startingNumber;
		int8_t currentNumber;
		uint8_t previousNumber;

		void decipher(const uint8_t) override;
		void method_0x434C49434B( const uint16_t) override;
};

