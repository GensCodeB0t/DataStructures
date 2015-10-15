// WEEK 1: Programming Exercise #1, page 57
// ROMAN NUMERALS TO DECIMAL PROGRAM
// Ryan Gens

#include <iostream>
#include <string>
#include <cstdlib>
#include "romanType.h"

using namespace std;

void main()
{
	// Local Varaibles
	char option;
	string numeral;

	do
	{
		RomanType romanNum;
		do
		{
			// Asks for and converts user input of a Roman Numeral into a decimal value.
			// Input is checked for valid Roman Numerals during conversion process.
			cout << "Please enter the Roman Numeral value you would like to convert, OR Q to quit.\n";
			cin >> numeral;
			cin.get();
			romanNum.setNumeral(numeral);
		} while (!romanNum.decimalConvert());

		do
		{
			// Prompt user for Printing stored data or repeating/quiting program. 
			cout << "Please select one of the following:\n\t1) Print Roman Numeral\n\t2) Print Decimal Number\n\tQ) Quit\n"
				<< "\tR) Enter a new Romal Numeral\n";
			cin >> option;
			cin.get();
			switch (toupper(option))
			{
			case '1':
				romanNum.printNumeral();
				break;
			case '2':
				romanNum.printValue();
				break;
			case 'Q':
				exit(0);
				break;
			case 'R':
				break;
			default:
				cout << "You have entered an invalid option. Please try again.\n";
				break;
			} 
		} while (toupper(option) != 'R');
	} while (toupper(option) == 'R');
}

