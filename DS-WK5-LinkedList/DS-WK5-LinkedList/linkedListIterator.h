/*Programming Exercises #3, page 349, and #7, page 351
For #3, think of nth element rather than kth element, i.e., locate the element (not the value) indicated by the user and remove it.
If you use the orderedLinkedList class for both 3 and 7, the solutions may be combined within a single program
*/
#ifndef LINKEDLISTITERATOR_H
#define LINKEDLISTITERATOR_H
#include "nodeType.h"

using namespace std;

template<class type>
class linkedListIterator
{
public:
	linkedListIterator();
	linkedListIterator(nodeType<type> *ptr);
	type operator* ();
	linkedListIterator<type> operator++();
	bool operator == (const linkedListIterator<type>& right) const;
	bool operator != (const linkedListIterator<type>& right) const;
private:
	nodeType<type> *current;
};



template <class type>
linkedListIterator<type>::linkedListIterator()
{
	current = NULL;
}
template <class type>
linkedListIterator<type>::linkedListIterator(nodeType<type> *ptr)
{
	current = ptr;
}
template <class type>
type linkedListIterator<type>::operator*()
{
	return current->info;
}
template <class type>
linkedListIterator<type> linkedListIterator<type>:: operator++()
{
	current = current->link;
	return *this;
}
template <class type>
bool linkedListIterator<type>:: operator ==(const linkedListIterator<type>& right) const
{
	return (current == right.current);
}
template <class type>
bool linkedListIterator<type>:: operator !=(const linkedListIterator<type>& right) const
{
	return (current != right.current);
}
#endif

