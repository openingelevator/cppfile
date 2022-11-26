#include<iostream>
#include<string>
using namespace std;
class Building
{
	friend class GoodFriend;
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;

};
//类外写成员函数
Building::Building()
{
	m_BedRoom = "卧室";
	m_SittingRoom = "客厅";
}
class GoodFriend
{
public:
	GoodFriend();
	void visit();
	Building* building;
};
GoodFriend::GoodFriend()
{
	//创建建筑物对象
	building = new Building;
}
void GoodFriend::visit()
{
	cout << "好朋友正在访问:" << building->m_SittingRoom << endl;
	cout << "好朋友正在访问:" << building->m_BedRoom << endl;
}
void test01()
{
	GoodFriend m_f1;
	m_f1.visit();
}
int main()
{
	test01();

	return 0;

}