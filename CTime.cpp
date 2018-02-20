//----------------------------------------------------------------------------
//	File: CTime.cpp
//
//	class: CTime
//	methods:
//			void CTime::setHour(short hour); mutator for m_hour
//			void CTime::setMinute(short minute); mutator for m_minute
//			void CTime::setSecond(short second); mutator for m_second
//			void CTime::setCurrentTime()
//			CTime::CTime(int hour, int minute, int second); constructor
//
//			void CTime::input(istream & sin)
//			void CTime::print(ostream & sout) const
//
//			bool CTime::operator==(const Comparable & other) const
//			bool CTime::operator<(const Comparable & other) const
//
//			ostream & operator<<(ostream & sout, const CTime & time)
//			istream & operator >> (istream & sin, CTime & time)	
//
//----------------------------------------------------------------------------
#include "CTime.h"
namespace AW_DATETIME
{
	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	void CTime::setHour(short hour) -- mutator
	// Title:		Sets the hour
	// Description: Validates and sets the m_hour of a CTime object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input: N/A
	// Output: N/A
	// Calls: N/A
	// Called By:	CTime::CTime(int hour, int minute, int second)
	//				main;
	// Parameters:	short hour; the hour			
	// Returns:		N/A
	// History Log: 04-05-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void CTime::setHour(short hour)
	{
		if (hour < 0 || hour > MAXHOUR)
			m_hour = 0;
		else
			m_hour = hour;
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	void CTime::setMinute(short minute) -- mutator
	// Title:		Sets the minute
	// Description: Validates and sets the m_minute of a CTime object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input: N/A
	// Output: N/A
	// Calls: N/A
	// Called By:	CTime::CTime(int hour, int minute, int second)
	//				main;
	// Parameters:	short minute; the minute
	//				
	// Returns:		N/A
	// History Log: 04-05-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void CTime::setMinute(short minute)
	{
		if (minute < 0 || minute > MAXMINSEC)
			m_minute = 0;
		else
			m_minute = minute;
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	void CTime::setSecond(short second) -- mutator
	// Title:		Sets the minute
	// Description: Validates and sets the m_second of a CTime object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input: N/A
	// Output: N/A
	// Calls: N/A
	// Called By:	CTime::CTime(int hour, int minute, int second)
	//				main;
	// Parameters:	short second; the second
	//				
	// Returns:		N/A
	// History Log: 04-05-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void CTime::setSecond(short second)
	{
		if (second < 0 || second > MAXMINSEC)
			m_second = 0;
		else
			m_second = second;
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	void CTime::setCurrentTime()
	// Title:		Sets the time from system clock
	// Description: Sets te time obejct to the current time from system clock
	//
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	constructor, mutators, input
	// Parameters:	N/A
	//				
	// Returns:		void
	// History Log: 04-05-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void CTime::setCurrentTime()
	{
		time_t rawtime;
		tm *currentTimePtr;
		time(&rawtime);
		currentTimePtr = localtime(&rawtime);

		m_hour = currentTimePtr->tm_hour;
		m_minute = currentTimePtr->tm_min;
		m_second = currentTimePtr->tm_sec;
	}

	//------------------------------------------------------------------------
	// Class: CTime
	// Function: CTime::CTime(int hour, int minute, int second) -- constructor
	// Title: Constructor with parameters
	// Description: Constructs a CTime object
	//
	// Programmer: Anthony Waddell
	// Date: 04-05-17
	// Version: 1.0
	//
	// Environment: Hardware: PC, i7
	// Software: OS: Windows 10 
	// Compiles under Microsoft Visual C++ 2015
	//
	// Input: N/A
	// Output: N/A
	// Calls: N/A
	// Called By: N/A
	// Parameters:  int hour; the hour
	//				int minute; the minute
	//				int second; the second
	// Returns: A CTime object
	// History Log: 04-05-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	CTime::CTime(int hour, int minute, int second)
	{
		setHour(hour);
		setMinute(minute);
		setSecond(second);
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	void CTime::input(istream & sin)
	// Title:		Inputs user supplied time
	// Description: Allows user to set the properties for a CTime object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		user properties for hour, minute and/or second of 
	//				CTime object
	// Output:		N/A
	// Calls:		setHour()
	//				setMinute()
	//				setSecond()
	//				setCurrentTime()
	// Called By:	istream & operator >>
	// Parameters:  istream & sin; reference to input stream
	// Returns:		void
	// History Log: 04-10-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void CTime::input(istream & sin)
	{
		string input;
		string sUserHour;
		string sUserMinute;
		string sUserSecond;
		short userHour;
		short userMinute;
		short userSecond;
		int count = 0;
		char inputChar = ' ';

		getline(sin, input);
		stringstream ss(input);
		for (unsigned int i = 0; i < input.size(); i++)
		{
			inputChar = input[i];
			if (inputChar == ':')
				count++;
		}
		(*this).setCurrentTime(); 
		switch (count)
		{
		case 0:
			getline(ss, sUserHour);
			if (sUserHour == "")
				break;
			userHour = atoi(sUserHour.c_str());
			(*this).setHour(userHour);
			break;
		case 1:
			//set the hour
			getline(ss, sUserHour, ':');
			userHour = atoi(sUserHour.c_str());
			(*this).setHour(userHour);
			//set the minute
			getline(ss, sUserMinute);
			userMinute = atoi(sUserMinute.c_str());
			(*this).setMinute(userMinute);
			break;
		case 2:
			//set hour
			getline(ss, sUserHour, ':');
			userHour = atoi(sUserHour.c_str());
			(*this).setHour(userHour);
			//set minute
			getline(ss, sUserMinute, ':');
			userMinute = atoi(sUserMinute.c_str());
			(*this).setMinute(userMinute);
			//set second
			getline(ss, sUserSecond);
			userSecond = atoi(sUserSecond.c_str());
			(*this).setSecond(userSecond);
			break;
		default:
			cout << "Invalid time inputted, using current time";
		}
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	void CTime::print(ostream & sout) const
	// Title:		overloaded print function for CTime class object
	// Description: Prints out a CTime object in "hh:mm:ss" format
	//
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		a CTime object to console
	// Calls:		N/A
	// Called By:	0stream & operator <<
	// Parameters:  istream & sin; reference to input stream
	// Returns:		void
	// History Log: 04-10-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void CTime::print(ostream & sout) const
	{

		sout << setw(2) << setfill('0') << m_hour << ":" << setw(2) <<
			setfill('0') << m_minute << ":" << setw(2) 
			<< setfill('0') << m_second;
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	bool CTime::operator==(const Comparable & other) const
	// Title:		Compares two CTime objects
	// Description:	Checks to see if two CTime objects are exactly the same
	// 
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	main, >=, <=
	// Parameters:  const Comparable &other -- the other CTime to compare
	// Returns:		True if the two objects are exactly the same; false if not
	// History Log: 04-05-17  AW  completed version 1.0
	//------------------------------------------------------------------------
	bool CTime::operator==(const Comparable & other) const
	{
		bool returnValue = false;
		try
		{
			const CTime &otherTime = dynamic_cast<const CTime&>(other);
			if (m_hour == otherTime.m_hour &&
				m_minute == otherTime.m_minute &&
				m_second == otherTime.m_second)
				returnValue = true;
		}
		catch (bad_cast e)
		{
		}
		return returnValue;
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	bool CTime::operator<(const Comparable & other) const
	// Title:		Overloaded less than compartive operator
	// Description: compares two times to see if one is less than the other
	//
	// Programmer:	Anthony Waddell
	// Date:		04-12-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	> operator
	//				>= operator
	// Parameters:	const Comparable & other; the time to be compared against
	// Returns:		true if this object is less than the other, false if not
	// History Log: 04-12-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	bool CTime::operator<(const Comparable & other) const
	{
		bool returnValue = false;
		try
		{
			const CTime &otherTime = dynamic_cast<const CTime&>(other);
			if ((m_hour < otherTime.m_hour) ||
				(m_hour == otherTime.m_hour && m_minute < otherTime.m_minute)||
				(m_hour == otherTime.m_hour && m_minute == otherTime.m_minute 
					&& m_second < otherTime.m_second))
				returnValue = true;
		}
		catch (bad_cast e)
		{
		}
		return returnValue;
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	ostream & operator<<(ostream & sout, const CTime & time)
	// Title:		Overloaded output operator
	// Description: Outputs the CTime object to the given stream
	//
	// Programmer:	Anthony Waddell
	// Date:		04-05-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		a CTime object
	// Output:		the CTime object to the sout stream
	// Calls:		print(ostream & sout) const
	// Called By:	N/A
	// Parameters:	ostream & sout; the stream used for output
	//				const CTime & time; the CTime to be output
	// Returns:		a reference to sout
	// History Log: 04-05-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	ostream & operator<<(ostream & sout, const CTime & time)
	{
		time.print(sout);
		return sout;
	}

	//------------------------------------------------------------------------
	// Class:		CTime
	// Function:	istream & operator >> (istream & sin, CTime & time)
	// Title:		Overloaded input operator
	// Description: Inputs from the given stream into a CTime object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	//
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		a user supplied time in the form "hh:mm:ss"
	// Output:		the CTime object with user-supplied values
	// Calls:		input(ostream & sin) const
	// Called By:	main
	// Parameters:	istream & sin; the stream used for input
	//				const CTime & time; the CTime to be used
	// Returns:		a reference to sin
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	istream & operator >> (istream & sin, CTime & time)
	{
		time.input(sin);
		return sin;
	}
}
