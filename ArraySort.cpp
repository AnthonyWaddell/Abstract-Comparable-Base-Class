//----------------------------------------------------------------------------
//	File: ArraySort.cpp
//
//	class: ArraySort
//	methods:
//				void quickSort(Comparable ** from, Comparable ** to)
//				Comparable ** partition(Comparable ** from, Comparable ** to)
//				void SortFirstMiddleLast
//					(Comparable ** from, Comparable ** mid, Comparable ** to)
//				void SortFirstMiddleLast
//					(Comparable ** from, Comparable ** mid, Comparable ** to)
//				void insertionSort(Comparable ** from, Comparable ** to)
//				void safeRead(istream& sin, Comparable* d, const char* prompt)
//				void printArray(ostream & sout, Comparable **a, int size)
//
//----------------------------------------------------------------------------
#include "ArraySort.h"
#include "Comparable.h"
namespace AW_ARRAYSORT
{
	using AW_DATETIME::Comparable;
	//-----------------------------------------------------------------------
	// Class:		ArraySort
	// Function:	void quickSort(Comparable** from, Comparable** to)
	// Title:		quicksort function
	// Description: Recursive optimized quicksort function to sort an array of
	//				Comparable objects; utilizes insertion sort on arrays of 
	//				size < 8
	//
	// Programmer:	Anthony Waddell
	// Date:		04-17-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		An array of comparable objects
	// Output:		A sorted array of Comparable objects from smallest to
	//				largest
	// Calls:		partition(Comparable ** from, Comparable ** to)
	//				quickSort(Comparable** from, Comparable** to); recursively
	//				insertionSort(Comparable ** from, Comparable ** to)
	// Parameters:	Comparable** from; the first element of the array
	//				Comparable** to; the last element of the array
	// Returns:		void
	// History Log: 04-17-17 AW Started v 0.1
	// Known Bugs:  *** Does not consistently sort arrays of Comparables. 
	//				Issue seems to be in partition function call ***
	//------------------------------------------------------------------------
	void quickSort(Comparable** from, Comparable** to)
	{
		
		int optimizedSortingThreshhold = 8;
		Comparable** mid = nullptr;
		int arrayLength = (int)((to + USEROFFSET) - from);

		if ((arrayLength) < optimizedSortingThreshhold)
		{
			insertionSort(from, to);
		}
		else
		{
			mid = partition(from, to);
			quickSort(from, mid);
			quickSort(mid + 1, to);
		}
	}

	//------------------------------------------------------------------------
	// Class:		ArraySort
	// Function:	Comparable ** partition
	//					(Comparable ** from, Comparable ** to)
	// Title:		Partition algorithm to divide array
	// Description: Partitions an array and return the middle element with 
	//				everything on the right of it being larger and everything
	//				on the left being smaller
	//
	// Programmer:	Anthony Waddell
	// Date:		04-17-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		SortFirstMiddleLast
	//				(Comparable ** from, Comparable ** mid, Comparable ** to)
	// Parameters:	Comparable** from; the first element of the array
	//				Comparable** to; the last element of the array
	// Returns:		Comparable **; the middle element (by value) of an array
	// History Log: 04-17-17 AW Started v 0.1
	//------------------------------------------------------------------------
	Comparable ** partition(Comparable ** from, Comparable ** to)
	{
		Comparable** front = from;
		Comparable** pivot = from + (to - from) / 2;
		Comparable** lastMinusOne = to - USEROFFSET;
		SortFirstMiddleLast(from, pivot, to);
		swap(*pivot, *(lastMinusOne));
		Comparable** back = (to - 2);

		front++; // advance to next element
		while (front < back)
		{
			// search forward for out of order element
			while (**pivot > **front)
				front++;
			//search backward for out of order element
			while (**pivot < **back)
				back--;
			swap(*front, *lastMinusOne);
		}
		swap(*front, *pivot);
		return(pivot);
	}

	//------------------------------------------------------------------------
	// Class:		ArraySort
	// Function:	void SortFirstMiddleLast
	//				(Comparable ** from, Comparable ** mid, Comparable ** to)
	// Title:		Arranges elements of an array
	// Description: Sorts the first, middle, and last elements passed in by
	//				ascending order
	//
	// Programmer:	Anthony Waddell
	// Date:		04-17-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Parameters:	Comparable** from; the first element of the array
	//				Comparable ** mid, middle element of the array
	//				Comparable** to; the last element of the array
	// Returns:		void
	// History Log: 04-17-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void SortFirstMiddleLast
	(Comparable ** from, Comparable ** mid, Comparable ** to)
	{
		if (**from > **mid)
		{
			swap(*from, *mid);
		}
		if (**mid > **to)
		{
			swap(*mid, *to);
		}
		if (**from > **mid)
		{
			swap(*from, *mid);
		}
	}

	//------------------------------------------------------------------------
	// Class:		ArraySort
	// Function:	void insertionSort(Comparable ** from, Comparable ** to)
	// Title:		Sorting Algorithm 
	// Description: Sorts an array of Comparable objects from least to 
	//				greatest order
	//
	// Programmer:	Anthony Waddell
	// Date:		04-17-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Parameters:	Comparable** from; the first element of the array
	//				Comparable** to; the last element of the array
	// Returns:		void
	// History Log: 04-27-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void insertionSort(Comparable ** from, Comparable ** to)
	{
		int size = (int)((to + USEROFFSET) - from);
		for (int i = 1; i < size; i++)
		{
			for (int j = i; j > 0; j--)
				if (**(from+ j) < **((from + j) - USEROFFSET))
					swap(*(from + j), *((from +j) - USEROFFSET));
				else break;
		}
	}

	//------------------------------------------------------------------------
	// Class:		ArraySort
	// Function:	void safeRead
	//					(istream& sin, Comparable* d, const char* prompt)
	// Title:		Reads into a Comparable object
	// Description: Safely allows a user to read into a Comparable object
	//
	// Programmer:	PB
	// Date:		04-17-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		User supplied values from console
	// Output:		N/A
	// Calls:		input()
	// Parameters:	istream& sin; the deignated input stream
	//				Comparable* d; the Comparable object to read into
	//				const char* prompt; the prompt for the user
	// Returns:		void
	// History Log: 04-27-17 AW included v 1.0
	//------------------------------------------------------------------------
	void safeRead(istream& sin, Comparable* d, const char* prompt)
	{
		const int BUFFERSIZE = 256;
		d->input(sin);
		while (!sin)
		{	// read in number--enter loop if fail
			sin.clear();		// clear fail
			sin.ignore(BUFFERSIZE, '\n');	// read past newline
			cout << prompt;  // re-prompt
			d->input(sin);
		}
		// read past newline once input succeeds
		sin.ignore(BUFFERSIZE, '\n');
	}

	//------------------------------------------------------------------------
	// Class:		ArraySort
	// Function:	void printArray(ostream & sout, Comparable **a, int size)
	// Title:		Prints array
	// Description: Prints out an array of Comparable objects
	//
	// Programmer:	PB
	// Date:		04-17-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		print()
	// Parameters:	(ostream & sout; the designated output stream
	//				Comparable **a; the array of pointers to Comparable 
	//					objects
	//				int size; the number of elements in the array
	// Returns:		void
	// History Log: 04-27-17 AW included v 1.0
	//------------------------------------------------------------------------
	void printArray(ostream & sout, Comparable **a, int size)
	{
		for (int i = 0; i < size; i++)
		{
			a[i]->print(sout);
			sout << endl;
		}
		sout << endl;
	}
}

