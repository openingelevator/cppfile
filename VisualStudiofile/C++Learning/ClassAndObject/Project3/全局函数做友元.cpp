#include<iostream>
#include<string>
using namespace std;

class Building
{
	friend void goodFriend(Building* building);
public:
	Building()
	{
		 m_BedRoom="����";
		m_SittingRoom = "����";
	}
	string m_SittingRoom;
private:
	string m_BedRoom;

};
//ȫ�ֺ���
void goodFriend(Building* building)
{
	cout << "�����ѵ�ȫ�ֺ������ڷ���" << building->m_SittingRoom << endl;
	cout << "�����ѵ�ȫ�ֺ������ڷ���" << building->m_BedRoom << endl;
}
void test01()
{
	Building building;
	goodFriend(&building);
}
int main()
{
	test01();
	return 0;
}