#include<iostream>
using namespace std;
//继承中同名成员的处理
class Base
{
public:
	
	Base()
	{
		 m_A = 100;
	}
	void func()
	{
		cout << "Base下func()的调用" << endl;
	}
	void func(int a)
	{
		cout << "Base下func(int a)的调用" << endl;
	}
	int m_A;
};
class Son :public Base
{
public:
	Son()
	{
		 m_A = 200;
	}
	void func()
	{
		cout << "Son下func()的调用" << endl;
	}
	int m_A;
};
//同名的成员属性的处理
void test01()
{
	Son s1;
	//子类对象可以直接访问子类中的同名成员
	cout << "Son下的m_A=" << s1.m_A << endl;
	//如果通过子类对象访问到父类中的同名成员，需要加作用域
	cout <<"Base下的m_A=" << s1.Base::m_A << endl;
	
}
//同名的成员函数的处理
void test02()
{
	Son s2;
	s2.func();//直接调用是调用子类中的同名成员
	s2.Base::func();
	//如果子类中出现和父类同名的成员函数，子类的同名函数会隐藏掉父类中所有的同名成员函数
	//如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	s2.Base::func(100);
}
int main()
{
	/*test01();*/
	test02();
	return 0;
}