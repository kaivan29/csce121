/*HW2PR2
Section - 306
Name - Kaivan Shah*/

#include "std_lib_facilities_3.h"

double my_sqrt_1( double n ) // To calculate square root of n by the given formula
{
	double x = 1.00 ;

	for( int i = 1 ; i <= 10; i++ )
		x = ( x + n/x ) / 2 ;

	return x ; // returns the value where the function is called
}
int main()
{
        cout << " n " << setw( 32 ) ; //setw() is library function and here it sets the width parameter of the stream out to exactly 30 as mentioned
 
        cout << " sqrt(n) " << setw( 32 ) ;
 
        cout << " my_sqrt_1(n) " << setw( 32 ) ;
 
        cout << " relative_error_percent " << setw( 32 ) << " \n\n " ;

	for ( auto k : { -100, -10, -1, 0, 1, 10 ,100 } ) //Range-Based loop: Executes for loop over a range mention in range_expression
	{
		double n = 3.14159 * pow( 10 , k ) ;
        	cout << n << setw( 25 ) ;

		cout << sqrt ( n ) << setw( 25 ) ; //sqrt(n) is a math library function that calculates the square root of the given number i.e.  n here

		double y = my_sqrt_1 ( n ) ;
		cout << y << setw( 25 ) ;

                double relative_error_per_cent = 100 * ( y * sqrt( n ) ) / sqrt( n ) ; //Calculates the relative error percent between the square root calculated by math library function sqrt(n) and function my_sqrt_1(n)
                cout << relative_error_per_cent << setw( 25 ) ;

                cout << " \n " ;
        }

	cout << " \n\n\n " ;
	return 0;

}
