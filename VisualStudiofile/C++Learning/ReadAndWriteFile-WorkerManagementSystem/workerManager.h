#pragma once
#include<iostream>
#include<string>
#include<fstream>
#define FILENAME "empFile.txt"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"worker.h"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	~WorkerManager();
	//展示菜单
	void Show_Menu();
	void exitSystem();
	void Add_Emp();
	//统计文件中的人数
	int get_EmpNum();
	//初始化员工
	void ini_Emp();
	//保存更改
	void save();
	//显示员工
	void Show_Emp();
	//判断职工是否存在
	int IsExist(int);
	void Del_Emp();
	//修改职工
	void Mod_Emp();
	//查找员工
	void Find_Emp();
	//给员工排序
	void Sort_Emp();
	//清空文件
	void Clean_File();

	int m_EmpNum;
	WorkerBase** m_EmpArray;
	bool m_FileIsEmpty;
};
