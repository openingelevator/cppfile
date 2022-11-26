#pragma once
#include<string>
#include<iostream>
#include"worker.h"
using namespace std;
class employee:public WorkerBase
{
public:
	void showInfo();
	string getDeptName();
	employee(int ,string,int);
	
};