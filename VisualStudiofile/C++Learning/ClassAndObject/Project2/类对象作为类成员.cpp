#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:

	Phone(string pname)
	{
		m_Pname = pname;
		cout << "Phone�Ĺ��캯������" << endl;
	}
	~Phone()
	{
		cout << "Phone��������������" << endl;
	}


	string m_Pname;

};

class Person
{
public:
	//��ʽת����Phone m_Phone=pname;
	Person(string name, string pname):m_name(name),m_Phone(pname)
	{
		cout << "Person�Ĺ��캯������" << endl;
	}
	~Person()
	{
		cout << "Person��������������" << endl;
	}
	string m_name;
	//��������Ķ�����Ϊ����ĳ�Աʱ���ȹ���������Ķ����ٹ��챾��Ķ���
	//������˳���빹���෴
	Phone m_Phone;

};
void test01()
{
	Person p("����","ƻ��");
}
int main()
{
	test01();
	return 0;
}