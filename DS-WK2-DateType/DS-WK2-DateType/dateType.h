// WEEK 2: Programming Exercise #2, page 124
// VALIDATING INPUT TO dateType CLASS
// Ryan Gens

#ifndef DATETYPE_H
#define DATETYPE_H
#include <string>

using namespace std;

class dateType
{
public:
	dateType(string Month = "01", string Day = "01", string Year = "1990");
	// Constructor to set the date.
	// The member variables dMonth, dDay, and dYear are set
	// according to the parameters.
	// Postcondition: dMonth = month; dDay = day, dYear = year. If 
	// no values are specified, the default values are used to initialize 
	// the member variables.

	void setDate(string Month, string Day, string Year);
	// Funtion to set the date.
	// The member variables dMonth, dDay, and dYear are set
	// according to the parameters.
	// Postcondition: dMonth = month; dDay = day, dYear = year.

	int getDay() const;
	// Function to return the day.
	// Postcondition: The value of dDay is returned.

	int getMonth() const;
	// Function to return the month.
	// Postcondition: The value of dMonth is returned.

	int getYear() const;
	// Function to return the year.
	// Postcondition: The value of dYear is returned.

	void printDate() const;
	// Function to output the date in the form mm-dd-yyyy.

	bool isLeapYear() const;
	// Returns boolean value if the date is a leap year.
	// Precondition: 
	// if (year is not exactly divisible by 4) then(it is a common year)
	// else
	// if (year is not exactly divisible by 100) then(it is a leap year)
	// else
	// if (year is not exactly divisible by 400) then(it is a common year)
	// else (it is a leap year)
	// Postcondition: A boolean value is returned.

private:
	int dMonth; // Variable to store the month.
	int dDay; // Variable to store the day.
	int dYear; // Variable to store the year.
	int date[3]; // Variable to store the tested date. date[1] = month, date[2] = day, date[3] = year.
	bool validDate;	// Variable to store the results of the date validation.


	bool vailidateDate(string Month, string Day, string Year);
	// Function to vaildate the user input date.
	// Postcondition: A bool value is returned; true if the date
	// is valid and false if it is not.

};
#endif