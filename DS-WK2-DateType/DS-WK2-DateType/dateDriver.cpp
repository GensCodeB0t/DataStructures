// WEEK 2: Programming Exercise #2, page 124
// VALIDATING INPUT TO dateType CLASS
// Ryan Gens

#include <iostream>
#include <string>
#include "dateType.h"

using namespace std;

void main()
{
	dateType testDate;
	string month, day, year;
	char quit;

	do
	{
		// Ask for user input.
		cout << "Please enter a number value for the month\n";
		cin >> month;
		cin.get();
		cout << "Please enter a number value for the day\n";
		cin >> day;
		cin.get();
		cout << "Please enter a value for the year\n";
		cin >> year;
		cin.get();

		// Validate the user input and store the valid date.
		testDate.setDate(month, day, year);

		// Print the date to the screen.
		testDate.printDate();

		// Repeat or Quit?
		do
		{
			cout << "Enter Q to quit or R to retry.\n";
			cin >> quit;
			cin.get();
			if (toupper(quit) == 'Q')
				exit(0);
		} while (toupper(quit) != 'R');
	} while (toupper(quit)=='R');
}