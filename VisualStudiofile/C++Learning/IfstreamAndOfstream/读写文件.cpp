#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;
int main()
{
	int account;
	char name[30];
	double balance;
	/*ofstream outClientFile("client.txt", ios::out);
	if (!outClientFile)
	{ 
		cerr << "file cannot load" << endl;
	    exit(1);
	}
	while (cin >> account >> name >> balance)
	{
		outClientFile << account << " " << name << " " << balance << endl;
		cout << "?";
	}*/

	ifstream inClientFile("client.txt", ios::in);
	if (!inClientFile)
	{
		cerr << "file cannot load" << endl;
		exit(1);
	}
	cout << left << setw(10) << "Account" << setw(13)
		<< "Name" << "Balance" << endl << fixed << showpoint;
	while (inClientFile >> account >> name >> balance)
	{
		  cout << left << setw(10) << account << setw(13) << name
			 << setw(7) << setprecision(2) << right << balance << endl;
	}
	return 0;
}
