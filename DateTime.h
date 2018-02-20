//----------------------------------------------------------------------------
//	File: DateTime.h
//
//	class: DateTime
//----------------------------------------------------------------------------
#ifndef DATETIME_H
#define DATETIME_H
#include "Date.h"
#include "CTime.h"

//----------------------------------------------------------------------------
// File:        DateTime.h
// Class:		DateTime
// Title:       Date Class
//
// Description:	This file contains definitions for the DateTime class
//
// Programmer:	Anthony Waddell
// Version:     1.0
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015
//
// Properties: N/A
//
// Functions:
//		Inline:
//			DateTime(void) { CTime::setCurrentTime(), Date::setCurrentDate(); }
//				Default constructor
//			DateTime(short dayOfMonth, short month = 0, short year = 0,
//				int hour = 0, int minute = 0, int second = 0) :
//				Date(dayOfMonth, month, year), CTime(hour, minute, second) {};
//					Constructor with parameters
//			DateTime(const Date &date, const CTime &time) :
//				Date(date), CTime(time) {};
//					Constructor with reference parameters
//			virtual bool operator!=(const Comparable &other)const;
//				Returns true if *this object is not exactly the same as the 
//				object it is being compared to
//			virtual bool operator>(const Comparable &other)const;
//				Returns true if *this object is greater than the object it 
//				is being compared to; false if not
//			virtual bool operator<=(const Comparable &other)const;
//				Returns true if *this object is less than or equal to the 
//				object it is being compared to; false if not
//			virtual bool operator>=(const Comparable &other)const;
//				Returns true if *this object is greater than or equal to the
//				object it is being compared to; false if not
//			
//		Non-inline:
//			virtual void input(istream& sin);
//				Allows a user to input properties into a DateTime object
//			virtual void print(ostream& sout)const;
//				Prints out a DateTime in a standard format
//			virtual bool operator==(const Comparable &other)const;
//				Returns true if *this object is exactly the same as the object
//				it is being compared to; false if not
//			virtual bool operator<(const Comparable &other)const;
//				Returns true if *this object is less than the object it is
//				being compared to; false if not
//			ostream& operator << (ostream& sout, const DateTime& dateTime);
//				Overloaded output operator for the DateTime class
//			istream& operator >> (istream& sin, DateTime& dateTime);
//				Overloaded input operator for the DateTime class
//
// History Log: 04/07/17 AW  completed version 1.0
//
// Known Bugs: N/A
//----------------------------------------------------------------------------
namespace AW_DATETIME
{
	class DateTime : public CTime, public Date
	{

	public:
		DateTime(void) { CTime::setCurrentTime(), Date::setCurrentDate(); }
		DateTime(short dayOfMonth, short month = 0, short year = 0,
			int hour = 0, int minute = 0, int second = 0) :
			Date(dayOfMonth, month, year), CTime(hour, minute, second) {};
		DateTime(const Date &date, const CTime &time) :
			Date(date), CTime(time) {};
	
		virtual void input(istream& sin);
		virtual void print(ostream& sout)const;
		virtual bool operator==(const Comparable &other)const;
		virtual bool operator!=(const Comparable &other)const
		{
			return !((*this) == other);
		}
		virtual bool operator<(const Comparable &other)const;
		virtual bool operator>(const Comparable &other)const
		{
			return !((*this) < other) && !((*this) == other);
		}
		virtual bool operator<=(const Comparable &other)const
		{
			return !((*this) > other);
		}
		virtual bool operator>=(const Comparable &other)const
		{
			return !((*this) < other);
		}
	};

	ostream& operator<<(ostream& sout, const DateTime& dateTime);
	istream& operator >> (istream& sin, DateTime& dateTime);

}
#endif