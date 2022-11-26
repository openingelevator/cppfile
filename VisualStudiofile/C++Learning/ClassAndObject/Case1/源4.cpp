#include<iostream>
#include"RationalNumber.h"
using namespace std;
int main()
{
	RationalNumber r1(2, 4);
	RationalNumber r2(5, 6);
	RationalNumber r3 = r1 + r2;
	RationalNumber r4 = r2 - r1;
	RationalNumber r5 = r3 * r1;
	RationalNumber r6 = r1 / r2;
	cout << "r1+r2的结果为：" << endl;
	r3.print();
	cout << "r1-r2的结果为：" << endl;
	r4.print();
	cout << "r1*r2的结果为：" << endl;
	r5.print();
	cout << "r1/r2的结果为：" << endl;
	r6.print();
	if (r1 == r2)cout << "r1==r2" << endl;
	else cout << "r1!=r2" << endl;
	return 0;
}