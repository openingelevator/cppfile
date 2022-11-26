#include<string>
#include<iostream>
using namespace std;
//��ǰ�ñ�����֪��Person�Ĵ���
template<class T1,class T2>
class Person;

//����ʵ��
template<class T1,class T2>
void printPerson(Person<T1,T2> p)
{
	cout << "����Ϊ" << p.m_Name << "����Ϊ" << p.m_Age << endl;
}

template<class T1,class T2>
class Person
{
	//ȫ�ֺ�������ʵ��
	/*friend void printPerson(Person<T1,T2> p)
	{
		cout << "����Ϊ" << p.m_Name << "����Ϊ" << p.m_Age << endl;
	}*/
	//ȫ�ֺ�������ʵ��
	//���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�������ǰ֪����������Ĵ���
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
//ȫ�ֺ���������ʵ��
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