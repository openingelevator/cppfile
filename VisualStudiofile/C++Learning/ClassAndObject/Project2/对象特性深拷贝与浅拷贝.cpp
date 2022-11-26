#include<iostream>
using namespace std;
class Person
{
public:
	Person()
	{
		cout << "Person的默认构造函数调用" << endl;
	}
	Person(int age,int height)
	{
		m_age = age;
		m_height = new int(height);
		cout << "Person的有参构造函数调用" << endl;
	}
	//自己实现拷贝构造函数，解决浅拷贝带来的问题
	Person(const Person& p)
	{
		cout << "Person拷贝构造函数调用" << endl;
		m_age = p.m_age;
		//深拷贝构造
		m_height = new int(*p.m_height);
	}
	~Person()
	{
		//析构代码，将堆区开辟的数据做释放操作
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;
		}
		cout << "Person的析构函数调用" << endl;
	}
	int m_age=0;
	int* m_height=NULL;
};
void test01()
{
	Person p1(10, 160);
	cout << "p1的年龄为：" << p1.m_age << "身高为：" << *p1.m_height << endl;
	//如果利用编译器提供的拷贝构造函数，会做浅拷贝操作
	//p1与p2都执行释放操作，由于局部对象存放在栈区，由先进后出原则会先释放p2
    //浅拷贝到来的问题是堆区的内存重复释放，因此使用深拷贝构造
	Person p2(p1);
	cout << "p2的年龄为：" << p2.m_age << "身高为：" << *p2.m_height << endl;
}
int main()
{
	test01();
	return 0;
}