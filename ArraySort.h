//----------------------------------------------------------------------------
//	File: ArraySort.h
//
//	class: ArraySort
//----------------------------------------------------------------------------
#ifndef ARRAYSORT_H
#define ARRAYSORT_H
#include <iostream>
#include "DateTime.h"
using namespace std;
using namespace AW_DATETIME;
//----------------------------------------------------------------------------
// File:		ArraySort.h
// Class:		ArraySort
// Description: Function outlines for the ArraySort class
// 
// Programmer:	Anthony Waddell
// Version:          1.0
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015
//
// Properties:	None
//
// Functions:   
//				Inline: N/A
//				
//				Non-Inline:
//				void quickSort(Comparable** from, Comparable** to);
//					Optimized quicksort function
//				Comparable** partition(Comparable** from, Comparable** to);
//					Divides array in two with all objects to right being 
//					larger than the midle item and all objects to the left
//					being smaller
//				void SortFirstMiddleLast
//				(Comparable** from, Comparable** mid, Comparable** to);
//					Arranges forst, middle, and last objects in ascending
//					order to bprepare for sorting
//				void insertionSort(Comparable** from, Comparable** to);
//					Sorting algorithm for arrays smaller than 4 in size
//				void safeRead(istream& sin, Comparable* d, const char* prompt)
//					Safely reads from console into a Comparable or derived
//					class object
//				void printArray(ostream & sout, Comparable **a, int size);
//					Prints array to console
// 
// History Log:	04-07-17 AW Included in Project
//
// Known Bugs:  *** Optimized quisksort function of ArraySort class returning
//				improperly sorted arrays ***
//---------------------------------------------------------------------------

namespace AW_ARRAYSORT
{	
	const int USEROFFSET = 1;
	void quickSort(Comparable** from, Comparable** to);
	Comparable** partition(Comparable** from, Comparable** to);	
	void SortFirstMiddleLast(Comparable** from,
		Comparable** mid, Comparable** to);	
	void insertionSort(Comparable** from, Comparable** to);
	void safeRead(istream& sin, Comparable* d, const char* prompt);
	void printArray(ostream & sout, Comparable **a, int size);
}
#endif