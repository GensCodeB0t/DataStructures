// WEEK 3: Programming Exercise #2, page 204
// Testing the removeAll member function
// Ryan Gens

#ifndef ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_H
#include <string>
#include <iostream>
using namespace std;

template <class elemType>
class arrayListType
{
public:
	arrayListType(int size);
	// Constructor: Function initializes the object. 

	void addItem(const elemType& elemItem);
	// Function adds an item to the list.
	// Postcondition: The formal parameter elemItem is added to the list
	// and the length of the list is increased.

	void printList();
	// Function prints the contents of the list

	void removeAll(const elemType& removeItem);
	// Function to remove elements containing data matching that of removeItem.
	// Postcondition: Matching elements are removed from the list and
	// the list length is decremented.

private:
	elemType *list;
	int listLength;
};

//****************************************************************************
// Constructor:
// Initializes the list length (number of elements in the list) and creates
// a new list object.
//****************************************************************************
template < class elemType>
arrayListType<elemType>::arrayListType(int size = 10)
{
	listLength = 0;
	list = new elemType[size];
}

//****************************************************************************
// addItem:
// Adds and item to the list.
//****************************************************************************
template < class elemType>
void arrayListType<elemType>::addItem(const elemType& elemItem)
{
	list[listLength] = elemItem;
	listLength++;
}

//****************************************************************************
// printList:
// Displays all the items in the list.
//****************************************************************************
template < class elemType>
void arrayListType<elemType>::printList()
{
	cout << "\nItems in your list:\n";
	for (int i = 0; i < listLength; i++)
	{
		cout << list[i] << endl;
	}
	cout << endl;
}

//****************************************************************************
// removeAll:
// Removes every instance of removeItem in the list, and replaces them with 
// the item at the end of the list.
//****************************************************************************
template < class elemType>
void arrayListType<elemType>::removeAll(const elemType& removeItem)
{
	for (int i = 0; i < listLength;)
	{
		if (list[i] == removeItem)
		{
			list[i] = list[(listLength-1)];
			listLength--;
		}
		else
		{
			i++;
		}
	}
}
#endif 

