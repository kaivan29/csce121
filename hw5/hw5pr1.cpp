#include "std_lib_facilities_3.h"
#include "Chrono.h"

using namespace Chrono;    //using the entities of the namespace Chrono

int main()
try {
	    int add;
		Date my_date;   //To input the Date from the user
		
		string counter;
		cout << "\n To find the next day of the Date \n";

		do							//do while loop to keep user asking for the date
		{
			cout<< "Enter the date in the format (yyyy, mm , dd) \n";
			cin >> my_date;
			
			cout << "\n Enter the number of days you want to add to the date mentioned by you \n";
			cin >> add;
			if (cin.good() == false)
				throw exception();
			

			if ( is_date(my_date.year(), my_date.month() , my_date.day()) == false)   //Checks if the date entered by user is incorrect i.e if the days length exceeds the limit
				cout << "The Date entered by you is incorrect \n";

			else												   //If it is correct
			{
				//We find the next day by using operator ++ defined in Chrono.cpp
				Date today = Date(my_date.year(), my_date.month() , my_date.day());

				for( int i = 1 ; i <= add ; i++ )    //Adds the number of the days to be added to the date
					++today;
				
				cout << "The date is : " << today << " \n ";
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
