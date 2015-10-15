// WEEK 3: Programming Exercise #2, page 204
// Testing the removeAll member function
// Ryan Gens

#include <iostream>
#include <string>
#include "arrayListType.h"

using namespace std;

void main()
{
	const int arraySize = 10;
	string inputItem;
	arrayListType<string> stringList(arraySize);

	// Prompt User for items, and add the to the list.
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Please enter item " << i+1 << " of the list." << endl;
		getline(cin, inputItem);
		stringList.addItem(inputItem);
	}
	// Print the user created list.
	stringList.printList();
	// Prompt the user for the item to remove
	cout << "Press enter the item to remove.\n";
	getline(cin, inputItem);
	// Test the removeAll member function.
	stringList.removeAll(inputItem);
	// Print the new list
	stringList.printList();

	cout << "Press enter to end the program.\n";
	cin.get();
}