#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;
class manager:public WorkerBase
{
public:
	void showInfo();
	string getDeptName();
	manager(int, string, int);
};