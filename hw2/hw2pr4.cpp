/*HW2PR4
Section - 306
Name - Kaivan Shah*/

#include "std_lib_facilities_3.h"
double my_sqrt_1 ( double n ) 
{
        double x = 1.00 ;

        for( int i = 1 ; i <= 10; i++ )
                x = ( x + n/x ) / 2 ;

        return x ; // returns the value where the function is called
}

double my_sqrt_2( double n ) // To calculate square root of n by the given formula 
{
	double result = 1.00;

	while( n > 8/5 )
        {
	 result *= 2 ;
	 n = n / 4 ;
	}

	while( n < 2/5 )
        {
         result /= 2;
         n = n * 4;
        }

	return result * my_sqrt_1( n ); //calls the function my_sqrt_1(n) which returns a value, which is multiplied with the result and returned where the function is called
}
int main()
{
        cout << " n " << setw( 32 ) ;

        cout << " sqrt( n ) " << setw( 32 ) ;

        cout << " my_sqrt_2( n ) " << setw( 32 ) ;

        cout << " relative_error_percent " << setw( 32 )<< " \n\n " ;

        for( auto k : { -100, -10, -1, 0, 1, 10 ,100 } ) //Range-Based loop: Executes for loop over a range mention in range_expression
        {
                double n = 3.14159 * pow( 10 , k ) ; //pow(a,b) is a math library function that gives a^b as output
                cout << n << setw( 25 ) ;
                
		cout << sqrt( n ) << setw( 25 ) ; //sqrt(n) is a math library function that calculates the square root of the given number i.e.  n here
                
		double y = my_sqrt_2( n ) ; // my_sqrt_2() function is called and n as a parameter is sent. The function returns a value which is stored in variable y
                cout << y << setw( 25 ) ;
                
		double relative_error_per_cent = 100 * ( y * sqrt( n ) ) / sqrt( n );
                cout << relative_error_per_cent << setw( 25 ) ; //Calculates the relative error percent between the square root calculated by math library function sqrt(n) and function my_sqrt_2(n)

                cout << " \n " ;
        }

        cout << " \n\n\n " ;
        return 0;
}

