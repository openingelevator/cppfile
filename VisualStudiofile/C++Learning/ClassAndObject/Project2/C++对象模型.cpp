#include<iostream>
using namespace std;
class Person
{
	int m_a;//非静态成员变量属于对象上
	static int m_b;//静态成员变量，不属于类的对象上
	void func(){}//非静态成员函数，成员变量与成员函数分开存储，不属于类的对象上
	static void func1(){}//静态成员函数，不属于类的对象上
};
int Person::m_b= 0;
void test01()
{
	Person p;
	//空对象占用的内存空间为1个字节
	//C++编译器会给每个空对象也分配1个字节的空间是为了区分空对象占内存的位置
	cout << "size of p=" << sizeof(p) << endl;
}
void test02()
{
	//当类中只有int m_a一个非静态成员变量时，p的内存为4个字节
	//当在类中多声明一个static类型的成员变量时，p的内存仍为4个字节
	//因为静态成员变量不属于类对象上
	Person p;
	cout << "size of p=" << sizeof(p) << endl;
}
int main()
{
	//test01();
	test02();
	return 0;
}