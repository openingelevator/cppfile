#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		m_age = age;
		m_name = name;
	}
	//����==
	bool operator==(Person &p)
	{
		if (p.m_age == this->m_age && p.m_name == this->m_name)
		{
			return true;
		}
		else
			return false;

	}
	bool operator!=(Person& p)
	{
		if (p.m_age == this->m_age && p.m_name == this->m_name)
		{
			return false;
		}
		else
			return true;

	}
	int m_age;
	string m_name;
};
void test01()
{
	Person p1("Tom", 18);
	Person p2("Tom", 20);
	if (p1 == p2)
	{
		cout << "p1��p2����ȵ�" << endl;
	}
	else if(p1!=p2)
	{
		cout << "p1��p2�ǲ���ȵ�" << endl;
	}
}
int main()
{
	test01();
	return 0;
}