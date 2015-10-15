/*Programming Exercises #6, page 530
Ryan Gens
Create a removeOrd function that removes an item, chosen by a user, from an ordered list without
leaving a empty space or duplicate number in the list. Add this function to the
orderedArrayListType class and write a program to test it.
*/

#ifndef ORDEREDARRAYLISTTYPE_H
#define ORDEREDARRAYLISTTYPE_H

#include "arrayListType.h"

using namespace std;

template<class elemType>
class orderedArrayListType : public arrayListType<elemType>{
public:
	orderedArrayListType(int size = 100);
	int binarySearch(const elemType& item) const;
	void insertOrd(const elemType& insertItem);
	void removeOrd(const elemType& removeItem);
};
#endif

template<class elemType>
int orderedArrayListType<elemType>::binarySearch(const elemType& item) const{
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;
	while (first <= last && !found){
		mid = (first + last) / 2;
		if (list[mid] == item)
			found = true;
		else if (list[mid] > item)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		return mid;
	else{
		mid = -1;
		return mid;
	}
		
}
template<class elemType>
void orderedArrayListType<elemType>::insertOrd(const elemType& item){
	int first = 0;
	int last = length - 1;
	int mid;

	bool found = false;

	if (length == 0){
		list[0] = item;
		length++;
	}
	else if (length == maxSize)
		cerr << "Cannot insert into a full list." << endl;
	else{
		while (first <= last && !found){
			mid = (first + last) / 2;
			if (list[mid] == item)
				found = true;
			else if (list[mid] > item)
				last = mid - 1;
			else
				first = mid + 1;
		}
	
	if (found)
		cerr << "The insert item is already in the list. Duplicates are not allowed." << endl;
	else{
		if (list[mid] < item)
			mid++;
		insertAt(mid, item);
		}
	}
}
template<class elemType>
orderedArrayListType<elemType>::orderedArrayListType(int size = 0)
:arrayListType(size){}

//**********************************************************************************
// removeOrd-- Removes and item from the orderd list without leaving an open space.
//**********************************************************************************
template<class elemType>
void orderedArrayListType<elemType>::removeOrd(const elemType& removeItem){
	removeAt(binarySearch(removeItem));
}