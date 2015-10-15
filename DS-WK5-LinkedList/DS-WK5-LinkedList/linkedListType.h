/*Programming Exercises #3, page 349, and #7, page 351
For #3, think of nth element rather than kth element, i.e., locate the element (not the value) indicated by the user and remove it.
If you use the orderedLinkedList class for both 3 and 7, the solutions may be combined within a single program
*/
#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include "linkedListIterator.h"
#include "linkedListType.h"
#include "nodeType.h"
#include <iostream>


using namespace std;

template <class type>
class linkedListType
{
public:
	const linkedListType<type> & operator=
		(const linkedListType<type>&);
	void intializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	type front() const;
	type back() const;
	type returnElem(const int elemPos) const;
	virtual void deleteElem(const int elemPos) =0;	// Removes an element from the list based on user input.
	virtual bool search(const type& searchItem)const = 0;
	virtual void insertFirst(const type& newItem) = 0;
	virtual void insertLast(const type& newItem) = 0;
	virtual void deleteNode(const type& deleteItem) = 0;
	linkedListIterator<type> begin();
	linkedListIterator<type> end();
	linkedListType();
	linkedListType(const linkedListType<type>& otherList);
	~linkedListType();
protected:
	int count;
	nodeType<type> *first;
	nodeType<type> *last;
private:
	void copyList(const linkedListType<type>& otherList);
};


template <class type>
const linkedListType<type> & linkedListType<type>:: operator =
(const linkedListType<type>& otherlist)
{
	if (this != &otherList)
		copyList(otherList);
	return *this;
}
template <class type>
void linkedListType <type>::intializeList()
{
	destroyList();
}
template <class type>
bool linkedListType <type>::isEmptyList() const
{
	return(first == NULL);
}
template <class type>
void linkedListType <type>::print() const
{
	nodeType<type> *current;
	current = first;
	while (current != NULL)
	{
		cout << current->info << " ";
		current = current->link;
	}
	cout << endl;
}
template <class type>
int linkedListType<type>::length() const
{
	return count;
}
template <class type>
void linkedListType<type>::destroyList()
{
	nodeType<type> *temp;

	while (first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
	count = 0;
}
template <class type>
type linkedListType<type>::front() const
{
	assert(first != NULL);
	return first->info;
}
template <class type>
type linkedListType<type>::back() const
{
	assert(last != NULL);
	return last->info;
}

template <class type>
type linkedListType <type>::returnElem(const int elemPos) const
{
	nodeType<type> *temp = first;
	if ((elemPos>0) && (elemPos< length()))
	{
		for (int i = 0; i != elemPos; i++)
		{
			temp = temp->link;
		}
		return temp->info;
	}
	else
	{
		exit(0);
	}
}

template <class type>
linkedListIterator<type> linkedListType<type>::begin()
{
	linkedListIterator<type> temp(first);
	return temp;
}

template <class type>
linkedListIterator<type> linkedListType<type>::end()
{
	linkedListIterator<type> temp(NULL);
	return temp;
}

template <class type>
linkedListType<type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}
template <class type>
linkedListType<type>::linkedListType(const linkedListType<type>& otherList)
{
	first = NULL;
	copyList(otherList);
}
template <class type>
linkedListType<type>::~linkedListType()
{
	destroyList();
}
#endif

