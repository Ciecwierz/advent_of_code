#include "Dial.h"


void Dial::rotate(const Instruction& inst)
{
	overflow = false;
	switch (inst.dir)
	{
		case DIRECTION::LEFT:
		{					
			this->currentNumber -= (inst.num % DIAL_DIVISION); 		
			if (this->currentNumber < 0) 
			{
				overflow = true;
				this->currentNumber += DIAL_DIVISION;
				
			}
			method_0x434C49434B(inst.num);
			decipher(this->currentNumber);
			break;
		}

		case DIRECTION::RIGHT:
		{
			this->currentNumber += (inst.num % DIAL_DIVISION);	
			if (this->currentNumber >= DIAL_DIVISION )
			{	
				overflow = true;
				this->currentNumber -= DIAL_DIVISION;
			
			}
			method_0x434C49434B(inst.num);
			decipher(this->currentNumber);
			break;
		}
		default:
			break;
	}
	//printf("Number %d\n",this->currentNumber);

}

void Dial::decipher( const uint8_t i)
{	
	if (i == 0)
		countZeros++;
}

void Dial::method_0x434C49434B(const uint16_t sequence)
{
	this->countZeros += sequence / DIAL_DIVISION;
	if (overflow && this->currentNumber != 0 && this->previousNumber != 0)
		this->countZeros++;

	this->previousNumber = this->currentNumber;
}