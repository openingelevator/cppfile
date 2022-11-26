#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;
void test01()
{
    const char* word = "hello";
	cout << "Value of word is: " << word << endl
		<< "Value of static_cast< void * >( word ) is: "
	<< static_cast<const void*>(word) << endl;
	cout << endl;
}
void test02()
{
	const int SIZE = 80;
	char buffer1[SIZE];
	char buffer2[SIZE];
	 cout << "Enter a sentence:" << endl;
	 cin >> buffer1;
	 cout << "\nThe string read with cin was:" << endl
	 << buffer1  << endl;
	 cin.get(buffer2, SIZE);
     cout << "The string read with cin.get was:" << endl
     << buffer2 << endl;
	 cout << endl;
}
void test03()
{
	int widthValue = 4;
	char sentence[10];
	cout << "Enter a sentence:" << endl;
	cin.width(5);
	while (cin >> sentence)
	{
		cout.width(widthValue++);
		cout << sentence << endl;
		cin.width(5);
	}
}
void test04()
{
	int number;
	cout << "Enter a decimal number: ";
	cin >> number; 	 
	  
	cout << number << " in hexadecimal is: " << hex
		<< number << endl;
	cout << dec << number << " in octal is: "<< oct 
		<< number << endl;
	cout << setbase(10) << number << " in decimal is: "
	    << number << endl;
	cout << endl;
}
void test05()
{
	 double root3 = sqrt(3.0); 
	   int places; 
     cout << "Square root of 3 with precisions 0-9." << endl
	 << "Precision set by ios_base member function "
	 << "precision:" << endl;
      cout << fixed; 
	   for (places = 0; places <= 9; places++)
	   {
	      cout.precision(places);
		  cout << root3 << endl;
	   } 
	    cout << "\nPrecision set by stream manipulator "
		 << "setprecision:" << endl;
  
		for (places = 0; places <= 9; places++)
			cout << setprecision(places) << root3 << endl;
		cout << endl;

}

void test06()
{
	int x = 10000;
   cout << x << " printed as int right and left justified\n"
   	<< "and as hex with internal justification.\n"
   	 << "Using the default pad character (space):" << endl;
   cout << showbase << setw(10) << x << endl;
   cout << left << setw(10) << x << endl;		   
   cout << internal << setw(10) << hex << x << endl << endl;		   
   cout << "Using various padding characters:" << endl;
   cout << right;
   cout.fill('*');
   cout << setw(10) << dec << x << endl;
   cout << left << setw(10) << setfill('%') << x << endl;	   
   cout << internal << setw(10) << setfill('^') << hex
   	 << x << endl;
   cout << endl;
}
void test07()
{
   double x = 0.001234567;
   double y = 1.946e9;
	
	 cout << "Displayed in default format:" << endl
	<< x << '\t' << y << endl;
	   
	 cout << "\nDisplayed in scientific format:" << endl
	<< scientific << x << '\t' << y << endl;
	   
	 cout << "\nDisplayed in fixed format:" << endl
	 << fixed << x << '\t' << y << endl;
	 cout << endl;
}
void test08()
{
	   bool booleanValue = true;
	   cout << "booleanValue is " << booleanValue << endl;
		  
	   cout << "booleanValue (after using boolalpha) is "
		 << boolalpha << booleanValue << endl << endl;
	   cout << "switch booleanValue and use noboolalpha" << endl;
		   
	   booleanValue = false; 
		     
	   cout << noboolalpha << endl; 	   
	   cout << "booleanValue is " << booleanValue << endl;
	   cout << "booleanValue (after using boolalpha) is "
		 << boolalpha << booleanValue << endl;

}
void test09()
{
	int integerValue;
	cout << "Before a bad input operation:"
		<< "\ncin.rdstate(): " << cin.rdstate()
		<< "\n    cin.eof(): " << cin.eof()
		<< "\n   cin.fail(): " << cin.fail()
		<< "\n    cin.bad(): " << cin.bad()
		<< "\n   cin.good(): " << cin.good()
		<< "\n\nExpects an integer, but enter a character: ";

	cin >> integerValue; 
	cout << endl;

	cout << "After a bad input operation:"
		<< "\ncin.rdstate(): " << cin.rdstate()
		<< "\n    cin.eof(): " << cin.eof()
		<< "\n   cin.fail(): " << cin.fail()
		<< "\n    cin.bad(): " << cin.bad()
		<< "\n   cin.good(): " << cin.good() << endl << endl;
	cin.clear(); 

	cout << "After cin.clear()" << "\ncin.fail(): " << cin.fail()
		<< "\ncin.good(): " << cin.good() << endl;
	cout << endl;
}
int main()
{
	cout << "test stream manipulator" << endl;
	test04();
	test05();
	test06();
	test07();

	cout << "test stream state function" << endl;
	test08();
	/*test09();*/

	cout << "test member function of class istream and ostream" << endl;
	test01();
	test02();
	test03();


	return 0;
}