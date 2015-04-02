#include "std_lib_facilities_3.h"
namespace Chrono{

	class Date{
	public:
		enum Month{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};

		class invalid{}; // to throw exception

		Date(int y, Month m, int d); //Check for valid date and intialize
		Date();						 //default constructor
		//the default copy operations are fine

		//not to be modified operations
		int day() const{ return d; }
		Month month() const{ return m; }
		int year() const { return y; }

		//modifying operations

		void add_day(int n);
		void add_month(int n);
		void add_year(int n);

		Date& operator++();

	private:
		int y;
		Month m;
		int d;
	};

	bool is_date(int y, Date::Month m, int d);

	bool leapyear(int y);

	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);


	ostream& operator<<(ostream& os, const Date& d);

	istream& operator>>(istream& is, const Date& dd);
} //Chrono

