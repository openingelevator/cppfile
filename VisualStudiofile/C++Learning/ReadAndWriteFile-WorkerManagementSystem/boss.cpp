#include<iostream>
#include<string>
#include"boss.h"
using namespace std;
void boss::showInfo()
{
	cout << "职工编号为" << this->m_Id
		<< "\t职工姓名" << this->m_Name
		<< "\t岗位" << this->getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl;

}
//获取岗位名称
string boss::getDeptName()
{
	return "老板";
}
boss::boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;
}