/*Programming Exercises #3, page 447
Ryan Gens
Add a reverseStack function to the stackType class that copies a passed stack in reverse order without changing its contents.
*/
#include "stackType.h"
#include <iostream>
using namespace std;

void main(){
	int intArray[] = { 34, 23, 36, 65, 77, 66, 22, 958, 534, 1002 };
	int stackSize = (sizeof(intArray) / sizeof(intArray[0]));
	stackType<int> stack1;
	stackType<int> stack2;


	// Fill stack1.
	for (int i = 0; i < (sizeof(intArray) / sizeof(intArray[0])); i++){
		stack1.push(intArray[i]);
	}

	// Fill stack2 with the elements of stack1 in reverse order.
	stack2.reverseStack(stack1);

	//***************************************************************************
	// Print out the contents of stack2 (to prove stack1 is still populated.
	// The stack is empty after printing its contents because the pop function 
	// is used to increment to the next element in the stack.
	//***************************************************************************
	cout << "Stack 2 contained the following elements: \n";
	if (!stack2.isEmptyStack())
	do{
		cout << stack2.top() << endl;
		stack2.pop();
	} while (!stack2.isEmptyStack());
	else
		cout << "Nothing. The stack is empty!!!\n" << endl;

	//***************************************************************************
	// Print out the contents of stack1. 
	// The stack is empty after printing its contents because the pop function 
	// is used to increment to the next element in the stack.
	//***************************************************************************
	cout << endl << "Stack 1 contained the following elements: \n";
	if (!stack1.isEmptyStack())
	do{
		cout << stack1.top() << endl;
		stack1.pop();
	} while (!stack1.isEmptyStack());
	else
		cout << "Nothing. The stack is empty!!!\n";

	// End the program.
	cout << endl << "Both stacks are now empty, because the pop function was used to\n"
		<< "iterate thru the elements of the stacks during printing.\n"
		<< "Press enter to end the program.\n";

	cin.get();

}