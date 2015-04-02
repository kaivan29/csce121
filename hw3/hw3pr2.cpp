#include "std_lib_facilities_3.h"

void fibonacci(int x, int y, vector<int> &v, int n) //To calculate and print fibonacci series
{
	v[0] = x;
	v[1] = y;

	cout << v[0] << " , " << v[1] ;
	
	for (int i = 2; i < n; i++) //loop to calculate the fibonacci series and store it in vector v
	{
		v[i] = v[i - 2] + v[i - 1];
		cout << " , " << v[i] ;
	}
}

 int main()
try{
	int no1=0, no2=0, size=0;
	
	cout << "\n Please enter the the value of no1: ";
	cin >> no1;
	
	cout << "\n Please enter the the value of no2: ";
	cin >> no2;
	
	cout << "\n Please enter the the value of size: ";
	cin >> size;
	
	vector<int> v(size,0); //vector v of type int to store the fibonacci series number
	
	cout << "\n The Fibonacci series is : \n";
	fibonacci(no1, no2, v, size); //calls by value for no1, no2 , size and calls by reference for the vector v to calculate the fibonacci series of no1 and no2
	
	cout<< "\n\n Value of  next-to-last entry in the vector divided by the last entry in the vector: " ;
	double result = (double)v[size-2]/v[size - 1] ; // ressult of  next-to-last entry in the vector divided by the last entry in the vector
	cout <<" \n " << result<<"\n";
	
	return 0;    //0 indicates success
}

catch(exception& e) //catches the exception and prints what kind of  error it is 
{
	cerr << "Error: "<< e.what() <<"\n";
	keep_window_open();
	return 1;  //1 indicates failure
}

catch(...) // catches an unknown exception
{
        cerr << "Unknown exception! \n";
        keep_window_open();
        return 2;  //2 indicates failure
}

