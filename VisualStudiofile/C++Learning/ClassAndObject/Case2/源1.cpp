#include<iostream>
#include"Integer.h"
using namespace std;
int main()
{
	Integer i1;
	Integer i2;
	cin >> i1 >> i2;
	//测试加减乘除运算符
	cout << "i1+i2=" << i1 + i2 << endl;
	cout << "i1-i2=" << i1 - i2 << endl;
	cout << "i1*i2=" << i1 * i2 << endl;
	cout << "i1/i2=" << i1 / i2 << endl;
	//测试赋值运算符
	Integer i3 = i1;
	i3 += i2;
	cout << i3 << endl;
	Integer i4 = i1;
	i4 *= i2;
	cout << i4 << endl;
   //测试关系运算符
	if (i3 == i4)cout << "i3==i4" << endl;
	else cout << "i3!=i4" << endl;
	if (i3 >= i4)cout << "i3>=i4" << endl;
	else cout << "i3<i4" << endl;
	//测试递增运算符
	cout << "i1为" << i1 << endl;
	cout << "i1++为" << i1++ << endl;
	cout << "++i1为" << ++i1 << endl;
	//测试函数调用运算符
	Integer i6(4);
	int num = i6(5);
	cout << "num=" << num << endl;
	return 0;

}