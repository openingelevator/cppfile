#include<iostream>
using namespace std;
//1.普通函数与函数模板都可以实现，优先调用普通函数
void myPrint(int a, int b)
{
	cout << "调用普通函数" << endl;
}
template<class T>
void myPrint(T a, T b)
{
	cout << "调用函数模板" << endl;
}

template<class T>
void myPrint(T a, T b,T c)
{
	cout << "调用重载函数模板" << endl;
}
void test01()
{
	int a = 10; 
	int b = 20;
	int c = 20;
	//此行调用普通函数,当普通函数有声明无实现时，也调用普通函数
	//myPrint(a, b);

	//2.可以通过空模板参数列表来强制调用函数模板
	myPrint<>(a,b);
	//3.函数模板也可以发生重载
	myPrint(a, b, c);
	//4.如果函数模板可以产生更好的匹配，优先调用函数模板
	char c1 = 'c';
	char c2 = 'a';
	myPrint(c1, c2);
}
int main()
{
	test01();
	return 0;
}