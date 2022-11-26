#include<iostream>
using namespace std;
//多继承语法
class Base1
{
public:
	Base1()
	{
		m_A = 100;
	}
	int m_A;
};
class Base2
{
public:
	Base2()
	{
		m_A = 200;
	}
	int m_A;
};
//子类
class Son:public Base1, public Base2
{
public:
	Son()
	{
		m_C = 300;
		m_D = 400;
	}
	int m_C;
	int m_D;
};
void test01()
{
	Son s1;
	cout << "sizeof Son=" << sizeof(s1) << endl;
	//多继承时当父类中出现同名成员，需要加作用域加以区分
	cout << "Base1下的m_A=" << s1.Base1::m_A << endl;
	cout << "Base2下的m_A=" << s1.Base2::m_A;
}


int main()
{
	test01();
	return 0;

}