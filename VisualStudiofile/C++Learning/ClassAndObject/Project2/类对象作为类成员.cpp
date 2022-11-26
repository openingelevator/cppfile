#include<iostream>
#include<string>
using namespace std;

class Phone
{
public:

	Phone(string pname)
	{
		m_Pname = pname;
		cout << "Phone的构造函数调用" << endl;
	}
	~Phone()
	{
		cout << "Phone的析构函数调用" << endl;
	}


	string m_Pname;

};

class Person
{
public:
	//隐式转换，Phone m_Phone=pname;
	Person(string name, string pname):m_name(name),m_Phone(pname)
	{
		cout << "Person的构造函数调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数调用" << endl;
	}
	string m_name;
	//当其他类的对象作为本类的成员时，先构造其他类的对象，再构造本类的对象
	//析构的顺序与构造相反
	Phone m_Phone;

};
void test01()
{
	Person p("张三","苹果");
}
int main()
{
	test01();
	return 0;
}