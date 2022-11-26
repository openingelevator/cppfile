#include<iostream>
using namespace std;
class animal
{
public:
	int m_Age;
};
//利用虚继承可以解决菱形继承问题
//在继承之前加上关键字virtual变为虚继承
//animal类称为虚基类
//加上关键字virtual后，sheepCamel从两个派生类继承下来的不再是两份数据，而是vbptr即虚基类指针
//vbptr指向vbtable即虚基类列表，列表中记录着数据地址的偏移量，加上后最终指向唯一一份数据
class sheep :virtual public animal{};
class camel :virtual public animal{};
class sheepCamel :public sheep,public camel{};
void test01()
{
	sheepCamel s1;
	s1.sheep::m_Age = 18;
	s1.camel::m_Age = 28;
	//当菱形继承，两个父类拥有相同的数据，需要用作用域加以区分
	cout << "s1.sheep::m_Age =" << s1.sheep::m_Age << endl;
	cout << "s1.camel::m_Age =" << s1.camel::m_Age << endl;
	//菱形继承导致数据有两份，造成资源浪费
	cout << "s1.m_Age=" << s1.m_Age << endl;
}
int main()
{
	test01();
	return 0;
}