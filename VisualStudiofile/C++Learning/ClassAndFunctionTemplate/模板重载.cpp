#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;

};
template<class T>
bool myCmp(T a, T b)
{
	if (a == b)
		return true;
	else return false;

}

//利用具体化的Person的版本实现代码，具体化会优先调用
template<>
bool myCmp(Person a, Person b)
{
	if (a.m_Age == b.m_Age && a.m_Name == b.m_Name)
		return true;
	else return false;

}


void test01()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	if (myCmp(p1, p1))cout << "p1==p2";
	else cout << "p1!=p2";

}
int main()
{
	test01();
	return 0;
}