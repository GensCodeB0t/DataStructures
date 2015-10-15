/*Programming Exercises #11, page 596
Ryan Gens
Create a driver program that demonstrates the use of the Heapsort method described in 
Chapter 10.
*/
#include "arrayListType.h"
#include <iostream>

using namespace std;

void main(){
	int testArray[] = { 23, 34, 45, 56, 67, 78, 89, 13, 42, 35, 57, 68, 79 };
	int userItem, position;
	arrayListType<int> hSortList;

	// Populate the list with the contents of the array.
	for (int i = 0; i < (sizeof(testArray)) / sizeof(testArray[0]); i++)
		hSortList.insert(testArray[i]);

	// Display the the contents of the list.
	cout << "The list contains the following items." << endl;
	hSortList.print();

	// Sort the list using the heapsort function and display the results.
	cout << endl << "The sorted list = " << endl;
	hSortList.heapSort();
	hSortList.print();

	// Prompt the user for an item to be removed from the list.
	cout << endl << "Please enter the item you would like to remove from the list." << endl;
	cin >> userItem;
	cin.get();
	position = hSortList.seqSearch(userItem);
	hSortList.removeAt(position);
	// If the item is in the list display its position in the list and the contents of the new list.
	if (position >= 0){
		cout << "The item you are trying to remove is at position " << position << "." << endl;
		hSortList.print();
	}

	// Prompt the user for an item to add to the list, add the item to the end of the list,
	// and display the new list.
	cout << endl << "Please enter the an integer you would like to added to the list." << endl;
	cin >> userItem;
	cin.get();
	hSortList.insertEnd(userItem);
	cout << "The new list = " << endl;
	hSortList.print();
	// Sort the list using the heapsort function and display the sorted list.
	cout << "The new sorted list = " << endl;
	hSortList.heapSort();
	hSortList.print();

	// End the program.
	cout << endl << "Press enter to end the program." << endl;
	cin.get();
}