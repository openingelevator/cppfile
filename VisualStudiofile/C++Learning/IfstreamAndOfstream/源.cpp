#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;
#include"clientdata.h"
void outputLine(ostream & output, const ClientData & record)
{
	   output << left << setw(10) << record.getAccountNumber()
		<< setw(16) << record.getLastName()
		 << setw(11) << record.getFirstName()
		 << setw(10) << setprecision(2) << right << fixed
		 << showpoint << record.getBalance() << endl;
} // end function outputLine
int  main()
{
	/*int account;
	char lastname[30];
	char firstname[30];
	double balance;*/
	ClientData client; // create record
	//ofstream outClientFile("client.txt", ios::out | ios::binary);
	//if (!outClientFile)
	//{
	//	cerr << "file cannot load" << endl;
	//	exit(1);
	//}
	ifstream inCredit("client.txt", ios::in | ios::binary);
	if (!inCredit)
	{
		cerr << "File cannot open" << endl;
		exit(1);
	}
	   cout << left << setw(10) << "Account" << setw(16)
		 << "Last Name" << setw(11) << "First Name" << left
		 << setw(10) << right << "Balance" << endl;
	
	  //cin >> account >> lastname >> firstname >> balance;
	  // client.setAccountNumber(account);
	  // client.setLastName(lastname);
	  // client.setFirstName(firstname);
	  // client.setBalance(balance);
	  // outClientFile.write(reinterpret_cast<char*>(&client),
		 //  sizeof(ClientData));
	  //read first record from file                       
	inCredit.read(reinterpret_cast<char*>(&client),
				      sizeof(ClientData));
	
	  // read all records from file          
	while (inCredit && !inCredit.eof())
	{
		// display record
		if (client.getAccountNumber() != 0)
		outputLine(cout, client);
		inCredit.read(reinterpret_cast<char*>(&client),
					 	    sizeof(ClientData));	 
	} // end while  
	inCredit.close();
    return 0;
}
