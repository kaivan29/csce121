/*HW2PR1
Section - 306
Name - Kaivan Shah*/

#include "std_lib_facilities_3.h"

double my_sqrt_1( double n ) // To calculate square root of n by the given formula
{
        double x = 1.00 ;

	for(int i = 1 ; i <= 10; i++)
		x = ( x + n/x ) / 2;

	return x; // returns the value where the function is called
}

int main()
{

	for( auto k : { -100, -10, -1, 0, 1, 10 ,100 } ) //Range-Based loop: Executes for loop over a range mention in range_expression
	{
		double n = 3.14159 * pow( 10 , k ); //pow(a,b) is a math library function that gives a^b as output
		cout << "\n\n The value of n: " << n; //sqrt(n) is a math library function that calculates the square root of the given number i.e.  n here
		
		cout << "\n Square root via inbuilt math_function: " << sqrt(n);
		
		double y = my_sqrt_1( n ); // my_sqrt_1() function is called and n as a parameter is sent. The function returns a value which is stored in variable y
		cout << "\n Square root via Newton-Raphson algorithm: " << y;

	}
	
	cout << "\n\n\n" ;
	return 0;

}


