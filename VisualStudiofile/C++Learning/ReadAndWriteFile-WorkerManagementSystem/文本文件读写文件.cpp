#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void test01()
{
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "������18" << endl;
	ofs.close();
}
void test02()
{
	ifstream ifs;
	ifs.open("text.txt", ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//������
	//��ʽһ
	/*char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	//��ʽ��
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	//��ʽ��
	/*string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}*/
	//��ʽ��
	char c;
	while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}
	ifs.close();
}
int main()
{
	//test01();
	test02();
	return 0;

}