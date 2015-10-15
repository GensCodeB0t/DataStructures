/*Ryan Gens Data Structures WK7.

Programming Exercises #14, page 392
Via the use of recursion, create a program that converts a decimal value into its equivalent value in a different base.
The decimal and base values should be user inputs.
Test with the following values:
9098 with a base of 20 = 12EI,
692 with a base of 2 =1010110100,
and 753 with a base of 16 = 2F1.
*/
#include <iostream>
#include <string>

using namespace std;

// Function prototypes.
void convertToBase(int, int, string&);
void addDigit(int, string&);


void main(){
	int inputDec, inputBase;
	string convertedNum;

	// Collect User input.
	cout << "Please enter the decimal (integer) value you would like to convert.\n";
	cin >> inputDec;
	cin.get();
	
	do{
		cout << "Please enter a base (integer) value, between 2 and 36,\nthat you would like to convert the to decimal to.\n";
		cin >> inputBase;
		cin.get();
	} while (inputBase < 2 || inputBase > 36);

	// Calculate and print the Converted Value.
	convertToBase(inputDec, inputBase, convertedNum);
	cout << "The Converted value = " << convertedNum << endl
		<< "Press enter to quit." << endl;

	// End program.
	cin.get();
}

//**********************************************************************
// convertTobase-- Converts the decimal input to a string representing
// the same decimal with the base of the user input base. This function
// is accomplished using recursion.
//**********************************************************************
void convertToBase(int decimal, const int base, string& convertedNum){
	if (decimal > 0){
		convertToBase(decimal / base, base, convertedNum);
		addDigit(decimal % base, convertedNum);
	}
	
}
//**********************************************************************
// addDigit-- Builds a string of digits representative of the converted
// value. This function receives a digit from the convertToBase that is 
// converted to a char via its ASCII value. Digits less than 10 are 
// offset by 48; values over are offset by 55. The string is build by
// reference.
//**********************************************************************
void addDigit(int digit, string& convertedNum){	
	char digitChar;
	if (digit < 10)
		digitChar = (digit + 48);
	else
		digitChar = (digit + 55);
	convertedNum.append(1,digitChar);
}