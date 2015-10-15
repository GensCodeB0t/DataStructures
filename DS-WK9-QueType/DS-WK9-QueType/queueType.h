/*Programming Exercises #4, page 495
Ryan Gens
Add a moveNthFront function to the queueType class, that moves the element in the queue at the nth position (user input)
to the front of the queue, while keeping the order of the other elements the same.
Create a driver program.
*/
#ifndef QUEUETYPE_H
#define QUEUETYPE_H
#include "queueADT.h"
#include <assert.h>
#include <iostream>

template <class Type>
class queueType : public queueADT<Type>{
public:
	const queueType<Type>& operator= (const queueType<Type>&);
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	// Added function
	void moveNthFront(int element);
	// Added print queue contents
	void printQueue() const;
	Type front() const;
	Type back() const;
	void addQueue(const Type& queueElement);
	void deleteQueue();
	queueType(int queueSize = 100);
	queueType(const queueType& otherQueue);
	~queueType();
private:
	int maxQueueSize;
	int count;
	int queueFront;
	int queueRear;
	Type *list;
	// Added recursion function
	void moveRecursion(int element, int index = 0);	
};
#endif

template <class Type>
bool queueType<Type>::isEmptyQueue() const{
	return (count == 0);
}
template <class Type>
bool queueType<Type>::isFullQueue() const{
	return (count == maxQueueSize);
}
template <class Type>
void queueType<Type>::initializeQueue(){
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
}
template <class Type>
Type queueType<Type>::front() const{
	assert(!isEmptyQueue());
	return list[queueFront];
}
template <class Type>
Type queueType<Type>::back() const{
	assert(!isEmptyQueue());
	return list[queueRear];
}
template <class Type>
void queueType<Type>::addQueue(const Type& newElement){
	if (!isFullQueue()){
		queueRear = (queueRear + 1) % maxQueueSize;
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
}
template <class Type>
void queueType<Type>::deleteQueue(){
	if (!isEmptyQueue()){
		count--;
		queueFront = (queueFront + 1) % maxQueueSize;
	}
	else
		cout << "Cannot remove from an empty queue." << endl;
}
template <class Type>
queueType<Type>::queueType(int queueSize){
	if (queueSize <= 0){
		cout << "Size of the array to hold the queue must"
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize;
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
	list = new Type[maxQueueSize];
}
template <class Type>
queueType<Type>::~queueType(){
	delete[] list;
}

//**********************************************************************************
// moveNthFron -- Moves the element selected via user input to the front of the
// queue. In this case I chose to use recursion, so I could get some more practice
// using the technique. Since the queue is relatively small and made up of integers,
// memory should not be an issue (I also tried to define as few local variables as
// possible. moveNtheFront calls the private recursion function to maintain 
// encapsulation, which was in danger if the moveNthFront function would have hosted
// the recursion, becuase the user of the moveNtheFront function would have access 
// to the index variable. 
//***********************************************************************************
template <class Type>
void queueType<Type>::moveNthFront(int element) {
	if (!isEmptyQueue()){
		if (element < count && element >= 0){
			Type frontElem = list[element];
			moveRecursion(element);
			list[queueFront] = frontElem;
		}
		else
			cout << "The element that you have selected to move is not in the queue." << endl << endl;
	}
	else
		cout << "Cannot move an element in an empty queue." << endl << endl;
}
template <class Type>
void queueType<Type>::moveRecursion(int element, int index){
	if (((queueFront + index) % maxQueueSize) != element){
		moveRecursion(element, ++index);
		if (index != 0)
			list[((queueFront + (index)) % maxQueueSize)] = list[((queueFront + index - 1) % maxQueueSize)];
	}
}
//**********************************************************************************
// printQueue -- This function prints the contents of the queue. I added this 
// function in order to maintain simplicity in the queueDriver.cpp source.
//***********************************************************************************
template <class Type>
void queueType<Type>::printQueue() const{
	if (!isEmptyQueue()){
		for (int index = 0; ((queueFront + index) % maxQueueSize) != queueRear + 1; index++)
			cout << "index [" << index << "] =  " <<list[queueFront + index] << endl;
	}
	else
		cout << "The queue is empty.\n";
	cout << endl;
}