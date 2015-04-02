/*HW1PR2
Section - 306
Name - Kaivan Shah*/
#include"std_lib_facilities_3.h"

int main()//C++ programs start by executing the function main
{
	int number = 0;//number is a variable of int datatype

	cout<<"\n\n To check whether the number entered by you is multiple of 5 or not \n";
	cout<<"\n  Please, enter the number: ";
	cin>>number;//reads an integer into number

	if( number % 5 == 0 )//Checks whether the value stored in variable, number, is divisible by 5
                       //If the condition is true
		cout<<" \n "<< number <<" is a multiple of 5 \n";
	else
                      //If the condition is false
		cout<<" \n "<< number <<" is not a multiple of 5 \n";
return 0;
}
