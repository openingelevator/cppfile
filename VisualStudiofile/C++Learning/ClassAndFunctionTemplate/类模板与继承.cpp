#include<iostream>
using namespace std;
template<class T>
class Base
{
public:
	Base(T b) { m = b; }
	T m;
};
//class Son :public Base<int>//必须要知道父类中T的类型才能给子类分配空间
//{
//
//};
//如果想灵活指定类型，子类也需要变成类模板

template<class T1,class T2>
class Son2:public Base<T2>
{
public:
	Son2(T1 a,T2 b):Base<T2>(b)
	{
		this->obj = a;
		cout << "T1的类型为：" << typeid(T1).name() << endl;
		cout << "T2的类型为：" << typeid(T2).name() << endl;
	}
	T1 obj;
};
void test01()
{
	Son2<int, char>s2(2,'c');

}
int main()
{
	test01();
	return 0;
}