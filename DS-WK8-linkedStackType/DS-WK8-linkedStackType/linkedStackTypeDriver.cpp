/*Programming Exercises #4, page 447
Ryan Gens
Add a reverseStack function to the linkedStackType class that copies a passed stack in reverse order without changing its contents.
*/
#include "linkedStackType.h"
#include <iostream>

using namespace std;

void main(){
	linkedStackType<int> stack1;
	linkedStackType<int> stack2;
	int intArray[] = { 535, 767, 22, 17, 99, 76, 54, 432, 996 };

	// Fill stack1.
	for (int i = 0; i < (sizeof(intArray) / sizeof(intArray[0])); i++)
		stack1.push(intArray[i]);

	// Fill stack2 with the elements of stack1 in reverse order.
	stack2.reverseStack(stack1);

	//***************************************************************************
	// Print out the contents of stack2 (to prove stack1 is still populated.
	// The stack is empty after printing its contents because the pop function 
	// is used to increment to the next element in the stack.
	//***************************************************************************
	cout << "stack2 contained the following elements: \n";
	if (!stack2.isEmptyStack())
	while (!stack2.isEmptyStack())
	{
		cout << stack2.top() << endl;
		stack2.pop();
	}
	else
		cout << "Nothing, the stack was empty.\n";

	//***************************************************************************
	// Print out the contents of stack1. 
	// The stack is empty after printing its contents because the pop function 
	// is used to increment to the next element in the stack.
	//***************************************************************************
	cout << endl << "stack1 contained the following elements: \n";
	if (!stack1.isEmptyStack())
	while (!stack1.isEmptyStack())
	{
		cout << stack1.top() << endl;
		stack1.pop();
	}
	else
		cout << "Nothing, the stack was empty.\n";

	// End the program.
	cout << endl << "Both stacks are now empty, because the pop function was used to\n"
		<< "iterate thru the elements of the stacks during printing.\n"
		<< "Press enter to end the program.\n";
	cin.get();
}