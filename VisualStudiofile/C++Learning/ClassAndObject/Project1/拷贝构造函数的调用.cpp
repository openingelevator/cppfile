#include<iostream>
using namespace std;
class Person2
{
public:
	Person2()
	{
		m_age = 0;
		cout << "Person2的无参构造函数调用" << endl;;
	}
	Person2(int a)
	{
		m_age = a;
		cout << "Person2的有参构造函数调用"<<endl;
	}
	Person2(const Person2& p)
	{
		m_age = p.m_age;
		cout << "Person2的拷贝构造函数调用" << endl;;
	}
	~Person2()
	{
		cout << "Person2的析构函数调用" << endl;

	}

	int m_age;
};
//1、使用一个已经创建完毕的对象来初始化一个新对象
//void test02()
//{
//	Person2 p1(10);
//	Person2 p2(p1);
//
//}
//2、值传递的方式给函数参数传值
//void dowork(Person2 p)
//{
//
//}
//void test03()
//{
//	Person2 p;
//	dowork(p);//拷贝出临时副本
//}
//3、值方式创建局部对象
Person2 dowork2()
{
	Person2 p1;
	cout << (int*)&p1 << endl;
	return p1;

}
void test04()
{
	Person2 p = dowork2();
	cout << (int*)&p << endl;
}
int main()
{
	test04();
	return 0;

}