/*HW1PR4
Section - 306
Name - Kaivan Shah*/
#include"std_lib_facilities_3.h"

int main()//C++ programs start by executing the function main
{
	string operation;//operation is a variable of datatype string
	double o1, o2, total;// o1, o2, total are variables of datatype double

	cout<<"\n Enter the 1st operation in form of an operand, an operator and an operand seperated by spaces \n\n";
	cin>> o1 >> operation >> o2;//reads a double then a string and a double again
   
    //Checks whether the operator is '+', '-', '*' or '/'
    //According to the operator the operands get executed and the value is stored in variable total
    if( operation == "+")
		total = o1 + o2;
    else if( operation == "-")
		total = o1 - o2;
    else if( operation == "*")
		total = o1 * o2;
    else 
		total = o1 / o2;
	cout<< o1 <<" "<< operation <<" "<< o2 <<" = "<< total <<"\n\n";
	return 0;
}
