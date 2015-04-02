#include "std_lib_facilities_3.h"

int main()
try{
	cout << "\n Please enter the first input file name: ";
	string name;
	getline(cin,name);								
	ifstream ist1(name.c_str());					//ist1 reads from the file "name"
	if (!ist1) error(" Can not open the input file", name); //If the input file name entered by user is incorrect, it prints out an error

	cout << "\n Please enter the second input file name: ";
	getline(cin,name);
	ifstream ist2(name.c_str());					//ist2 reads from the file "name"
	if (!ist2) error(" Can not open the input file", name); //If the input file name entered by user is incorrect, it prints out an error

	cout << "\n Please enter the first input file name: ";
	getline(cin,name);
	ofstream ost(name.c_str());					//ost writes to the file "name"
	if (!ost) error(" Can not open the input file", name); //If the output file name entered by user is incorrect, it prints out an error

	vector<string> input1;			//Store the readings of the input1 here
	string word;
	while (getline(ist1,word))     //getline() so that it does not miss the whitespaces
	{
		if (word == ";") break;
		input1.push_back(word);
	}

	vector<string> input2;			//Store the readings of the input2 here
	while (getline(ist2,word))     //getline() so that it does not miss the whitespaces
	{
		if (word == ";") break;
		input2.push_back(word);
	}

	int length,ctr;

	//To check the size of the vector we do not miss any line while comparing
	if (input1.size() < input2.size())
	{   
		length = input1.size();
		ctr = input2.size() - input1.size();
	}
	else
	{
		length = input2.size();
		ctr = input1.size() - input2.size();
	}


	for (int i = 0; i < length; i++)   //Comparing line by line of the two vectors input1 and input2
	{
	
		if(input1[i] == input2[i])
			ost << i + 1 << ": OK \n";  //ost makes the changes in the output file
	
		else
			ost << i + 1 << ": DIFF \n";   //ost makes the changes in the output file
	
	}
	
	for( int i = 0; i < ctr; i++)   //Say if one of the file has more lines than the other, we do not want to miss it! So to print them
		ost << length + 1 << ": DIFF \n";

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


