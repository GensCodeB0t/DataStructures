// WEEK 4: Programming Exercises #3, page 259
// Find smallest, largest, and average of elements
// in a push_back created vector.
// Ryan Gens

#include <vector>
#include <iostream>

using namespace std;


void main()
{
	const int arraySize = 7;
	float smallest = 0, largest = 0 , average = 0;
	float tempArray[] = { 5.58, 4.32, 3.211, 9.76, 10.1, 11.752, 2.2 };
	// Create the vector and iterator
	vector<float> realVect;
	vector<float>::iterator realVectIt;

	// Insert elements of the array into the vector
	for (int i = 0; i < arraySize; i++)
	{
		realVect.push_back(tempArray[i]);
	}

	smallest = *realVect.begin();
	cout << "Elements in the Vector: " << endl;

	// Cyclce through the vector using the iterator to print the 
	// values in the vector, find the smallest value largest value, 
	// and the total of all the elements in the vector
	for (realVectIt =realVect.begin(); realVectIt != realVect.end(); realVectIt++)
	{
		cout << *realVectIt << endl;
		average += *realVectIt;
		smallest = (smallest < *realVectIt ? smallest : *realVectIt);
		largest = (largest > *realVectIt ? largest : *realVectIt);
	}
	// Find the average
	average /= realVect.size();

	// Print the values
	cout << endl << "The smallest number in the vector is : " << smallest << endl;
	cout << "The largest number in the vector is : " << largest << endl;
	cout << "The average of the numbers in the vector is : " << average << endl;

	cout << "Press enter to quit.";
	cin.get();
}