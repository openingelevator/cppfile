#include<iostream>
using namespace std;
class Person 
{public:
	//构造函数
	Person()
	{
		cout << "Person的无参构造调用" << endl;
	}
	Person(int a)
	{
		age = a;
		cout << "Person的有参构造调用" << endl;
	}
	Person(const Person &p)
	{
		age = p.age;
		cout << "Person的拷贝构造函数调用" << endl;
	}
	int age;
};
void test01()
{
	//1括号法
	//调用默认构造函数时不要加()
	//当加上()时，编译器会认为这是一个函数的声明
	Person p1;
	Person p2(10);
	Person p3(p2);
	//2显示法
	//Person(10) Person(p4)作为匿名对象，当前行执行结束后，系统会立即回收掉匿名对象
	//不要利用拷贝构造函数初始化匿名对象， 编译器认为Person(p4)等价于Person p4,相当于对象的声明
	Person p4 = Person(10);
	Person p5 = Person(p4);
	/*3隐式转化法*/
	Person p6 = 10;
	Person p7 = p6;
}
int main()
{
	test01();
	return 0;
}