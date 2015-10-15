/*Programming Exercises #4, page 495
Ryan Gens
Add a moveNthFront function to the queueType class, that moves the element in the queue at the nth position (user input)
to the front of the queue, while keeping the order of the other elements the same. 
Create a driver program.
*/
#include "queueType.h"
#include <iostream>

using namespace std;

void main(){
	int queueArray[] = { 5, 11, 34, 67, 43, 55 };
	int nElement;
	queueType<int> workingQueue;

	// Populate the queue from the queueArray contents defined above.
	for (int i = 0; i < (sizeof(queueArray) / sizeof(queueArray[0])); i++)
		workingQueue.addQueue(queueArray[i]);

	// Print the contents of the queue.
	cout << "The queue contains the following elements: " << endl;
	workingQueue.printQueue();

	// Prompt the user for the element they wish to move to the front of the queue.
	cout << "Please enter the index number of the element you wish to move to the font of the queue.\n";
	cin >> nElement;
	cin.get();

	// Move the element to the front of the queue.
	workingQueue.moveNthFront(nElement);

	// Print the new order of the queue.
	cout << "The new queue contains the following elements: " << endl;
	workingQueue.printQueue();

	// End the program.
	cout << "Press enter to end the program.\n";
	cin.get();
}