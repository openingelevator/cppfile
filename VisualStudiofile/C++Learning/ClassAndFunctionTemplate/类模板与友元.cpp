#include<string>
#include<iostream>
using namespace std;
//提前让编译器知道Person的存在
template<class T1,class T2>
class Person;

//类外实现
template<class T1,class T2>
void printPerson(Person<T1,T2> p)
{
	cout << "姓名为" << p.m_Name << "年龄为" << p.m_Age << endl;
}

template<class T1,class T2>
class Person
{
	//全局函数类内实现
	/*friend void printPerson(Person<T1,T2> p)
	{
		cout << "姓名为" << p.m_Name << "年龄为" << p.m_Age << endl;
	}*/
	//全局函数类内实现
	//如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
	friend void printPerson<>(Person<T1, T2> p);
public:
	Person(T1 name, T2 age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

private:

	T1 m_Name;
	T2 m_Age;
};
//全局函数在类内实现
void test01()
{
	Person<string, int>p("Tom", 10);
	printPerson(p);
}
void test02()
{
	Person<string, int>p("Jack", 10);
	printPerson(p);
}
int main()
{
	test02();
	return 0;
}