#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	static void func()
	{
		m_a = 100;
		//m_b=200会报错，静态成员函数不能访问非静态成员变量
		//非静态成员变量必须通过对象进行访问，编译器无法分辨非静态成员变量属于哪个特定对象
		cout << "static void func函数的调用" << endl;
	}
	static int m_a;
	int m_b;
	//静态成员函数有访问权限，func2函数在类外不可访问
private:
	static void func2()
	{

	}

};
void test01()
{
	//1、通过对象进行访问
	Person p;
	p.func();
	//2、通过类名进行访问，由于类内的所有对象共享一个函数，因此不用初始化也可以调用这个函数
	Person::func();
}

int main()
{
	test01();
	return 0;
}