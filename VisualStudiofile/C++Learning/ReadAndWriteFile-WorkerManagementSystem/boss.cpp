#include<iostream>
#include<string>
#include"boss.h"
using namespace std;
void boss::showInfo()
{
	cout << "ְ�����Ϊ" << this->m_Id
		<< "\tְ������" << this->m_Name
		<< "\t��λ" << this->getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;

}
//��ȡ��λ����
string boss::getDeptName()
{
	return "�ϰ�";
}
boss::boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}