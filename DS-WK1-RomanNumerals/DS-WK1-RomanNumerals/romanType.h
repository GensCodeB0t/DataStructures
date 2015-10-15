// WEEK 1: Programming Exercise #1, page 57
// ROMAN NUMERALS TO DECIMAL PROGRAM
// Ryan Gens

#ifndef ROMANTYPE_H
#define ROMANTYPE_H
#include <string>

using namespace std;

class RomanType
{
public:
	// Constructor
	RomanType();

	// Setters
	void setNumeral(string);
	// Function Sets the value of the 'numeral' string.

	// Functions
	bool decimalConvert();
	// Function converts a Roman Numeral into a Decimal value.
	// User input is vaildated to make sure all characters are Roman Numerals.
	// Postcondition: Returns false if the user input does not contain valid 
	// Roman Numerals.

	void printValue() const;
	// Function prints the decimal value of the converted Roman Numeral ('decimalVal').

	void printNumeral() const;
	// Function prints the stored 'numeral' string


private:
	string numeral;		// User inputed Roman Numeral
	int decimalVal;		// Converted value
};


#endif // !ROMANTYPE_H