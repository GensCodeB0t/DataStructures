// WEEK 1: Programming Exercise #1, page 57
// ROMAN NUMERALS TO DECIMAL PROGRAM
// Ryan Gens

#include "RomanType.h"
#include <iostream>
using namespace std;

RomanType::RomanType()
{
	// Initalize the values of the object variables.
	numeral == "";
	decimalVal = 0;
}

void RomanType::setNumeral(string numVal)
{
	numeral = numVal;
}

bool RomanType::decimalConvert()
{
	bool skipOperand = true;
	int operand = 0;
	int prevVal = 0;
	// Determine the Roman Numeral at each position in the string, vaildate that the character is a numeral
	// and assign its value to the 'operand' variable.
	for (unsigned int numPos = 0; numPos <= numeral.length(); numPos++)
	{
		if (numPos < numeral.length())
		{
			switch (toupper(numeral.at(numPos)))
			{
			case 'M':
				operand = 1000;
				break;
			case 'D':
				operand = 500;
				break;
			case 'C':
				operand = 100;
				break;
			case 'L':
				operand = 50;
				break;
			case 'X':
				operand = 10;
				break;
			case 'V':
				operand = 5;
				break;
			case 'I':
				operand = 1;
				break;
			case 'Q':
				exit(0);
				break;
			default:
				operand = 0;
				cout << "Julius Caesar does not approve of your input, please try again.\n";
				return false;
				break;
			}
		}

		// Determines whether to add to or subtract from the decimal value based on the value of the Roman
		// Numeral. A larger numeral preceding a smaller or equal numeral means addition, while a smaller numeral preceding
		// a larger numeral means subtraction.
		if (skipOperand)
		{
			prevVal = operand;
			skipOperand = false;
		}
		else
		{
			if (prevVal >= operand)
			{
				decimalVal += prevVal;
				prevVal = operand;
			}
			else
			{
				operand -= prevVal;
				decimalVal += operand;
				skipOperand = true;
			}
		}
	}
	return true;
}

void RomanType::printValue() const
{
	cout << "\nThe Decimal Value stored = " << decimalVal << endl << endl;
}
void RomanType::printNumeral() const
{
	cout << "\nThe Roman Numeral Value stored = " << numeral << endl << endl;
}