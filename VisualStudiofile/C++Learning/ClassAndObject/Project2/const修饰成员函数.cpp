#include<iostream>
using namespace std;
class Person
{
public:
	//在函数体内部，不管是否传参，每个成员函数内部都有一个this指针
	//this指针实际上是一个指针常量，指针的指向不可修改
	//在成员函数后加const相当于const Person *const this;
	//在成员函数后加const修饰的是this指针，使得指针指向的值也不可修改
	void showPerson()const
	{
		this->m_B = 100;
	//this->m_A=100;为非法操作
	}
	void func()
	{
		m_A = 100;
	}
	int m_A;
	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值
};
void test01()
{
	Person p;
	p.showPerson();
}
void test02()
{
	const Person p;//在对象前加const，变为常对象
	//m_A不可修改，m_B是特殊值，在常对象下也可以修改
	p.m_B = 100;
	//p.func();为非法操作，常对象只能调用常函数
	p.showPerson();
}
int main()
{
	test01();
	return 0;


}