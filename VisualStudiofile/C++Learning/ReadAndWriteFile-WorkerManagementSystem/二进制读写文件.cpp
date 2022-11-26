#include<iostream>
#include<fstream>
using namespace std;
//二进制文件，写文件
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
	Person p = { "张三",18 };
	ofs.write((const char*)&p, sizeof(p));
	ofs.close();

}
void test02()
{
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Person p;
	ifs.read((char*)&p, sizeof(p));
	cout << "姓名：" << p.m_Name <<" " << "年龄：" << p.m_Age << endl;
	ifs.close();
}
int main()
{
	test02();
	return 0;
}