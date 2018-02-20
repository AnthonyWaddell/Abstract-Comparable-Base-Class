//----------------------------------------------------------------------------
//	File: Date.h
//
//	class: Date
//----------------------------------------------------------------------------
#ifndef DATE_H
#define DATE_H
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Comparable.h"
using namespace std;

//----------------------------------------------------------------------------
// Class:		Date
// File:        Date.cpp
// Title:       Date Class
//
// Description:	This file contains definitions for the Date class
//
// Programmer:		Anthony Waddell
// Version:          1.0
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015
//
// Properties:
//				short m_year;		// full year, i.e., 2006
//				short m_month;		// 0 - 11
//				short m_dayOfMonth; // 1 - days in that month
//				short m_dayOfYear;  // 1 - 365 or 366
//				short m_dayOfWeek;	// 0 - 6
//
// Functions:
//		Inline:
//		Static:
//			static bool isLeapYear(short year);
//				true if year is a leap year; false otherwise
//		Non-Static:
//			short getDayOfWeek() const;
//				accessor for m_dayOfWeek
//			short getDayOfMonth() const;
//				accessor for m_dayOfMonth
//			short getMonth() const;
//				accessor for m_month
//			short getYear() const;
//				accessor for m_year
//			short getDayOfYear() const;
//				accessor for m_dayOfYear
//			virtual bool operator!=(const Comparable &other)const;
//				Returns true if *this object is not exactly the same as the 
//				object it is being compared to; false if not
//			virtual bool operator>(const Comparable &other)const;
//				Returns true if *this object is greater than the object it is
//				being compared to; false if not
//			virtual bool operator<=(const Comparable &other)const;
//				Returns true if *this object is less than or equal to the
//				object it is being compared to; false if not
//			virtual bool operator>=(const Comparable &other)const;
//				Returns true if *this object is greater than or equal to
//				the object it is being compared to; false if not
//			
//		Non-inline:
//		Static:
//			static short daysInMonth(short month, short year);
//				returns the number of days in month for that year
//			static const char* monthName(int monthNum);
//				returns a string representation of monthNum
//			static const char* weekdayName(int weekdayNum);
//				returns a string representation of weekdayNum
//		Non-static
//			Date(short day, short month, short year);
//				Constructor with parameters
//			virtual ~Date(void) {}; 
//				class destructor
//			virtual bool operator==(const Comparable &other)const;
//				Returns true if *this object is exactly the same as the object
//				it is being compared to; false if not
//			virtual bool operator<(const Comparable &other)const;
//				Returns true if *this object is less than the object it is
//				being compared against, false if not
//			virtual void input(istream& sin);
//				Allows user to input properties into a Date object
//			virtual void print(ostream& sout)const;
//				Prints out the date object in a standarized format
//			void setDayOfYear(void);
//				Mutator for m_dayOfYear
//			void setDayOfWeek(void);
//				Mutator for m_dayOfWeek
//			void setCurrentDate(void);
//				Fills a date object's properties with the current date from
//				the system 
//			void setDayOfMonth(short dayOfMonth);
//				Mutator for m_dayOfMonth
//			void setMonth(short monthIn);
//				Mutator for m_Month
//			void setYear(short yearIn);
//				Mutator for m_Year
//			short countLeaps(short year)const;
//				Returns the number of leap years from 1760 to the given year
//			Date tomorrow()const;
//				Returns a Date object representing the day after *this
//			Date yesterday()const;
//				Returns a Date object representign the day before *this
//			ostream& operator << (ostream& sout, const Date& date);
//				Overloaded output operator for the Date class
//			istream& operator >> (istream& sin, Date& date);
//				Overloaded input operator for the Date class
//
// History Log: 04/07/17 AW  completed version 1.0
//
// Known Bugs: N/A
//----------------------------------------------------------------------------
namespace AW_DATETIME
{
	const short LOWYEAR = 1760;
	const short DAYSINYEAR = 365;
	const short STARTDAYOFWEEK = 2;
	const short MONTHSINYEAR = 11;
	const short DAYSINWEEK = 7;

	class Date : virtual public Comparable
	{
	public:
		Date(short day = -1, short month = -1, short year = -1);
		virtual ~Date(void) {}
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
		virtual void input(istream& sin);
		virtual void print(ostream& sout)const;

		// mutators
	private:
		void setDayOfYear(void);
		void setDayOfWeek(void);

	public:
		void setCurrentDate(void);
		void setDayOfMonth(short dayOfMonth);
		void setMonth(short monthIn);
		void setYear(short yearIn);
		short countLeaps(short year)const;

		//accessors
		short getDayOfWeek()const { return m_dayOfWeek; }
		short getDayOfMonth()const { return m_dayOfMonth; }
		short getMonth()const { return m_month; }
		short getYear()const { return m_year; }
		short getDayOfYear()const { return m_dayOfYear; }

		Date tomorrow()const;
		Date yesterday()const;

		//statics
		static bool isLeapYear(short year)
		{
			return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
		}
		static short daysInMonth(short month, short year);
		static const string monthName(int monthNum);
		static const string weekdayName(int weekdayNum);

	protected:
		short m_year;  // full year, i.e., 2012
		short m_month; // 0 - 11
		short m_dayOfMonth; // 1 - days in that month
		short m_dayOfYear;  // 1 - 365 or 366
		short m_dayOfWeek;	// 0 - 6
	};

	ostream& operator << (ostream& sout, const Date& date);
	istream& operator >> (istream& sin, Date& date);
}
#endif
