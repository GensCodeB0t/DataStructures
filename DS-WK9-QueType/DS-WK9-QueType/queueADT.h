/*Programming Exercises #4, page 495
Ryan Gens
Add a moveNthFront function to the queueType class, that moves the element in the queue at the nth position (user input)
to the front of the queue, while keeping the order of the other elements the same.
Create a driver program.
*/
#ifndef QUEUEADT_H
#define QUEUEADT_H

template<class Type>
class queueADT{
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;
	virtual Type front() const = 0;
	virtual Type back() const = 0;
	virtual void addQueue(const Type& queueElement) = 0;
	virtual void deleteQueue() = 0;
};
#endif