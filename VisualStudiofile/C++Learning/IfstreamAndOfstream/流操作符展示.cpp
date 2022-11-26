#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	//int number;
	//cin >> number;
	//cout << number << "in hexadecimal is" << hex << number << endl;
	//cout << dec << number << "in octal is" << oct << number << endl;
	//cout << setbase(10) << number << "in decimal is" << number << endl;


	// double root2 = sqrt(2.0); // calculate square root of 2
	//	   int places; // precision, vary from 0-9
	//cout << "Square root of 2 with precisions 0-9." << endl
	//	 << "Precision set by ios_base member function "
	//	 << "precision:" << endl;
	//cout << fixed; 
	//	   for (places = 0; places <= 9; places++)
	//	   {
	//	      cout.precision(places);
	//		  cout << root2 << endl;
	//	   } 

	/*int widthValue = 4;
	char sentence[10];
	cout << "Enter a sentence" << endl;
	cin.width(5);
	while (cin >> sentence)
	{
		cout.width(widthValue++);
		cout << sentence << endl;
		cin.width(5);
	}*/

	//int x = 10000;
	//cout << x << " printed as int right and left justified\n"
	//	<< "and as hex with internal justification.\n"
	//	 << "Using the default pad character (space):" << endl;
	//cout << showbase << setw(10) << x << endl;
	//   // display x with left justification 
	//cout << left << setw(10) << x << endl;		   
	//// display x as hex with internal justification
	//cout << internal << setw(10) << hex << x << endl << endl;		   
	//cout << "Using various padding characters:" << endl;
	//// display x using padded characters (right justification)
	//cout << right;
	//cout.fill('*');
	//cout << setw(10) << dec << x << endl;
	//// display x using padded characters (left justification)
	//cout << left << setw(10) << setfill('%') << x << endl;
	//// display x using padded characters (internal justification)		   
	//cout << internal << setw(10) << setfill('^') << hex
	//	 << x << endl;

	  int integerValue;
	
			   // display results of cin functions
			   cout << "Before a bad input operation:"
		 << "\ncin.rdstate(): " << cin.rdstate()
		 << "\n    cin.eof(): " << cin.eof()
		 << "\n   cin.fail(): " << cin.fail()
		 << "\n    cin.bad(): " << cin.bad()
		 << "\n   cin.good(): " << cin.good()
		 << "\n\nExpects an integer, but enter a character: ";
	
			   cin >> integerValue; // enter character value
	   cout << endl;
	
// display results of cin functions after bad input
cout << "After a bad input operation:"
<< "\ncin.rdstate(): " << cin.rdstate()
<< "\n    cin.eof(): " << cin.eof()
<< "\n   cin.fail(): " << cin.fail()
<< "\n    cin.bad(): " << cin.bad()
<< "\n   cin.good(): " << cin.good() << endl << endl;
cin.clear(); // clear stream
		   
// display results of cin functions after clearing cin
cout << "After cin.clear()" << "\ncin.fail(): " << cin.fail()
<< "\ncin.good(): " << cin.good() << endl;

	return 0;
}