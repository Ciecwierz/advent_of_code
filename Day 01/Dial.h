#pragma once

#include "Password.h"
#define DIAL_DIVISION 100u


class Dial : public Password
{
	public:
		void rotate (const Instruction& inst);
		
		explicit Dial(uint8_t _startingNumber) : startingNumber(_startingNumber), currentNumber(_startingNumber)
		{
			
		}
		~Dial() = default;
	private:	
		uint8_t startingNumber;
		int8_t currentNumber;
		void decipher(const uint8_t) override;
		
		uint16_t iteration = 0;
};

