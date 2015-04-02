#include "std_lib_facilities_3.h"
int main()
try{
	string url = " ";
	
	cout << "Enter the URL of a PDF you want to open \n\n";
	cin >> url; //takes theurl of a pdf file from the user and stores it in string url
	
	int end = url.length(); //calculates the length of the string entered using function length()
	int begin = url.length() - 3;
	
	if (url.substr(0,7) == "http://" && url.substr(begin,end) == "pdf" || url.substr(begin,end) == "PDF" ) //compares the string to check if it is a valid pdf file and uses in-built function  substr() for that
	{
	
		url = "wget " + url + " -O webfile.pdf";
		
		system(url.c_str());
		system("display webfile.pdf");
		
		return 0;
	}

       else
		throw exception();    //if there is a error it throws the exception to the catch block
               // or we can print cout << " The url entered by you is not a pdf file!" ; //If it is not a valid pdf url
	
	return 0;   //0 indicates success
}

catch(exception& e) //catches the exception and prints out what the error was or what went wrong!
{
        cerr << "\n The url entered by you is not correct! Please check \n Error : "<< e.what() <<" \n\n ";
        keep_window_open();
        return 1;  //1 indicates failure
}

catch(...) //catches an unknown exception
{
        cerr << "\n Unknown exception! \n\n";
        keep_window_open();
        return 2;  //2 indicates failure
}

