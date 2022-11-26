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
	//选手姓名
	string m_Name;
	//分数 最多有两轮分数
	double m_Score[2];
};