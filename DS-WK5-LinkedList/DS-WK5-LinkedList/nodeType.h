/*Programming Exercises #3, page 349, and #7, page 351
For #3, think of nth element rather than kth element, i.e., locate the element (not the value) indicated by the user and remove it.
If you use the orderedLinkedList class for both 3 and 7, the solutions may be combined within a single program
*/
#ifndef NODETYPE_H
#define NODETYPE_H

using namespace std;

template <class type>
struct nodeType
{
	type info;
	nodeType<type> *link;
};
#endif
