// WEEK 4:
/* Create an integer vector without specifying its size.  Use the push_back function
to insert seven elements into the vector object.  Write a routine which will reverse
the elements within the same vector object without creating a new vector.  For example,
if the list contains the values 1, 2, 3, 4, 5, 6, and 7, the result will be a
list of 7, 6, 5, 4, 3, 2, 1.  Complete the program to adequately test the routine.
The reverse function which is part of the C++ library may not be used in the solution.
*/
// Ryan Gens
#include <iostream>
#include <vector>

using namespace std;

void main()
{
	vector<int> revVect;
	vector<int>::iterator revVectIt;
	vector<int>::iterator fwdVectIt;

	// Create a vector using the push_back function that
	// contains the numbers 1 - 7.
	for (int i = 1; i < 8; i++)
	{
		revVect.push_back(i);
	}

	// Print the forward vector
	cout << "Forward Vector elements: " << endl;
	for (revVectIt = revVect.begin(); revVectIt < revVect.end(); revVectIt++)
	{
		cout << *revVectIt << endl;
	}

	// Reverse the order of the vector by using 2 iterators.
	// RevVectIt points at the last element in the vector, inserts it 
	// at the position of the fwdVect iterator, and deletes the last element
	// after it's inserted. fwdVect is incremented after each insertion.
	for (unsigned int i = 0; i < revVect.size(); i++)
	{
		revVectIt = revVect.end()-1;
		fwdVectIt = revVect.begin();
		revVect.insert(fwdVectIt + i, *revVectIt);
		revVectIt = revVect.end() - 1;
		revVect.erase(revVectIt);
	}

	// Print reversed vector
	cout << "Reversed Vector elements: " << endl;
	for (revVectIt = revVect.begin(); revVectIt < revVect.end(); revVectIt++)
	{
		cout << *revVectIt << endl;
	} 

	cout << "Press enter to quit." << endl;
	cin.get();
}