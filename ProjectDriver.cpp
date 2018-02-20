//----------------------------------------------------------------------------
// File:		ProjectDriver.cpp
// 
// Description: Test Driver for the Comparable class
// 
// Programmer:  Anthony Waddell
//
// Functions:   main()
// 
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015
//--------------------------------------------------------------------------
#include "CTime.h"
#include "Date.h"
#include "DateTime.h"
#include "Comparable.h"
#include "ArraySort.h"
using namespace std;
//----------------------------------------------------------------------------
//
// Function:	main()
// Title:		Using Comparable class
// Description: This file contains function main() which tests the Comparable
//				abstract base class
//
// Programmer:	Anthony Waddell
// Date:		04-25-17
// Version:		1.0
//  
// Environment: Hardware: PC, i7
//				Software: OS: Windows 10 
//				Compiles under Microsoft Visual C++ 2015
// 
// Input:		User supplied values for Date, CTime, and DateTime objects from
//				console to Comparaed and sorted
// Output:		Sorted arrays of user supplied objects
// Calls:		Cpmarable abstract base class and it's derived classes 
// Called By:	n/a
// Parameters:  None
// Returns:		EXIT_SUCCESS  upon successful execution
//
// History Log:
//					04-07-17 AW Began Project
//					04-27-17 AW completed project
// Known Bugs:  *** Optimized quisksort function of ArraySort class returning
//				improperly sorted arrays ***
//----------------------------------------------------------------------------

int main(void)
{
	using AW_DATETIME::CTime;
	using AW_DATETIME::Date;
	using AW_DATETIME::DateTime;
	using AW_DATETIME::Comparable;
	using namespace AW_ARRAYSORT;

	CTime userTime;
	Date userDate(1, 1, 1);
	DateTime rightNow;
	DateTime userDateTime;
	int inputQuantity;
	int userOffset = 1;

	cout << "The current date and time is: " << endl << rightNow << 
		endl << endl;
	cout << "enter a time (hh:mm:ss): ";
	cin >> userTime;
	cout << userTime << endl << endl;
	cout << "Enter the number of date/times you wish to enter: ";
	cin >> inputQuantity;
	cin.get();
	Comparable** m_array = new Comparable*[inputQuantity];

	//Set up and fill array with DateTime objects
	try
	{
		for (int i = 0; i < inputQuantity; i++)
		{
			cout << "Enter date/time " << (i + 1) 
				<< ": (dd/mm/yyyy hh:mm:ss) ";
			cin >> userDateTime;
			m_array[i] = nullptr;
			m_array[i] = new DateTime(userDateTime);
		}
	}
	catch (exception e)
	{
		cerr << "exception: " << e.what() << endl;
		cout << "shutting down" << endl;
		cin.ignore(FILENAME_MAX, '\n');
		exit(EXIT_FAILURE);
	}

	//Sort and print array of DateTime objects
	cout << endl;
	quickSort(m_array, (m_array + inputQuantity) - userOffset);
	printArray(cout, m_array, inputQuantity);

	//Set up and fill array with Date objects
	cout << "Re-fill the array with dates only: " << endl;
	try
	{
		for (int i = 0; i < inputQuantity; i++)
		{
			cout << "Enter date " << (i + 1) << ": (dd/mm/yyyy) ";
			cin >> userDate;
			m_array[i] = nullptr;
			m_array[i] = new Date(userDate);
		}
	}
	catch (exception e)
	{
		cerr << "exception: " << e.what() << endl;
		cout << "shutting down" << endl;
		cin.ignore(FILENAME_MAX, '\n');
		exit(EXIT_FAILURE);
	}

	//Sort and print array of Date objects
	cout << endl;
	quickSort(m_array, (m_array + inputQuantity) - 1);
	printArray(cout, m_array, inputQuantity);
	cout << endl;

	//Print out day before first element in array and 
	//day after last element in array
	const Date &yesterday = dynamic_cast<const Date&>(*m_array[0]);
	cout << "The day before the first day in the array is: " << endl <<
		yesterday.yesterday() << endl << endl;

	const Date &tomorrow =
		dynamic_cast<const Date&>(*m_array[inputQuantity - userOffset]);
	cout << "The day after the last day in the array is: " << endl << 
		tomorrow.tomorrow();

	//cleanup and prevent memory leaks
	for (int i = 0; i < inputQuantity; i++)
	{
		delete m_array[i];
	}
	delete[] m_array;

	cin.get();
	return EXIT_SUCCESS;
}
