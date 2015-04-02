#include "std_lib_facilities_3.h"
#include "randint.h"

int better_random_digit() //To give a better random digit
{
	int  number = 1000; //Setting the number = 1000 so that it enters the while loop

               //Loop to get a better random digit
	 while(number >= 1000)
        	 number = randint() >> 21;

	//cout<<"\n"<< number << "\n";
	return number; //Returning the better random digit obtained
}

int main()
try{
	int remainder = 0;
	vector <int> v(10,0);
	
	for ( int i = 1; i <= 500; i++ )
	{		
		remainder = better_random_digit() % 10;
	
		switch( remainder )
		{

		case 0:
			v[0]++;
			break;

		case 1:
			v[1]++;
			break;

		case 2:
			v[2]++;
			break;

		case 3:
			v[3]++;
			break;

		case 4:
			v[4]++;
			break;

		case 5:
			v[5]++;
			break;

		case 6:
			v[6]++;
			break;

		case 7:
			v[7]++;
			break;

		case 8:
			v[8]++;
			break;

		case 9:
			v[9]++;
			break;

		default:
			cout<<"Error";
			break;

		}

	}

	cout << "DIGIT" << setw(10) << "COUNT \n" ;

	for ( int i = 0; i < 10; i++ )
		cout<<setw(3) << i << setw(8) << v[i] << "     " << string(v[i],'*') <<"\n";  //string(v[i],'*') prints as many '*' according to the value of v[i]
			 
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
