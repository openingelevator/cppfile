#include<iostream>
#include"workerManager.h"
#include<fstream>
using namespace std;
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId<< endl;

	}
	ofs.close();
}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs>> did)
	{
		num++;
	}
	return num;
}
void WorkerManager::ini_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		WorkerBase* worker = NULL;
		if (did == 1)
		{
			worker = new employee(id, name, did);
		}
		else if(did==2)
		{
			worker = new manager(id, name, did);
		}
		else
		{
			worker = new boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
			index++;
	}
	ifs.close();

}
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在并且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为" << num << endl;
	this->m_EmpNum = num;
	this->m_FileIsEmpty = false;
	//先开辟空间，再将文件中的数据存放到数组中
	this->m_EmpArray = new WorkerBase * [this->m_EmpNum];
	this->ini_Emp();
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
void WorkerManager::Show_Menu()
{
	cout << "****************************" << endl;
	cout << "****欢迎使用职工管理系统****" << endl;
	cout << "***** 0、退出管理系统  *****" << endl;
	cout << "***** 1、增加职工信息  *****" << endl;
	cout << "***** 2、显示职工信息  *****" << endl;
	cout << "***** 3、删除离职职工  *****" << endl;
	cout << "***** 4、修改职工信息  *****" << endl;
	cout << "***** 5、查找职工信息  *****" << endl;
	cout << "***** 6、按照编号排序  *****" << endl;
	cout << "***** 7、清空所有文档  *****" << endl;
	cout << "****************************" << endl;
	cout << endl;

}
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	int addnum = 0;
	cout << "请输入增加职工的数量" << endl;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_EmpNum + addnum;
		//开辟新空间
		WorkerBase** newspace = new WorkerBase * [newsize];
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加
		for (int i = 0; i < addnum; i++)
		{
			int id, flag = 1;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新员工编号" << endl;
			cin >> id;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Id==id)
				{
					cout << "职工编号重复，请重新输入" << endl;
					cin >> id;
				}
			}
			cout << "请输入第" << i + 1 << "个新员工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			WorkerBase* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的员工保存在数组中
			newspace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[]this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newspace;
		//更新新的职工人数
		this->m_EmpNum = newsize;
		//保存结果
		this->save();
		//提示添加成功
		cout << "成功添加" << addnum << "名新职工" << endl;
	}
	else
	{
		cout << "输入的数据有误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		     return i;
	}
	return -1;
}
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入离职员工序号" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "该职工序号不存在，请重新输入" << endl;
			this->Del_Emp();
		}
		else
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//同步数据到文件中
			this->save();
			cout << "删除成功" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int id;
		cout << "请输入离职员工序号" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "修改失败，查无此人" << endl;
	
		}
		else
		{
			delete this->m_EmpArray[index];
			int newId = 0;
			string newName = " ";
			int dSelect = 0;
			cout << "查到" << id<< "号职工，请输入新职工编号" << endl;
			cin >> newId;
			cout << "请输入新姓名" << endl;
			cin >> newName;
			cout << "请输入该职工岗位：" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			WorkerBase* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new employee(newId, newName, 1);
				break;
			case 2:
				worker = new manager(newId, newName, 2);
				break;
			case 3:
				worker = new boss(newId, newName, 3);
				break;
			default:
				break;
			}
			this->m_EmpArray[index] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "1、按编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找的职工编号" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "查找成功，该职工信息如下" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id << "号的信息如下" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		 }
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minORmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//升序
				{
					if (m_EmpArray[minORmax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minORmax = j;
					}
				}
				else//降序
				{
					if (m_EmpArray[minORmax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minORmax = j;
					}
				}
			}
			if (minORmax != i)
			{
				WorkerBase* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minORmax];
				m_EmpArray[minORmax] = temp;
			}
	}
		cout << "排序成功，排序后结果为" << endl;
		this->save();
		this->Show_Emp();

	}
}
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[]this->m_EmpArray;
			this->m_EmpArray=NULL;
			this->m_FileIsEmpty = true;

		}
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}