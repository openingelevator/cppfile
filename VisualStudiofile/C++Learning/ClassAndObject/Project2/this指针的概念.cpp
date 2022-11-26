#include<iostream>
using namespace std;
class Person
{

public:
	Person(int age)
	{
		this->age = age;
	}
	Person &PersonAddAge(Person &p)
	{
		this->age += p.age;
		//this指向p2的指针，*this是指向的就是p2这个对象本体
		return *this;
	}
	int age;

};
//解决名称冲突问题，this指针指向的是被调用的成员函数指向的对象
void test01()
{
	Person p1(18);
	cout << "p1的年龄为" << p1.age << endl;
}
//返回对象本身用*this
void test02()
{
	Person p1(10);
	Person p2(10);
	//链式编程思想
	//如果用值方式返回局部对象，函数返回的不是p2的本体，而是调用拷贝构造函数构造出来的一个新对象
	p2.PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2的年龄为" << p2.age << endl;
}
int main()
{
	/*test01();*/
	test02();
	return 0;

}