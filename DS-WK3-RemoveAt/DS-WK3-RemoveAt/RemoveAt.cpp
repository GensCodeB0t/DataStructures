// WEEK 3: Programming Exercise #1, page 204
// Modify the removeAt member function to replace
// the item at location with the item at the end of
// the list.
// Ryan Gens

template < class elemType>
void arrayListType<elemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cerr << "The Location of the item to be removed "
			<< "is out of range." << endl;
	else
	{
		if (length > 1)
			list[location] = list[length];
		else
		{
			list[location] = 0;
		}
		length--;
	}
}
