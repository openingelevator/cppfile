#include<iostream>
#include<string>
#include"employee.h"
using namespace std;
void employee::showInfo()
{
	cout << "ְ�����Ϊ" << this->m_Id
		<< "\tְ������" << this->m_Name
		<< "\t��λ" << this->getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;

}
//��ȡ��λ����
string employee::getDeptName()
{
	return "Ա��";
}
employee::employee(int id,string name,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}