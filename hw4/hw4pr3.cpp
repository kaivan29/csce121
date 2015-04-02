#include "std_lib_facilities_3.h"
#include "Chrono.h"

using namespace Chrono;    //using the entities of the namespace Chrono

int main()
try {

		int year, month, day;
		string counter;
		cout << "\n To find the next day of the Date \n";

		do							//do while loop to keep user asking for the date
		{
			cout << "\n Enter the year \n";
			cin >> year;
			if (cin.good() == false) //To check if the year entered by user is a integer
				throw exception();

			cout << " Enter the month \n";
			cin >> month;
			if (cin.good() == false)
				throw exception();
	
			cout << " Enter the day \n";
			cin >> day;
			if (cin.good() == false)
				throw exception();

			

			if ( is_date(year, Date::Month(month), day) == false)   //Checks if the date entered by user is incorrect i.e if the days length exceeds the limit
				cout << "The Date entered by you is incorrect \n";

			else												   //If it is correct
			{
				//We find the next day by using operator ++ defined in Chrono.cpp

				Date today = Date(year, Date::Month(month), day); 
				++today;
				
				cout << " Tomorrow it is : " << today << " \n ";
			}

			cout << "\n To Continue enter any charachter or enter ';' \n";	//If the user wants to enter another date
		
			cin >> counter;

		} while (counter != ";");

		return 0;
	}

catch (exception& e)
{
	cerr << "\n error :" << e.what() << " \n";
	keep_window_open();
	return 1;
}
	
catch (...)
{
	cerr << " Unknown Exception \n ";
	keep_window_open();
	return 2;
}
