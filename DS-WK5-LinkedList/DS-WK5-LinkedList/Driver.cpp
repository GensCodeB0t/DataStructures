/*Programming Exercises #3, page 349, and #7, page 351
For #3, think of nth element rather than kth element, i.e., locate the element (not the value) indicated by the user and remove it.
If you use the orderedLinkedList class for both 3 and 7, the solutions may be combined within a single program
*/
#include <iostream>
#include "orderedLinkedList.h"

using namespace std;

void main(){
	int intArray[] = { 1, 44, 35, 25, 432, 578, 43, 678, 9, 7, 66 };
	int element;
	orderedLinkedList<int> intList;
	
	// Populate the list and print the results.
	for (int i = 0; i < (sizeof(intArray)/sizeof(intArray[0])); i++){
		intList.insertLast(intArray[i]);
	}
	intList.print();

	// Prompt the user to remove an element.
	cout << "Please enter the number of the element you would like to remove from the list.\n"
		<< "The elements range from 0 to " << intList.length() << endl;
	cin >> element;
	cin.get();
	intList.deleteElem(element);
	cout << "The new list = \n";
	intList.print();

	// Prompt the user to return an element's value.
	cout << "Please enter the number of the element you would like to return from the list.\n"
		<< "The elements range from 0 to " << intList.length() << endl;
	cin >> element;
	cin.get();
	cout << "The element info = \n" << intList.returnElem(element) << endl;

	// Prompt the user to insert an item into the list.
	cout << "Please enter the item you would like to insert into the list." << endl;
	cin >> element;
	cin.get();
	intList.insert(element);
	cout << "The new list = \n";
	intList.print();

	// Exit the program.
	cout << "Please press enter to exit the program." << endl;
	cin.get();
	
}