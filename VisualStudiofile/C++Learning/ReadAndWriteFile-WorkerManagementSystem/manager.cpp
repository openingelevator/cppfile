#include<iostream>
#include<string>
#include"manager.h"
using namespace std;
void manager::showInfo()
{
	cout << "职工编号为" << this->m_Id
		<< "\t职工姓名" << this->m_Name
		<< "\t岗位" << this->getDeptName()
		<< "\t岗位职责：完成老板交给的任务，并下发给员工" << endl;

}
//获取岗位名称
string manager::getDeptName()
{
	return "经理";
}
manager::manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}