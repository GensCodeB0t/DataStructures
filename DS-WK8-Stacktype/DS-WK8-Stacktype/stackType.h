/*Programming Exercises #3, page 447
Ryan Gens
Add a reverseStack function to the stackType class that copies a passed stack in reverse order without changing its contents.
*/
#ifndef STACKTYPE_H
#define STACKTYPE_H
#include<iostream>
#include <assert.h>
#include "stackADT.h"

template <class Type>
class stackType : public stackADT<Type>{
public:
	const stackType<Type>& operator=(const stackType<Type>&);
	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;
	void push(const Type& newItem);
	Type top() const;
	void pop();
	void reverseStack(stackType<Type>& otherStack);
	stackType(int stackSize = 100);
	stackType(const stackType<Type>& otherStack);
	~stackType();
private:
	int maxStackSize;
	int stackTop;
	Type *list;

	void copystack(const stackType<Type>& otherStack);
};
#endif

template <class Type>
void stackType<Type>::initializeStack(){
	stackTop = 0;
}
template <class Type>
bool stackType<Type>::isEmptyStack() const{
	return (stackTop == 0);
}
template <class Type>
bool stackType<Type>::isFullStack() const{
	return(stackTop == maxStackSize);
}
template <class Type>
void stackType<Type>::push(const Type& newItem){
	if (!isFullStack()){
		list[stackTop] = newItem;
		stackTop++;
	}
	else
		cout << "Cannot add to a full stack" << endl;
}
template <class Type>
Type stackType<Type>::top() const{
	assert(stackTop != 0);
	return list[stackTop - 1];
}
template <class Type>
void stackType<Type>::pop(){
	if (!isEmptyStack())
		stackTop--;
	else
		cout << "Cannot remove from an empty stack." << endl;
}
template <class Type>
void stackType<Type>::copystack(const stackType<Type>& otherStack){
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new Type[maxStackSize];

	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
}
template <class Type>
stackType<Type>::stackType(int stackSize ){
	if (stackSize <= 0){
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize;
	stackTop = 0;
	list = new Type[maxStackSize];
}
template <class Type>
stackType<Type>::~stackType(){
	delete[] list;
}
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack){
	list = NULL;
	copystack(otherStack);
}
template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack){
	if (this != &otherStack)
		copyStack(otherStack);

	return *this;
}
template <class Type>
//****************************************************************
// reverseStack-- Copies the elements of otherStack in reverse 
// order. Upon completetion, otherStack remains unchanged.
//****************************************************************
void stackType<Type>::reverseStack(stackType<Type>& otherStack){
	delete[] list;
	initializeStack();
	maxStackSize = otherStack.maxStackSize;
	int stackIndex = otherStack.stackTop;
	list = new Type[maxStackSize];

	for (int j = (stackIndex - 1); j >= 0; j--)
		push(otherStack.list[j]);		
}