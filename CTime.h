//----------------------------------------------------------------------------
//	File: CTime.h
//
//	class: CTime
//----------------------------------------------------------------------------
#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>
#include <exception>
#include "Comparable.h"
using namespace std;

namespace AW_DATETIME
{
	const short MAXHOUR = 24;
	const short MAXMINSEC = 59;
	//------------------------------------------------------------------------
	// Class:		CTime
	// File:        CTime.h
	// Title:       CTime Class
	// Description:	This file contains the class definition for CTime
	//
	// Programmer:	Anthony Waddell
	// Version:     1.0
	// Environment: Hardware: PC, i7
	//              Software: OS: Windows 10 
	//              Compiles under Microsoft Visual C++ 2015
	// 
	//
	// Properties:
	//				int m_hour		-- 0 - 23
	//				int m_minute	-- 0 - 59
	//				int m_second	-- 0 - 59 
	//
	// Functions:
	//			Inline:
	//				CTime(void) { CTime::setCurrentTime();
	//					default constructor
	//				short getHour()const; 
	//					accessor for m_hour
	//				short getMinute()const; 
	//					accessor for m_minute  
	//				short getSecond()const; 
	//					accessor for m_second
	//				virtual bool operator!=(const Comparable &other)const;
	//					Returns true if *this is not exactly the same as
	//					the object it's being compared to; false if not
	//				virtual bool operator>(const Comparable &other)const;
	//					Returns true if *this is greater than the object it's
	//					being compared to; false if not
	//				virtual bool operator<=(const Comparable &other)const;
	//					Returns true if *this is less than or euqla to the
	//					the object it's being compared to, false if not
	//				virtual bool operator>=(const Comparable &other)const;
	//					Returns true if *this is greater than or equal to the
	//					object it's being compared to, false if not
	//
	//			Non-inline:
	//				void CTime::setHour(short hour); 
	//					mutator for m_hour
	//				void CTime::setMinute(short minute); 
	//					mutator for m_minute
	//				void CTime::setSecond(short second); 
	//					mutator for m_second
	//				void CTime::setCurrentTime();
	//					Fills a CTime object with current time from the 
	//					system clock
	//				CTime::CTime(int hour, int minute, int second); 
	//					constructor with parameters
	//				void CTime::input(istream & sin);
	//					Allows a user to input properties into a CTime object
	//				void CTime::print(ostream & sout) const;
	//					Prints out a CTime object in (hh:mm:ss) format 
	//				virtual bool CTime::operator==
	//				(const Comparable & other) const;
	//					Returns true if *this object is exactly the same as 
	//					the object it's being compared against, false if not
	//				virtual bool CTime::operator<
	//				(const Comparable & other) const;
	//					Returns true if *this object is less than the object
	//					 it is being compared to; false if not
	//				ostream & operator<<(ostream & sout, const CTime & time);
	//					overloaded output operator
	//				istream & operator >> (istream & sin, CTime & time)
	//					overloaded input operator
	//
	// History Log:	04-11-17 AW Completer v 1.0 
	// Known Bugs: N/A
	// -----------------------------------------------------------------------
	class CTime : virtual public Comparable
	{
	public:
		CTime(void) { CTime::setCurrentTime(); }
		CTime(int hour, int minute = 0, int second = 0);

		// pure virtuals that MUST be defined		
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

		// Accessors
		short getHour()const { return m_hour; }
		short getMinute()const { return m_minute; }
		short getSecond()const { return m_second; }

		// Mutators
		void setHour(short hour);
		void setMinute(short minute);
		void setSecond(short second);

		void setCurrentTime(void);
		virtual ~CTime() {}

	protected:
		int m_hour;
		int m_minute;
		int m_second;
	};

	ostream& operator << (ostream& sout, const CTime& time);
	istream& operator >> (istream& sin, CTime& time);
}