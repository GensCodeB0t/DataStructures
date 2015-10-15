// WEEK 2: Programming Exercise #2, page 124
// VALIDATING INPUT TO dateType CLASS
// Ryan Gens

#include "dateType.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>


using namespace std;

// Constructor with parameters
dateType::dateType(string Month, string Day, string Year)
{
	setDate(Month, Day, Year);
}

// Getters
int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}

// Transfers validated values for Month, Day, and Year variables into
// dMont, dDay, and dYear variables.
void dateType::setDate(string Month, string Day, string Year)
{
	validDate = vailidateDate(Month, Day, Year);	// Determine if the date is valid.
	if (validDate)
	{
		dDay = date[0];
		dMonth = date[1];
		dYear = date[2];
	}
	else
	{
		dDay = 00;
		dMonth = 00;
		dYear = 0000;
	}
}

void dateType::printDate() const
{
	if (validDate)	// Determine if the date is valid.
	{
		if (isLeapYear())	// Determine if the year is a leap year.
		{
			cout << "The date you entered is a leap year.\n";
		}
		else
		{
			cout << "The date you entered is NOT a leap year.\n";
		}

		cout << "The date you entered = "
			<< setw(2)	// set the width of the output
			<< setfill('0')	// fill in empty spaces with zeros
			<< dMonth
			<< "-" 
			<< setw(2)	// set the width of the output
			<< dDay 
			<< "-"
			<< setw(4)	// set the width of the output
			<< dYear << endl;
	}
	else
	{
		cout << "You did not enter a valid date, please try again.\n";
	}

}

bool dateType::vailidateDate(string Month, string Day, string Year) 
{
	// Create a temporary String array to make it easier to implement a 
	// for loop.
	string stringArray[] = { { Day }, { Month }, { Year } };

	for (int arrayPos = 2; arrayPos >= 0; arrayPos--)
	{
		// Check if the user input is a number.
		if (!isdigit(*stringArray[arrayPos].c_str()))
			return false;
		// Convert the string value to an integer and place it in 
		// a temporary array.
		date[arrayPos] = atoi(stringArray[arrayPos].c_str());
		switch (arrayPos)
		{
		case 0:	// Day-- Test if the day variable is a day of the month. 
			if (date[arrayPos] < 1)
				return false;
			switch (date[1])
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				if (date[arrayPos] > 31)
					return false;
				break;
			case 2:	// February compensates for Leap Year.
				if (isLeapYear())
				{
					if (date[arrayPos] > 29)
						return false;
				}
				else
				{
					if (date[arrayPos] > 28)
						return false;
				}

				break;
			case 4:
			case 6:
			case 9:
			case 11:
				if (date[arrayPos] > 30)
					return false;
				break;
			}
			break;
		case 1:	// Month-- Checks whether the Month variable is valid.
			if ((date[arrayPos]<1) || (date[arrayPos]>12))
				return false;
			break;
		case 2:	// Year--Checks whether the Year variable is valid.
			if ((date[arrayPos]<1) || (date[arrayPos]>9999))
				return false;
			break;
		}
	}
	return true;
}

bool dateType::isLeapYear() const
{
	// A leap year occurs: 
	// if (year is not exactly divisible by 4) then(it is a common year)
	// else
	// if (year is not exactly divisible by 100) then(it is a leap year)
	// else
	// if (year is not exactly divisible by 400) then(it is a common year)
	// else (it is a leap year)

	bool leapYear;
	if (date[2] % 4 != 0)
	{
		leapYear = false;
	}
	else if (date[2] % 100 != 0)
	{
		leapYear = true;
	}
	else if (date[2] % 400 != 0)
	{
		leapYear = false;
	}
	return leapYear;
};
