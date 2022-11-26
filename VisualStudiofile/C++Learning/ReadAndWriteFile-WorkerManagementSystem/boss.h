#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;
class boss :public WorkerBase
{
public:
	void showInfo();
	string getDeptName();
	boss(int, string, int);
};
