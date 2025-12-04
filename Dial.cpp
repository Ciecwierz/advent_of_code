#include "Dial.h"


void Dial::rotate(const Instruction& inst)
{
	switch (inst.dir)
	{
		case DIRECTION::LEFT:
		{		
			this->currentNumber -= (inst.num % DIAL_DIVISION);
			if (this->currentNumber < 0)
				this->currentNumber = DIAL_DIVISION + this->currentNumber;
			decipher(this->currentNumber);
			break;
		}

		case DIRECTION::RIGHT:
		{
			this->currentNumber += (inst.num % DIAL_DIVISION);
			if (this->currentNumber >= DIAL_DIVISION)
				this->currentNumber -= DIAL_DIVISION;
			decipher(this->currentNumber);
			break;
		}
		default:
			break;
	}
	printf("#%d Number %d\n", ++(this->iteration),this->currentNumber);

}

void Dial::decipher( const uint8_t i)
{	
	if (i == 0)
		countZeros++;
}