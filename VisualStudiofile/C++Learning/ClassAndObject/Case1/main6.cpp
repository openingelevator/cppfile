#include<iostream>
#include"parenthesis.h"
using namespace std;
int main()
{
	parenthesis p1(3, 3);
	cin >> p1;
	parenthesis p2(3, 3);
	cin >> p2;
	cout << "p1Ϊ��" << endl;
		cout<< p1 << endl;
	cout <<"p2�ڶ��еڶ���Ԫ��Ϊ��" << p2(2, 2) << endl;
	if (p1 == p2)cout << "p1==p2" << endl;
	else cout << "p1!=p2" << endl;
	return 0;
}