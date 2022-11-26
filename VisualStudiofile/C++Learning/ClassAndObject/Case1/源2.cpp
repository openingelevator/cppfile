#include<iostream>
#include"SavingAccount.h"
using namespace std;
int main()
{
	SavingAccount saver1(2000.00), saver2(3000.00);
	cout << "saver1的月利率为" << saver1.calculateMonthlyInterest() / 1.0 /2000.00 << endl;
	cout << "saver1的新余额为" << saver1.getBalance() << endl;
	cout << "saver2的月利率为" << saver2.calculateMonthlyInterest() / 1.0 / 3000.00 << endl;
	cout << "saver2的新余额为" << saver2.getBalance() << endl;
	saver1.modifyInterestRate(0.04);
	saver2.modifyInterestRate(0.04);
	cout << "利率修改之后" << endl;
	cout << "saver1下个月的利息为" << saver1.calculateMonthlyInterest() << endl;
	cout<<"saver1的新余额为"<< saver1.getBalance() << endl;
	cout << "saver2下个月的利息为" << saver2.calculateMonthlyInterest() << endl;
	cout << "saver2的新余额为" << saver2.getBalance() << endl;
	return 0;
}