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
//����д��Ա����
Building::Building()
{
	m_BedRoom = "����";
	m_SittingRoom = "����";
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
	//�������������
	building = new Building;
}
void GoodFriend::visit()
{
	cout << "���������ڷ���:" << building->m_SittingRoom << endl;
	cout << "���������ڷ���:" << building->m_BedRoom << endl;
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