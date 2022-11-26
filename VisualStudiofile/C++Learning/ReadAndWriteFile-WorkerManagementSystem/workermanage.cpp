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
		cout << "�ļ�������" << endl;
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
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڲ��Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ" << num << endl;
	this->m_EmpNum = num;
	this->m_FileIsEmpty = false;
	//�ȿ��ٿռ䣬�ٽ��ļ��е����ݴ�ŵ�������
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
	cout << "****��ӭʹ��ְ������ϵͳ****" << endl;
	cout << "***** 0���˳�����ϵͳ  *****" << endl;
	cout << "***** 1������ְ����Ϣ  *****" << endl;
	cout << "***** 2����ʾְ����Ϣ  *****" << endl;
	cout << "***** 3��ɾ����ְְ��  *****" << endl;
	cout << "***** 4���޸�ְ����Ϣ  *****" << endl;
	cout << "***** 5������ְ����Ϣ  *****" << endl;
	cout << "***** 6�����ձ������  *****" << endl;
	cout << "***** 7����������ĵ�  *****" << endl;
	cout << "****************************" << endl;
	cout << endl;

}
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp()
{
	int addnum = 0;
	cout << "����������ְ��������" << endl;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = this->m_EmpNum + addnum;
		//�����¿ռ�
		WorkerBase** newspace = new WorkerBase * [newsize];
		if (this->m_EmpArray!=NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		//�������
		for (int i = 0; i < addnum; i++)
		{
			int id, flag = 1;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����Ա�����" << endl;
			cin >> id;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Id==id)
				{
					cout << "ְ������ظ�������������" << endl;
					cin >> id;
				}
			}
			cout << "�������" << i + 1 << "����Ա������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//��������Ա��������������
			newspace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newspace;
		//�����µ�ְ������
		this->m_EmpNum = newsize;
		//������
		this->save();
		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addnum << "����ְ��" << endl;
	}
	else
	{
		cout << "�������������" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "��������ְԱ�����" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "��ְ����Ų����ڣ�����������" << endl;
			this->Del_Emp();
		}
		else
		{
			for (int i = index; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			//ͬ�����ݵ��ļ���
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int id;
		cout << "��������ְԱ�����" << endl;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
	
		}
		else
		{
			delete this->m_EmpArray[index];
			int newId = 0;
			string newName = " ";
			int dSelect = 0;
			cout << "�鵽" << id<< "��ְ������������ְ�����" << endl;
			cin >> newId;
			cout << "������������" << endl;
			cin >> newName;
			cout << "�������ְ����λ��" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "1������Ų���" << endl;
		cout << "2������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ�����" << endl;
			cin >> id;
			int ret = this->IsExist(id);
			if (ret == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "���ҳɹ�����ְ����Ϣ����" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << "�ŵ���Ϣ����" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minORmax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)//����
				{
					if (m_EmpArray[minORmax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minORmax = j;
					}
				}
				else//����
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
		cout << "����ɹ����������Ϊ" << endl;
		this->save();
		this->Show_Emp();

	}
}
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
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
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}