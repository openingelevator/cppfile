#include<iostream>
#include<string>
using namespace std;
class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 shows" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 shows" << endl;
	}
};
template<class T>
class MyClass
{
public:
	T obj;
	//��ģ���еĳ�Ա����������ʱ�Ŵ���ʵ��
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};
void test01()
{
	MyClass<Person1>m;
	m.func1();
	MyClass<Person2>m1;
	m1.func2();
}
int main()
{
	test01();
	return 0;
}