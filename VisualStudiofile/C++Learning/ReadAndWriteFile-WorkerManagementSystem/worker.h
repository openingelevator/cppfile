#pragma once
#include<string>
#include<iostream>
using namespace std;

class WorkerBase
{
public:
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;
	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ��ű��
};