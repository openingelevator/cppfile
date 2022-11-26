#include<iostream>
#include<string>
#include"employee.h"
using namespace std;
void employee::showInfo()
{
	cout << "职工编号为" << this->m_Id
		<< "\t职工姓名" << this->m_Name
		<< "\t岗位" << this->getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;

}
//获取岗位名称
string employee::getDeptName()
{
	return "员工";
}
employee::employee(int id,string name,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}