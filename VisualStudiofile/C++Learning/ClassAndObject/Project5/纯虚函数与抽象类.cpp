#include<iostream>
using namespace std;
class Base
{
public:
	//只要有一个纯虚函数，这个类就称为抽象类
	//抽象类无法实例化对象
	virtual void func() = 0;
};
class Son :public Base
{
public:
	virtual void func() { cout << "func函数调用"; }
};
void test01()
{
/*	Son s;*///子类必须重写父类中的纯虚函数，否则无法实例化对象
	Base* base = new Son;
	base->func();
	delete base;
}
int main()
{
	test01();
	return 0;
}