#include<iostream>
using namespace std;

class Person
{
	friend ostream& operator<<(ostream& cout, Person& p);

public:
	Person(int a,int b)
	{
		m_A = a;
		m_B = b;
	}
private:
	//成员函数重载左移运算符  p.operator<<(cout)简化版本为p<<cout
	// 一般不会利用成员函数来重载左移运算符
	//void operator<<()
	//{

	//}
	int m_A;
	int m_B;
};
//只能利用全局函数重载左移运算符
ostream& operator<<(ostream &cout,Person &p)
{
	cout << "m_A=" << p.m_A << endl;
	cout << "m_B=" << p.m_B;
	return cout;
}
void test01()
{
	Person p(10,10);
	//p.m_A = 10;
	//p.m_B = 10;
	//由链式编程思想，p后面如果要加上<<，则重载函数的返回值必须与cout类型相同
	cout << p << endl;
}
int main()
{
	test01();
	return 0;
}