#include "std_lib_facilities_3.h"
#include "Chrono.h"
//Chrono.cpp

namespace Chrono{		

	//member function definitions:

	Date::Date(int yy, Month mm, int dd)
		: y(yy), m(mm), d(dd)
	{
		if (!is_date(yy, mm, dd)) throw invalid();
	}

	Date& default_date()
	{
		static Date dd(2001, Date::jan, 1); //start of 21st century
		return dd;
	}

	Date::Date()
		: y(default_date().year()),
		m(default_date().month()),
		d(default_date().day())
	{
	}

	void Date::add_day(int n)		// to add day
	{
		d = d + n;			// adds day	by n, here n is 1 as we need to find tomorrow	
	}

	void Date::add_month(int n)	
	{
		int days_in_month = 31;
		switch (m)			//To check what month is entered by user and what is the length of the month
		{
			case Date::feb:
				days_in_month = (leapyear(y)) ? 29 : 28;     //if the month is feb than the length is 28 and 29 when it is a leap year
				break;
			case Date::apr:
			case Date::jun:
			case Date::sep:
			case Date::nov:
				days_in_month = 30;	
			break;
		}
		if (d > days_in_month)		// checks if day goes to next month that is when it exceeds the months length
		{
			d = 1;				   // sets day to 1
			if (m == dec)		   //  if m is December
			{
				m = jan;		  //set m to January
				add_year(1);      //need to change to next year too 
			}
			else 
				m = Month(m + n); //if it not december but the length exceeds than we change the month
		}
	}

	void Date::add_year(int n)
	{
		if (m == feb && d == 29 && !leapyear(y + n)){
			//beware of leap years!
			m = mar;	//use March 1 instead of February 29
			d = 1;
		}
		y += n;
	}
	//helper functions

	bool is_date(int y, Date::Month m, int d)
	{
		//assume that y is valid

		if (d <= 0) return false;  //d must be positive
		int days_in_month = 31;   //most months have 31 days

		switch (m){
		case Date::feb:             //Length of february varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Date::apr:
		case Date::jun:
		case Date::sep:
		case Date::nov:
			days_in_month = 30;      //The rest have 30 days
			break;
		}

		if (days_in_month < d) return false;

		return true;
	}

	bool leapyear(int y)
	{
		if ((y % 400 == 0 || y % 100 != 0) && (y % 4 == 0)) //to check if it is a leap year
			return true;
		else
			return false;
	}
	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}

	ostream& operator<<(ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day() << ')';
	}

	istream& operator>>(istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')'){    //oops: format error
			is.clear(ios_base::failbit);							  //set the failbit
			return is;
		}
		return is;
	}

	Date& Date::operator++()		// ++ operator to increement the date entered
	{
		this->add_day(1);     //'this' is a special type of pointer

		if ( is_date(y , Date::Month(m), d) == false ) //if is_date is false
		this->add_month(1);

		return *this;    //returning the object
	}

	enum Day
	{
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	Day day_of_week(const Date& d)
	{
		return sunday;
	}

	Date next_Sunday(const Date& d)
	{
		return d;
	}

	Date next_weekday(const Date& d)
	{
		return d;
	}

}//chrono
