#include<iostream>
#include<set>
#include<string>
using namespace std;
class Person
{
public:
	Person(string name, int age):m_Name(name),m_Age(age)
	{

	}
	string m_Name;
	int m_Age;

};
class MyCompare
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.m_Age > p2.m_Age;
	}

};
void test01()
{
	//�Զ�����������Ͷ���ָ���������
	set<Person,MyCompare>s;
	Person p1("����", 24);
	Person p2("����", 28);
	Person p3("����", 25);
	Person p4("����", 22);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "����:" << it->m_Name << " ����:" << it->m_Age << endl;
	}
	
}
int main()
{
	test01();
	return 0;
}