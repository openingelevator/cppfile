#include<iostream>
#include<fstream>
using namespace std;
//�������ļ���д�ļ�
class Person
{
public:
	char m_Name[64];
	int m_Age;
};
void test01()
{
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);
	Person p = { "����",18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();

}
void test02()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "������" << p.m_Name <<" " << "���䣺" << p.m_Age << endl;
	ifs.close();
}
int main()
{
	test02();
	return 0;
}