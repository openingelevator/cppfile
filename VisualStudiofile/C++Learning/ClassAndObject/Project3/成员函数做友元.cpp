#include<iostream>
#include<string>
using namespace std;
class Building;
class GoodFriend
{
public:
	Building* building;
	GoodFriend();
	void visit();//�ô˺�������Building�е�˽�г�Ա
	void visit2();//�ô˺������ɷ���Building�е�˽�г�Ա

};
class Building
{
	//���߱�������GoodFriend���µ�visis��Ա������Ϊ�������Ԫ�����Է���˽�г�Ա
	friend void GoodFriend::visit();
public:
	Building()
	{
		m_BedRoom = "����";
		m_SittingRoom = "����";
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
	cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "visit�������ڷ��ʣ�"<<building->m_BedRoom << endl;
}
void GoodFriend::visit2()
{
	cout << "visit�������ڷ��ʣ�" << building->m_SittingRoom << endl;
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