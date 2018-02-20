//----------------------------------------------------------------------------
//	File: DateTime.cpp
//
//	class: DateTime
//	methods:
//			ostream & operator<<(ostream & sout, const DateTime & dateTime)
//			istream & operator >> (istream & sin, DateTime & dateTime)
//	
//			void DateTime::input(istream & sin)
//			void DateTime::print(ostream & sout) const
//
//			bool DateTime::operator==(const Comparable & other) const
//			bool DateTime::operator<(const Comparable & other) const
//
//----------------------------------------------------------------------------
#include "DateTime.h"
namespace AW_DATETIME
{
	//------------------------------------------------------------------------
	// Class:		DateTime
	// Function:	ostream & operator<<(ostream & sout, 
	//					const DateTime & dateTime)
	// Title:		Overloaded output operator
	// Description: Overloaded output operator for the DateTime class
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		a DateTime object to console
	// Calls:		print(ostream& sout)const
	// Called By:	main()
	// Parameters:	ostream& sout; the designated output stream
	//				const DateTime & dateTime; the DateTime object to output
	//				to stream
	// Returns:		a reference to sout
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	ostream & operator<<(ostream & sout, const DateTime & dateTime)
	{
		dateTime.print(sout);
		return sout;
	}

	//------------------------------------------------------------------------
	// Class:		DateTime
	// Function:	istream & operator >> (istream & sout, 
	//					const DateTime & dateTime)
	// Title:		Overloaded input operator
	// Description: Overloaded input operator for the DateTime class
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		A DateTime object from console
	// Output:		N/A
	// Calls:		input(istream& sin)const
	// Called By:	main()
	// Parameters:	istream& sin; the designated input stream
	//				const DateTime & dateTime; the DateTime object input from
	//				the stream
	// Returns:		a reference to ssin
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	istream & operator >> (istream & sin, DateTime & dateTime)
	{
		dateTime.input(sin);
		return sin;
	}

	//------------------------------------------------------------------------
	// Class:		DateTime
	// Function:	void DateTime::input(istream & sin)
	// Title:		Input function
	// Description: Accepts and validates input from console for a DateTime
	//				object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-17-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		properties of a DateTime object provided by user, from 
	//				console
	// Output:		N/A
	// Calls:		Date::input(); input function from Date class
	//				CTime::input(); input function from CTime class
	//				DateTime(const Date &date, const CTime &time); constructor
	// Called By:	main()
	//				istream & operator >> (istream & sin, DateTime & dateTime)
	//				void safeRead(istream& sin, Comparable* d, 
	//					const char* prompt)
	// Parameters:	istream& sin; the designated input stream
	// Returns:		void
	// History Log: 04-17-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void DateTime::input(istream & sin)
	{
		string dateInput;
		string trimmedDateInput;
		string timeInput;
		string trimmedTimeInput;
		Date inputDate;
		CTime inputTime;
		char inputChar = ' ';

		//capture input for date and time
		getline(sin, dateInput, ' '); 
		getline(sin, timeInput);

		//Remove special characters to format Date Input
		for (unsigned int i = 0; i < dateInput.size(); i++)
		{
			inputChar = dateInput[i];
			if (inputChar == '0' || '1' || '2' || '3' || '4' || '5' || 
				'6' || '7' || '8' || '9' || '/')
				trimmedDateInput += inputChar;
		}

		//Remove special characters to format time input
		for (unsigned int i = 0; i < timeInput.size(); i++)
		{
			inputChar = timeInput[i];
			if (inputChar == '0' || '1' || '2' || '3' || '4' || '5' || 
				'6' || '7' || '8' || '9' || ':')
				trimmedTimeInput += inputChar;
		}

		//create date object
		stringstream ssDate(trimmedDateInput);
		inputDate.input(ssDate);

		//create time object
		stringstream ssTime(trimmedTimeInput);
		inputTime.input(ssTime);

		DateTime userDateTime(inputDate, inputTime);
		*this = userDateTime;
	}

	//------------------------------------------------------------------------
	// Class:		DateTime
	// Function:	void DateTime::print(ostream & sout) const
	// Title:		print function
	// Description: Prints out a DateTime object in specified format
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
	// Calls:		Date::print(); input function from Date class
	//				CTime::print(); input function from CTime class
	// Called By:	main()
	//				ostream & operator << (ostream & sout, DateTime & dateTime)
	// Parameters:	ostream & sout; the designated output stream
	// Returns:		void
	// History Log: 04-17-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void DateTime::print(ostream & sout) const
	{
		Date::print(sout);
		sout << "; ";
		CTime::print(sout);
	}

	//------------------------------------------------------------------------
	// Class:		DateTime
	// Function:	bool DateTime::operator==(const Comparable & other) const
	// Title:		Overloaded equals Comparison operator
	// Description: Determines if two DateTime objects are exactly the same
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
	// Calls:		DateTime(const Date &date, const CTime &time); constructor
	// Called By:	main()
	//				operator !=
	//				operator >
	// Parameters:	const Comparable & other; the DateTime object to be 
	//				compared against
	// Returns:		true if two objects are exactlly the same; false if not
	// History Log: 04-17-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	bool DateTime::operator==(const Comparable & other) const
	{
		bool returnValue = false;
		try
		{
			const DateTime &otherDateTime = 
				dynamic_cast<const DateTime&>(other);
			const Date &otherDate = dynamic_cast<const Date&>(other);
			if ((Date)(*this) == otherDate)
			{
				const CTime &otherTime = dynamic_cast<const CTime&>(other);
				if ((CTime)(*this) == otherTime)
				{
					returnValue = true;
				}
			}
		}
		catch (bad_cast e)
		{
		}
		return returnValue;
	}

	//------------------------------------------------------------------------
	// Class:		DateTime
	// Function:	bool DateTime::operator<(const Comparable & other) const
	// Title:		Overloaded less than Comparison operator
	// Description: Determines if one DatetIme object is less than another
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
	// Calls:		DateTime(const Date &date, const CTime &time); constructor
	// Called By:	main()
	//				operator >=
	//				operator >
	// Parameters:	const Comparable & other; the DateTime object to be 
	//				compared against
	// Returns:		true if two objects are exactlly the same; false if not
	// History Log: 04-17-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	bool DateTime::operator<(const Comparable & other) const
	{
		bool returnValue = false;
		try
		{
			const DateTime &otherDateTime = 
				dynamic_cast<const DateTime&>(other);
			const Date &otherDate = dynamic_cast<const Date&>(other);
			const CTime &otherTime = dynamic_cast<const CTime&>(other);

			if (((Date)(*this) < otherDate) ||
				(((Date)(*this) == otherDate) && 
				((CTime)(*this) < otherTime)))
			{
				returnValue = true;
			}
		}
		catch (bad_cast e)
		{
		}
		return returnValue;
	}
}