//-----------------------------------------------------------------------------
// File: Comparable.h
//
// Class: Comparable
//----------------------------------------------------------------------------
#pragma once
#pragma warning(disable : 4996)
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------
// File:		Comparable.h
// Class:		Comparable
// Description: Pure virtual function outlines for the Comparable abstract
//				base class
// 
// Programmer:	Anthony Waddell
// Version:     1.0
// Environment: Hardware: PC, i7
//              Software: OS: Windows 10 
//              Compiles under Microsoft Visual C++ 2015
//
// Properties:	None
//
// Functions:   
//				Pure Virtuals:
//
//				virtual bool operator==(const Comparable &other)const;
//					Returns true if two objects are exactly the same; 
//					false, if not
//				virtual bool operator!=(const Comparable &other)const;
//					returns true if two objects are not exactky the same;
//					false if not
//				virtual bool operator<(const Comparable &other)const;
//					Returns true if *this is less than the object it's being
//					compared to; false if not
//				virtual bool operator>(const Comparable &other)const;
//					Returns true if *this is greater than the object it's 
//					being compared to; false if not
//				virtual bool operator<=(const Comparable &other)const;
//					Returns true if *this is less than or equal to the object
//					it's being compared to; false if not
//				virtual bool operator>=(const Comparable &other)const;
//					Returns true if *this is greater than or equal to the
//					object it's being compared to; false if not
//				virtual void input(istream& sin);
//					Allows user to enter properties into derived Comparable
//					objects
//				virtual void print(ostream& sout)const;
//					Allows derived Comparable objects to be printed to
//					designated output stream
//				virtual ~Comparable();
//					Destructor
// 
// History Log:	04-07-17 AW Included in Project
//
// Known Bugs:	N/A
//---------------------------------------------------------------------------

namespace AW_DATETIME
{
	class Comparable
	{
	public:
		virtual bool operator==(const Comparable &other)const = 0;
		virtual bool operator!=(const Comparable &other)const = 0;
		virtual bool operator<(const Comparable &other)const = 0;
		virtual bool operator>(const Comparable &other)const = 0;
		virtual bool operator<=(const Comparable &other)const = 0;
		virtual bool operator>=(const Comparable &other)const = 0;
		virtual void input(istream& sin) = 0;
		virtual void print(ostream& sout)const = 0;
		virtual ~Comparable() {}
	};
}