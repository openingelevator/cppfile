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
	//չʾ�˵�
	void Show_Menu();
	void exitSystem();
	void Add_Emp();
	//ͳ���ļ��е�����
	int get_EmpNum();
	//��ʼ��Ա��
	void ini_Emp();
	//�������
	void save();
	//��ʾԱ��
	void Show_Emp();
	//�ж�ְ���Ƿ����
	int IsExist(int);
	void Del_Emp();
	//�޸�ְ��
	void Mod_Emp();
	//����Ա��
	void Find_Emp();
	//��Ա������
	void Sort_Emp();
	//����ļ�
	void Clean_File();

	int m_EmpNum;
	WorkerBase** m_EmpArray;
	bool m_FileIsEmpty;
};
