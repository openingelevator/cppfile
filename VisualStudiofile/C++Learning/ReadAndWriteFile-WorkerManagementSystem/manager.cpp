#include<iostream>
#include<string>
#include"manager.h"
using namespace std;
void manager::showInfo()
{
	cout << "ְ�����Ϊ" << this->m_Id
		<< "\tְ������" << this->m_Name
		<< "\t��λ" << this->getDeptName()
		<< "\t��λְ������ϰ彻�������񣬲��·���Ա��" << endl;

}
//��ȡ��λ����
string manager::getDeptName()
{
	return "����";
}
manager::manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}