#include<iostream>
#include"HugeInteger.h"
using namespace std;
int main()
{
	int a[40] = { 3,4,1 ,4,6,3,6,7,3};
	int b[40] = { 5,2,6 };
	HugeInteger h1;
	h1.input(a);
	HugeInteger h2;
	h2.input(b);
	cout << "h1大小为：" << endl;
	h1.output();
	cout << "h2的大小为：" << endl;
	h2.output();
	cout << "h1+h2的结果为" << endl;
	HugeInteger h3=h1.add(h2);
	h3.output();
	cout << "h2-h1的结果为" << endl;
	HugeInteger h4=h2.subtract(h1);
	h4.output();
	return 0;
}