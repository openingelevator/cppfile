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
	cout << "integer1集合为" << endl;
	integer1.printSet();
	cout << endl;
	cout << "integer2集合为" << endl;
	integer2.printSet();
	cout << endl;
	cout << "integer1与integer2的交集为" << endl;
	integer4.printSet();
	cout << endl;
	cout << "插入20的结果为：" << endl;
	integer4.insertElement(20);
	integer4.printSet();
	cout << endl;
	cout << "integer1与integer2的并集为：" << endl;
	integer3.printSet();
	return 0;

}