/*HW1PR4
Section - 306
Name - Kaivan Shah*/
#include"std_lib_facilities_3.h"

int main()//C++ programs start by executing the function main
{
	int x = 1;//x is a variable of datatype integer and initialized with value 1
	
        for(int i = 1; i <= 11; i++)//for i in the range of [0,11]
	{
		int x2 = x * x ;
		double y = sqrt(x2);//y of double datatype is a squareroot of x2, sqrt() is a mathfunction in the library
		cout<<"\n Square root of "<< x <<" squared is "<< y <<"\n";
		x = x * 10;
	}
	return 0;
}

















