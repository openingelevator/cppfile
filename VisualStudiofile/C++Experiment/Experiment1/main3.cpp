#include<iostream>
#include"IntegerSet.h"
using namespace std;
int main()
{
	int a[8] = { 2,4,5,6,7,8,3,10 };
	int b[8] = { 1,4,52,33,6,4,2,7 };
	IntegerSet integer1(a,8);
	IntegerSet integer2(b,8);
	IntegerSet integer3 = integer1.unionOfSets(integer2);
	IntegerSet integer4 = integer1.intersectionOfSets(integer2);
	cout << "integer1����Ϊ" << endl;
	integer1.printSet();
	cout << endl;
	cout << "integer2����Ϊ" << endl;
	integer2.printSet();
	cout << endl;
	cout << "integer1��integer2�Ľ���Ϊ" << endl;
	integer4.printSet();
	cout << endl;
	cout << "����20�Ľ��Ϊ��" << endl;
	integer4.insertElement(20);
	integer4.printSet();
	cout << endl;
	cout << "integer1��integer2�Ĳ���Ϊ��" << endl;
	integer3.printSet();
	return 0;

}