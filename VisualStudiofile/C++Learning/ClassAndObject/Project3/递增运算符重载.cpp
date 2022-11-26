#include<iostream>
using namespace std;
//递增运算符重载需要区分好前置递增与后置递增的区别
class MyInteger
{
	friend ostream& operator<<(ostream& cout,const MyInteger& integer);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//重载前置递增运算符，返回引用是为了一直对同一个数据进行操作
	MyInteger& operator++()
	{
		m_Num++;
		return *this;
	}
	//重载后置递增运算符
	//MyInteger operator++(int) int 代表占位参数，可以用于区分前置与后置递增
	//后置递增返回值，不返回引用，因为返回的是局部变量，函数执行完后就被释放，以引用方式返回属于非法操作
	MyInteger operator++(int)
	{
		//先记录当时结果
		MyInteger temp = *this;
		//后递增
		m_Num++;
		//最后将记录结果进行返回
		return temp;
	}
private:
	int m_Num;

};

ostream& operator<<(ostream &cout,const MyInteger& integer)
{
	cout << integer.m_Num ;
	return cout;
}


void test01()
{
	MyInteger myint;
	cout << ++myint << endl;
}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint;
}

int main()
{
	//test01();
	test02();
	return 0;
}