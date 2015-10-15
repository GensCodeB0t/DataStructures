/*Programming Exercises #3, page 349, and #7, page 351
For #3, think of nth element rather than kth element, i.e., locate the element (not the value) indicated by the user and remove it.
If you use the orderedLinkedList class for both 3 and 7, the solutions may be combined within a single program
*/

#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include "linkedListType.h"



using namespace std;

template <class type>
class orderedLinkedList : public linkedListType<type>
{
public:
	void insert(const type& newItem);	// Compares the values in the list against a user's input and inserts the item if it is not already in the list.
	void deleteElem(const int elemPos);	// Removes an element from the list based on user's input.
	bool search(const type& searchItem)const;
	void insertFirst(const type& newItem);
	void insertLast(const type& newItem);
	void deleteNode(const type& deleteItem);
};

//******************************************************************************
// deleteElem-- Removes an item from the list based on the user inputed element.
//******************************************************************************
template <class type>
void orderedLinkedList<type>::deleteElem(const int elemPos)
{
	if (elemPos < 0 || elemPos >= length())
		cerr << "The element you are trying to delete is not in the list.\n";
	else
	{

		nodeType<type> *current;
		nodeType<type> *trail;
		current = first;
		trail = first;


		for (int index = 0; index != elemPos; index++){
			if (index < elemPos)
				trail = current;
			current = current->link;
		}


		if (current == first)
			first = current->link;
		else if (current == last)
		{
			trail->link = NULL;
			last = trail;
		}
		else
			trail->link = current->link;

		count--;
	}
}

template <class type>
bool orderedLinkedList<type>::search(const type& searchItem) const
{
	bool found = false;
	nodeType<type> *current;
	current = first;
	while (current != NULL && !found)
	{
		if (current->info >= searchItem)
			found = true;
		else
			current = current->link;

		if (found)
			found = (current->info == searchItem);
	}
	return found;
}

//******************************************************************************
// search-- Compares the values in the list against a user's input and inserts 
// the item if it is not already in the list.
//******************************************************************************
template <class type>
void orderedLinkedList<type>::insert(const type& newItem)
{
	nodeType<type> *current;
	nodeType<type> *trailCurrent;
	nodeType<type> *newNode;

	bool found, itemFound = false;

	newNode = new nodeType<type>;
	newNode->info = newItem;
	newNode->link = NULL;

	if (first == NULL)
	{
		first = newNode;
		last = newNode;
		count++;
	}
	else
	{
		current = first;
		found = false;

		while (current != NULL && !found)
		if (current->info >= newItem){
			found = true;
			// Check if the item being inserted in already in the list.
			if (current->info == newItem){
				cerr << "The item being insert is already in the list." << endl;
				itemFound = true;
			}

		}
		else
		{
			trailCurrent = current;
			current = current->link;
		}

		if (!itemFound)		// If the item is in the list, exit the function.
			if (current == first)
			{
				newNode->link = first;
				first = newNode;
				count++;
			}
			else
			{
				trailCurrent->link = newNode;
				newNode->link = current;
				if (current == NULL)
					last = newNode;
			count++;
		}
	}
}

template <class type>
void orderedLinkedList<type>::insertFirst(const type& newItem)
{
	insert(newItem);
}

template <class type>
void orderedLinkedList<type>::insertLast(const type& newItem)
{
	insert(newItem);
}

template <class type>
void orderedLinkedList<type>::deleteNode(const type& deleteItem)
{
	nodeType<type> *current;
	nodeType<type> *trailCurrent;
	bool found;

	if (first == NULL)
		cerr << "Cannot delete from an empty list." << endl;
	else
	{
		current = first;
		found = false;

		while (current != NULL && !found)
		if (current->info >= deleteItem)
			found = true;
		else
		{
			trailCurrent = current;
			current = current->link;
		}
		if (current == NULL)
			cerr << "The item to be deleted is not in the list." << endl;
		else
		if (current->info == deleteItem)
		{
			if (first == current)
			{
				first = first->link;
				if (first == NULL)
					last = NULL;
				delete current;
			}
			else
			{
				trailCurrent->link = current->link;

				if (current == last)
					last = trailCurrent;

				delete current;
			}
			count--;
		}
		else
			cerr << "The item to be deleted is not in the list" << endl;
	}
}
#endif

