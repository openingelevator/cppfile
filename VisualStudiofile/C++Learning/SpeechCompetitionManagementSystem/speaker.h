#pragma once
#include<iostream>
using namespace std;

class Speaker
{
public:
	void setName(string name);
	string getName()const;
	void setScore(double val,int index);
	double getScore(int index)const;

private:
	//ѡ������
	string m_Name;
	//���� ��������ַ���
	double m_Score[2];
};