#include "std_lib_facilities_3.h"
#include "randint.h"

int main()
try{
	int number = 0, remainder = 0;
	vector <int> v(10,0); //vector to store the number of 0's ,1's .... 8's ,9's
	
	for ( int i = 1; i <= 1000; i++ ) //To count the number of 0's ,1's .... 8's ,9's
	{		

		number = randint(); //Calling the function randint() to send the random integers
		
		//cout<<"\n"<< number << "\n";
		
		remainder = number % 10; //To get the last digit of the random integer
		
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
			cout<<" Error ";
			break;	

		}

	}

	for ( int i = 0; i < 10; i++ ) //To print number of the 0's ,1's .... 8's ,9's
		cout << "\n There were " << v[i] << " " << i << "'s \n";
			 
	return 0;
}

catch(runtime_error& e)
{
	cerr << " runtime error: " << e.what() << "\n";  //e.what extracts the message from runtime error
	keep_window_open();
	return 1;
}
catch(...)
{
	cerr << " Oops: Unknown Exception \n";
	keep_window_open();
	return 1;
}
