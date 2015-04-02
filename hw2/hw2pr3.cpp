/*HW2PR3
Section - 306
Name - Kaivan Shah*/
#include "std_lib_facilities_3.h"

int main()
{
	vector<string> words; //A vector called words of string datatype
	
	string temp = " " ;
	int counter = 0 ; //A counter set to count number of times the words mentioned appears
	
	cout << "\n\n To count the number of times the words Aggie or Aggies or aggie or aggies occurs in your input and press ' ctrl + d ' to end the input \n " ;
	
	while ( cin>> temp ) // reads whitespace-seperated words  from the user and stores it in temp; ends when the user press 'ctrl +d'
		words.push_back( temp ); //to put into the vector words
	
	for( int i = 0; i < words.size(); ++i )
	{	
		
		if( words[i] == "Aggie"|| words[i] == "Aggies" || words[i] == "aggie" || words[i] == "aggies" ) //to check the the mentioned word appears or not
		++counter; //If the condition is true the counter increments
	
	}
	
	cout<< " \n\n The number of times the words 'Aggie' or 'Aggies' or 'aggie' or 'aggies' occur is :" << counter << endl;
	return 0;
}
