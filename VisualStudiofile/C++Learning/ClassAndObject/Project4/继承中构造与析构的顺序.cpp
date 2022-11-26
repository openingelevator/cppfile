#include<iostream>
using namespace std;
//继承中构造与析构的顺序
class Base
{
public:
	Base()
	{
		cout << "Base构造函数" << endl;
	}
	~Base()
	{
		cout << "Base析构函数" << endl;
	}
};
class Son :public Base
{
public:
	Son()
	{
		cout << "Son的构造函数" << endl;
	}
	~Son()
	{
		cout << "Son的析构函数" << endl;
	}
};
void test01()
{
	//Base b1;
	//先构造父类，再构造子类，析构顺序一般与构造顺序相反
	Son s1;
}
int main()
{
	test01();
	return 0;
}


