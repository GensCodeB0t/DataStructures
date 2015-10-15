/*Programming Exercises #6, page 596
Ryan Gens
Create a driver program that demonstrates the use of the Quicksort method described in
Chapter 10.
*/
#include "arrayListType.h"
#include <iostream>

using namespace std;

void main(){
	int testArray[] = { 23, 34, 45, 56, 67, 78, 89, 13, 42, 35, 57, 68, 79 };
	int userItem, position;
	arrayListType<int> qSortList;

	// Populate the list with the items in the array.
	for (int i = 0; i < (sizeof(testArray)) / sizeof(testArray[0]); i++)
		qSortList.insert(testArray[i]);

	// Display the contents of the initial list
	cout << "The list contains the following items." << endl;
	qSortList.print();

	// Sort the list using the quicksort function 
	// and display the sorted list.
	cout << endl << "The sorted list = " << endl;
	qSortList.quickSort();
	qSortList.print();

	// Prompt the user for an item to remove from the list.
	cout << endl << "Please enter the item you would like to remove from the list." << endl;
	cin >> userItem;
	cin.get();
	position = qSortList.seqSearch(userItem);
	qSortList.removeAt(position);
	// If the item is in the list, remove it and display the new list.
	if (position >= 0){
		cout << "The item you are trying to remove is at position " << position << "." << endl;
		qSortList.print();
	}

	// Prompt the user for an item to be added to the list,
	// add the item to the end of the list, and display the new list.
	cout << endl << "Please enter the an integer you would like to added to the list." << endl;
	cin >> userItem;
	cin.get();
	qSortList.insertEnd(userItem);
	cout << "The new list = " << endl;
	qSortList.print();
	// Sort the list and display the results
	cout << "The new sorted list = " << endl;
	qSortList.quickSort();
	qSortList.print();

	// End the program.
	cout << endl << "Press enter to end the program." << endl;
	cin.get();
}