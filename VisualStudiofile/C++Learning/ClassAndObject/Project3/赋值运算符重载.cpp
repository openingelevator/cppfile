#include<iostream>
using namespace std;
class Person
{
public:
	Person(int age)
	{
		m_age = new int(age);
	}
	~Person()
	{
		if (m_age!= NULL)
		{
			delete m_age;
			m_age = NULL;
		}
	}
	Person& operator=(Person &p)
	{
		//编译器提供浅拷贝，类似于m_age=p.m_age;
		//应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (m_age != NULL)
		{
			delete m_age;
			m_age = NULL;
		}
		m_age = new int(*p.m_age);
		return *this;
	}

	int* m_age;

};
void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(30);
	p3=p2 = p1;//如果不重载赋值运算符，此赋值操作会导致堆区重复释放内存，使得程序崩溃
	//解决方案：使用深拷贝解决浅拷贝带来的问题，重载赋值运算符
	cout << "p1的年龄为：" << *p1.m_age << endl;
	cout << "p2的年龄为：" << *p2.m_age << endl;
	cout << "p3的年龄为：" << *p3.m_age << endl;
}
int main()
{
	test01();
	return 0;
}