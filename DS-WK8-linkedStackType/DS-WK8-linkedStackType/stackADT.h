/*Programming Exercises #4, page 447
Ryan Gens
Add a reverseStack function to the stackType class that copies a passed stack in reverse order without changing its contents.
*/
#ifndef STACKADT_H
#define STACKADT_H

template<class Type>
class stackADT{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};
#endif