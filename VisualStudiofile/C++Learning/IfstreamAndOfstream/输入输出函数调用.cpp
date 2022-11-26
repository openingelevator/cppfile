#include <iostream>
using namespace std;
int main()
{
	 //const char* word = "again";
	 //cout << "Value of word is: " << word << endl
		// << "Value of static_cast< void * >( word ) is: "
		// << static_cast<const void*>(word) << endl;

	/*int character; 
	cout << "Before input, cin.eof() is " << cin.eof() << endl
	 << "Enter a sentence followed by end-of-file:" << endl;
		   while ((character = cin.get()) != EOF)
		      cout.put(character);
		   cout << "\nEOF in this system is: " << character << endl;
		   cout << "After input of EOF, cin.eof() is " << cin.eof() << endl;*/

	 //const int SIZE = 80;
	 //char buffer1[SIZE];
	 //char buffer2[SIZE];
	 //cout << "Enter a sentence:" << endl;
	 //cin >> buffer1;
	 //cout << "\nThe string read with cin was:" << endl
	 //<< buffer1 << endl << endl;
	 //cin.get(buffer2, SIZE);
	 //cout << "The string read with cin.get was:" << endl
		// << buffer2 << endl;

	 const int SIZE = 80;
     char buffer[SIZE]; 
	cout << "Enter a sentence:" << endl;
	cin.read(buffer, 20);
	cout << "\nThe sentence entered is:" << endl;
	cout.write(buffer, cin.gcount());
	cout << endl;
	   return 0;
} 
