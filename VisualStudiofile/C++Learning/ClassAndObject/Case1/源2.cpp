#include<iostream>
#include"SavingAccount.h"
using namespace std;
int main()
{
	SavingAccount saver1(2000.00), saver2(3000.00);
	cout << "saver1��������Ϊ" << saver1.calculateMonthlyInterest() / 1.0 /2000.00 << endl;
	cout << "saver1�������Ϊ" << saver1.getBalance() << endl;
	cout << "saver2��������Ϊ" << saver2.calculateMonthlyInterest() / 1.0 / 3000.00 << endl;
	cout << "saver2�������Ϊ" << saver2.getBalance() << endl;
	saver1.modifyInterestRate(0.04);
	saver2.modifyInterestRate(0.04);
	cout << "�����޸�֮��" << endl;
	cout << "saver1�¸��µ���ϢΪ" << saver1.calculateMonthlyInterest() << endl;
	cout<<"saver1�������Ϊ"<< saver1.getBalance() << endl;
	cout << "saver2�¸��µ���ϢΪ" << saver2.calculateMonthlyInterest() << endl;
	cout << "saver2�������Ϊ" << saver2.getBalance() << endl;
	return 0;
}