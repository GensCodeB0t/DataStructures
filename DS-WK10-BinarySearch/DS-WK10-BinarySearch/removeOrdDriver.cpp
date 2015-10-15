/*Programming Exercises #6, page 530
Ryan Gens
Create a removeOrd function that removes an item, chosen by a user, from an ordered list without
leaving a empty space or duplicate number in the list. Add this function to the 
orderedArrayListType class and write a program to test it.
*/

#include "orderedArrayListType.h"
#include <iostream>

using namespace std;

void main(){
	int tempArray[] = {53, 22, 13, 54, 38, 76, 59, 31, 4, 98, 77, 68, 96 };
	int item;
	orderedArrayListType<int> intList((sizeof (tempArray) / sizeof (tempArray[0])));

	// Create the list.
	for (int i = 0; i < (sizeof (tempArray) / sizeof (tempArray[0])); i++){
		intList.insertOrd(tempArray[i]);
	}

	// Print the contents of the list.
	cout << "The list contains the following items:" << endl;
	intList.print();

	// Prompt the user for the item they wish to remove, and remove it from the list.
	cout << "Please enter the number you would like to remove from the list." << endl;
	cin >> item;
	cin.get();
	intList.removeOrd(item);

	// Print the list
	cout << endl << "The list contains the following items:" << endl;
	intList.print();

	// End
	cout << endl << "Press enter to end the program." << endl;
	cin.get();
}