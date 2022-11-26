#include<iostream>
#include<string>
using namespace std;
class Building;
class GoodFriend
{
public:
	Building* building;
	GoodFriend();
	void visit();//让此函数访问Building中的私有成员
	void visit2();//让此函数不可访问Building中的私有成员

};
class Building
{
	//告诉编译器，GoodFriend类下的visis成员函数作为本类的友元，可以访问私有成员
	friend void GoodFriend::visit();
public:
	Building()
	{
		m_BedRoom = "卧室";
		m_SittingRoom = "客厅";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;
};
GoodFriend::GoodFriend()
{
	building = new Building;
};
void GoodFriend::visit()
{
	cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit函数正在访问："<<building->m_BedRoom << endl;
}
void GoodFriend::visit2()
{
	cout << "visit函数正在访问：" << building->m_SittingRoom << endl;
}
void test01()
{
	GoodFriend m_f1;
	m_f1.visit();
	m_f1.visit2();
}
int main()
{
	test01();

	return 0;
}