#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	fstream fs;
	fs.open("datasize.txt", ios::out);
	fs.close();
	fs.open("datasize.txt", ios::out | ios::in);
	fs << left << setw(35) << "char" << '\t' << right <<setw(3) << sizeof(char) << '\n';
	fs << left << setw(35) << "unsigned char"  << '\t' << right << setw(3) << sizeof(unsigned char) << '\n';
	fs << left << setw(35) << "short int"  << '\t' << right << setw(3) << sizeof(short int) << '\n';
	fs << left << setw(35) << "unsigned short int"  << '\t' << right << setw(3) << sizeof(unsigned short int) << '\n';
	fs << left << setw(35) << "int"<< '\t' << right << setw(3) << sizeof(int) << '\n';
	fs << left << setw(35) << "unsigned int"  << '\t' << right << setw(3) << sizeof(unsigned int) << '\n';
	fs << left << setw(35) << "long int"  << '\t' << right << setw(3) << sizeof(long int) << '\n';
	fs << left << setw(35) << "unsigned long int" << '\t' << right << setw(3) << sizeof(unsigned long int) << '\n';
	fs << left << setw(35) << "float" << '\t' << right << setw(3) << sizeof(float) << '\n';
	fs << left << setw(35) << "double"  << '\t' << right << setw(3) << sizeof(double) << '\n';
	fs << left << setw(35) << "long double" << '\t' << right << setw(3) << sizeof(long double) << '\n';
	return 0;
}