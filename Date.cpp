//----------------------------------------------------------------------------
//	File: Date.cpp
//
//	class: Date
//	methods:
//			Date::Date(short day, short month, short year); constructor
//			void Date::setCurrentDate(void)
//			void Date::setDayOfWeek(void); mutator for m_dayOfWeek
//			void Date::setDayOfYear(void); mutator for m_dayOfYear
//			void Date::setDayOfMonth(short dayOfMonth); 
//				mutator for m_dayOfMonth
//			void Date::setMonth(short month); mutator for m_month
//			void Date::setYear(short year); mutator for m_year
//
//			bool Date::operator==(const Comparable &other) const
//			bool Date::operator<(const Comparable &other) const
//
//			short Date::countLeaps(short year)const
//			Date Date::tomorrow() const
//			Date Date::yesterday() const
//			short Date::daysInMonth(short month, short year)
//			const string Date::monthName(int monthNum)
//			const string Date::weekdayName(int weekdayNum)
//
//			void Date::input(istream& sin)
//			void Date::print(ostream& sout)const
//	
//			ostream & operator<<(ostream & sout, const Date & date)
//			istream & operator >> (istream & sin, Date & date)
//
//----------------------------------------------------------------------------
#include "Date.h"

namespace AW_DATETIME
{
	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	Date::Date(short day, short month, short year); constructor
	// Title:		Constructor for Date object
	// Description: Constructs an object of the Date class
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		a user supplied date in the form "mm/dd/yyyy"
	// Output:		N/A
	// Calls:		setCurrentDate();
	//				setDayOfMonth(day);
	//				setDayOfYear();
	//				setDayOfWeek();
	// Called By:	main
	//				yesterday() const
	//				tomorrow() const
	// Parameters:	short day; day to set
	//				short month; month to set
	//				short year; month to set
	// Returns:		N/A
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	Date::Date(short day, short month, short year)
	{
		//sets date to today and then tris to start 
		setCurrentDate();
		setDayOfMonth(day);
		setMonth(month);
		setYear(year);
		setDayOfYear();
		setDayOfWeek();
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	bool Date::operator==(const Comparable &other) const
	// Title:		overloaded == operator for Date class
	// Description: Compares two Date class object to see if they are equal
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	main
	//				!= operator
	//				< operator
	// Parameters:	const Comparable &other; the other Date object to be
	//				compared against
	// Returns:		true if both object are exactly the same, false if not
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	bool Date::operator==(const Comparable &other) const
	{
		bool returnValue = false;
		try
		{
			const Date &otherDate = dynamic_cast<const Date&>(other);

			if (m_year == otherDate.m_year && m_month == otherDate.m_month
				&& m_dayOfMonth == otherDate.m_dayOfMonth)
				returnValue = true;
		}
		catch (bad_cast e)
		{
		}
		return returnValue;
	}
	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	bool Date::operator<(const Comparable &other) const
	// Title:		overloaded < operator for Date class
	// Description: Compares two Date class object to see if one is less than
	//				the other
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	main
	//				> operator
	//				>= operator
	// Parameters:	const Comparable &other; the other Date object to be
	//				compared against
	// Returns:		true if this object is less than the other, false if not
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	bool Date::operator<(const Comparable &other) const
	{
		bool returnValue = false;
		try
		{
			const Date &otherDate = dynamic_cast<const Date&>(other);
			if ((m_year < otherDate.m_year) ||
				(m_year == otherDate.m_year && m_month < otherDate.m_month)
				|| (m_year == otherDate.m_year && m_month == otherDate.m_month
					&& m_dayOfMonth < otherDate.m_dayOfMonth))
				returnValue = true;
		}
		catch (bad_cast e)
		{
		}
		return returnValue;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::setCurrentDate(void)
	// Title:		Sets the date to current date
	// Description: Sets a Date object with values supplied by system
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	Date(short day, short month, short year)
	//				input(istream& sin)
	// Parameters:	N/A
	// Returns:		void
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::setCurrentDate(void)
	{
		time_t rawtime;
		tm *currentTimePtr;
		time(&rawtime);
		currentTimePtr = localtime(&rawtime);

		m_year = currentTimePtr->tm_year + 1900;
		m_month = currentTimePtr->tm_mon;
		m_dayOfMonth = currentTimePtr->tm_mday;
		setDayOfYear();
		setDayOfWeek();
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::setDayOfWeek(void)
	// Title:		Sets the day of the week
	// Description: Sets the day of the week (0-6) for a Date object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		countLeaps(short year)const
	// Called By:	setCurrentDate(void)
	//				tomorrow() const
	//				yesterday() const
	//				setDayOfMonth(short dayOfMonth)
	//				Date(short day, short month, short year)
	// Parameters:	N/A
	// Returns:		void
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::setDayOfWeek(void)
	{
		m_dayOfWeek = 0;
		short count = (m_year - LOWYEAR);
		count += countLeaps(m_year);
		count += 1;
		count += m_dayOfYear;
		m_dayOfWeek = (count % DAYSINWEEK);
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::setDayOfYear(void)
	// Title:		Sets the day of the year
	// Description: Sets the day of the week (1-365/366) for a Date object
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		isLeapYear(short year)
	// Called By:	setCurrentDate(void)
	//				tomorrow() const
	//				yesterday() const
	//				setDayOfMonth(short dayOfMonth)
	//				Date(short day, short month, short year)
	// Parameters:	N/A
	// Returns:		void
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::setDayOfYear(void)
	{
		m_dayOfYear = 0;
		int calendar[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 0; i < m_month; i++)
		{
			m_dayOfYear += calendar[i];
		}
		m_dayOfYear += m_dayOfMonth;
		if ((isLeapYear(m_year)) && m_month > 1)
			m_dayOfYear += 1;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	short Date::countLeaps(short year)const
	// Title:		Counts leap years
	// Description: Determines the number of leap years from 1760 to the 
	//				given date
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		isLeapYear(short year)
	// Called By:	setDayOfweek(void)
	// Parameters:	short year; the year to count leap years to
	// Returns:		short; the number of leap years between years
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	short Date::countLeaps(short year)const
	{
		short leaps = 0;
		for (short i = LOWYEAR; i < year; i++)
			if (isLeapYear(i))
				leaps++;
		return leaps;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	Date Date::tomorrow() const
	// Title:		Finds tomorrow's date
	// Description: Creates day object representing tomorrow's date
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		setDayofYear(void)
	//				setDayOfWeek(void)
	// Called By:	N/A
	// Parameters:	N/A
	// Returns:		Date Date; the day representing tomorrow
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	Date Date::tomorrow() const
	{
		Date tomorrow = *this;
		short thisMonth = tomorrow.m_month;
		short firstOfTheMonth = 1;

		if (tomorrow.m_dayOfMonth == 31 &&
			(thisMonth == 0 || thisMonth == 2 || thisMonth == 4 ||
				thisMonth == 6 || thisMonth == 7 || thisMonth == 9 ||
				thisMonth == 11))
		{
			if (thisMonth == 11)
			{
				tomorrow.m_dayOfMonth = firstOfTheMonth;
				tomorrow.m_month = 0;
				tomorrow.m_year += 1;
			}
			else
			{
				tomorrow.m_dayOfMonth = firstOfTheMonth;
				tomorrow.m_month = (tomorrow.m_month + 1);
			}
		}
		else if (tomorrow.m_dayOfMonth == 30 && (thisMonth == 3 ||
			thisMonth == 5 || thisMonth == 8 || thisMonth == 10))
		{
			tomorrow.m_dayOfMonth = firstOfTheMonth;
			tomorrow.m_month += 1;
		}
		else if (thisMonth == 1)
		{
			if (isLeapYear(tomorrow.m_year))
			{
				if (tomorrow.m_dayOfMonth == 28)
				{
					tomorrow.m_dayOfMonth = 29;

				}
				else if (tomorrow.m_dayOfMonth == 29)
				{
					tomorrow.m_dayOfMonth = firstOfTheMonth;
					tomorrow.m_month += 1;
				}
			}
			else
			{
				if (tomorrow.m_dayOfMonth == 28)
				{
					tomorrow.m_dayOfMonth = firstOfTheMonth;
					tomorrow.m_month += 1;
				}
			}
		}
		else
		{
			tomorrow.m_dayOfMonth += 1;
		}
		tomorrow.setDayOfYear();
		tomorrow.setDayOfWeek();

		return tomorrow;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	Date Date::yesterday() const
	// Title:		Finds yesterday's date
	// Description: Creates day object representing yesterday's date
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		setDayofYear(void)
	//				setDayOfWeek(void)
	// Called By:	N/A
	// Parameters:	N/A
	// Returns:		Date; the day representing yesterday
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	Date Date::yesterday() const
	{
		Date yesterday = *this;
		short thisMonth = yesterday.m_month;

		if (yesterday.m_dayOfMonth == 1)
		{
			if (thisMonth == 0)
			{
				yesterday.m_dayOfMonth = 31;
				yesterday.m_month = 11;
				yesterday.m_year -= 1;
			}
			else if (thisMonth == 1 || thisMonth == 3 || thisMonth == 5 ||
				thisMonth == 8 || thisMonth == 10)
			{
				yesterday.m_month -= 1;
				yesterday.m_dayOfMonth = 31;
			}
			else if (thisMonth == 11 || thisMonth == 9 || thisMonth == 6)
			{
				yesterday.m_month -= 1;
				yesterday.m_dayOfMonth = 30;
			}
			else if (thisMonth == 7)
			{
				yesterday.m_month -= 1;
				yesterday.m_dayOfMonth = 31;
			}
			else if (thisMonth == 2)
			{
				if (isLeapYear(yesterday.m_year))
					yesterday.m_dayOfMonth = 29;
				else
					yesterday.m_dayOfMonth = 28;
				yesterday.m_month -= 1;
			}
		}
		else
		{
			yesterday.m_dayOfMonth -= 1;
		}
		yesterday.setDayOfYear();
		yesterday.setDayOfWeek();
		return yesterday;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	short Date::daysInMonth(short month, short year)
	// Title:		Calculates the days in a month
	// Description: Determines the number of days in any month given
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		isLeapYear(short year)
	// Called By:	setDayOfmonth(short dayOfMonth)
	// Parameters:	short month; the month
	//				short year; the year
	// Returns:		short; the number of days in any month
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	short Date::daysInMonth(short month, short year)
	{
		short numberOfDays;
		if (month == 3 || month == 5 || month == 8 || month == 10)
			numberOfDays = 30;
		else if (month == 1)
		{
			if (isLeapYear(year))
				numberOfDays = 29;
			else
				numberOfDays = 28;
		}
		else
			numberOfDays = 31;
		return numberOfDays;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	const string Date::monthName(int monthNum)
	// Title:		Gets the name of the month
	// Description: String representation of the month (0 - 11)
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	print(ostream& sout)const
	// Parameters:	int monthNum; the month
	// Returns:		string; the string representation of a month
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	const string Date::monthName(int monthNum)
	{
		string nameOfMonth;
		switch (monthNum)
		{
		case 0: nameOfMonth = "Janurary";
			break;
		case 1: nameOfMonth = "February";
			break;
		case 2: nameOfMonth = "March";
			break;
		case 3: nameOfMonth = "April";
			break;
		case 4: nameOfMonth = "May";
			break;
		case 5: nameOfMonth = "June";
			break;
		case 6: nameOfMonth = "July";
			break;
		case 7: nameOfMonth = "August";
			break;
		case 8: nameOfMonth = "September";
			break;
		case 9: nameOfMonth = "October";
			break;
		case 10: nameOfMonth = "November";
			break;
		case 11: nameOfMonth = "December";
			break;
		default: nameOfMonth = "Invalid";
		}
		return nameOfMonth;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	const string Date::weekdayName(int weekdayNum)
	// Title:		Gets the name of the weekday
	// Description: String representation of the weekday (0 - 6)
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	print(ostream& sout)const
	// Parameters:	int weekdayNum; the weekday
	// Returns:		string; the string representation of the day of the week
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	const string Date::weekdayName(int weekdayNum)
	{
		string whatDay;
		switch (weekdayNum)
		{
		case 0: whatDay = "Sunday";
			break;
		case 1: whatDay = "Monday";
			break;
		case 2: whatDay = "Tuesday";
			break;
		case 3: whatDay = "Wednesday";
			break;
		case 4: whatDay = "Thursday";
			break;
		case 5: whatDay = "Friday";
			break;
		case 6: whatDay = "Saturday";
			break;
		default: whatDay = "Invalid";
		}
		return whatDay;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::setDayOfMonth(short dayOfMonth)
	// Title:		Set the day of the month
	// Description: Set the day of the month for a Date object; mutator
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		short daysInMonth(short month, short year)
	//				void setDayOfYear()
	//				void setDayOfWeek()
	// Called By:	Date(short day, short month, short year); constructor
	//				input(istream& sin)
	// Parameters:	short dayOfMonth; the day of the month
	// Returns:		void
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::setDayOfMonth(short dayOfMonth)
	{
		if (dayOfMonth > 0
			&& dayOfMonth <= daysInMonth(m_month, m_year))
		{
			m_dayOfMonth = dayOfMonth;
			setDayOfYear();
			setDayOfWeek();
		}
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::setMonth(short month)
	// Title:		Sets the month
	// Description: Set the month for a Date object; mutator
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	Date(short day, short month, short year); constructor
	//				input(istream& sin)
	// Parameters:	short month; the month
	// Returns:		void
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::setMonth(short month)
	{
		if (month >= 0 && month <= MONTHSINYEAR)
			m_month = month;

	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::setYear(short year)
	// Title:		Sets the yearsetyear
	// Description: Set the Year for a Date object; mutator
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		N/A
	// Called By:	Date(short day, short month, short year); constructor
	//				input(istream& sin)
	// Parameters:	short year; the year
	// Returns:		void
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::setYear(short year)
	{
		if (year >= LOWYEAR)
			m_year = year;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::input(istream& sin)
	// Title:		Input function for creating Date object
	// Description: Allows the user to enter any combination of m_dayOfMonth,
	//				m_month, and/or m_year and puts them into *this
	//
	// Programmer:	Anthony Waddell
	// Date:		04-11-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		properties of a Date object from console, provided by user
	// Output:		N/A
	// Calls:		setMonth(short month)
	//				setDayOfMonth(short dayOfMonth)
	//				setYear(short year)
	//				setCurrentDate()
	// Called By:	istream & operator >> (istream & sin, Date & date)
	// Parameters:	istream& sin; the input stream
	// Returns:		void
	// History Log: 04-11-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::input(istream& sin)
	{
		string input;
		string sUserDay;
		string sUserMonth;
		string sUserYear;
		short userDay;
		short userMonth;
		short userYear;
		int count = 0;
		int userOffset = 1;
		char inputChar = ' ';

		getline(sin, input);
		stringstream ss(input);
		(*this).setCurrentDate();
		for (unsigned int i = 0; i < input.size(); i++)
		{
			inputChar = input[i];
			if (inputChar == '/')
				count++;
		}
		switch (count)
		{
		case 0:
			getline(ss, sUserDay);
			userDay = atoi(sUserDay.c_str());
			(*this).setDayOfMonth(userDay);
			break;
		case 1:
			getline(ss, sUserDay, '/');
			userDay = atoi(sUserDay.c_str());
			(*this).setDayOfMonth(userDay);

			getline(ss, sUserMonth);
			userMonth = atoi(sUserMonth.c_str());
			(*this).setMonth(userMonth - userOffset);
			break;
		case 2:
			getline(ss, sUserDay, '/');
			userDay = atoi(sUserDay.c_str());
			(*this).setDayOfMonth(userDay);

			getline(ss, sUserMonth, '/');
			userMonth = atoi(sUserMonth.c_str());
			(*this).setMonth(userMonth - userOffset);

			getline(ss, sUserYear);
			userYear = atoi(sUserYear.c_str());
			(*this).setYear(userYear);
			break;

		default:
			cout << "Invalid date inputted, using today's date";
		}
		(*this).setDayOfWeek();
		(*this).setDayOfYear();
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	void Date::print(ostream& sout)const
	// Title:		Print function for Date class
	// Description: Prints out a Date object in a standard format
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		N/A
	// Calls:		string weekdayName(short dayOfWeek)
	//				string monthName(short month)
	//				short getDayofMonth()
	//				short getYear()
	// Called By:	ostream & operator << (ostream & sout, Date & date)
	// Parameters:	ostream& sout; the designated output stream
	// Returns:		void
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	void Date::print(ostream& sout)const
	{
		sout << weekdayName(m_dayOfWeek) << ", " << monthName(m_month) << 
			" " << getDayOfMonth() << ", " << (*this).getYear();
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	ostream & operator<<(ostream & sout, const Date & date)
	// Title:		Overloaded output operator
	// Description: Overloaded output operator for the Date class
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		N/A
	// Output:		a Date object to console
	// Calls:		print(ostream& sout)const
	// Called By:	main()
	// Parameters:	ostream& sout; the designated output stream
	//				const Date & date; the Date object to output to stream
	// Returns:		a reference to sout
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	ostream & operator<<(ostream & sout, const Date & date)
	{
		date.print(sout);
		return sout;
	}

	//------------------------------------------------------------------------
	// Class:		Date
	// Function:	istream & operator >> (istream & sin, Date & date)
	// Title:		Overloaded input operator
	// Description: Overloaded input operator for the Date class
	//
	// Programmer:	Anthony Waddell
	// Date:		04-07-17
	// Version:		1.0
	// Environment: Hardware: PC, i7
	//				Software: OS: Windows 10 
	//				Compiles under Microsoft Visual C++ 2015
	//
	// Input:		A Date object from console
	// Output:		N/A
	// Calls:		input(istream& sin)const
	// Called By:	main()
	// Parameters:	istream& sout; the designated input stream
	//				const Date & date; the Date object input from the stream
	// Returns:		a reference to sin
	// History Log: 04-07-17 AW Completed v 1.0
	//------------------------------------------------------------------------
	istream & operator >> (istream & sin, Date & date)
	{
		date.input(sin);
		return sin;
	}
}