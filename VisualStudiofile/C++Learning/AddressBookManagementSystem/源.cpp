#include<iostream>
#include<string>
using namespace std;
const int Max= 1000;
struct Person 
{
	string m_name;
	int m_sex=0;
	int m_age=0;
	string m_phone;
	string m_address;
};
struct Addressbook 
{
	struct Person array[Max];
	int m_size=0;

};
//��ʾ�˵�����
void showMenu()
{
	cout << "*************************" << endl;
	cout << "****  1�������ϵ��  ****" << endl;
	cout << "****  2����ʾ��ϵ��  ****" << endl;
	cout << "****  3��ɾ����ϵ��  ****" << endl;
	cout << "****  4��������ϵ��  ****" << endl;
	cout << "****  5���޸���ϵ��  ****" << endl;
	cout << "****  6�������ϵ��  ****" << endl;
	cout << "****  0���˳�ͨѶ¼  ****" << endl;
	cout << "*************************" << endl;
}
//�����ϵ��
void addMember(struct Addressbook *abs)
{
	if (abs->m_size == Max)
	{
		cout << "ͨѶ¼�����޷��������" << endl;
		return;
	}
	else
	{
		//��������
		string name;
		cout << "����������\n";
		cin >> name;
		abs->array[abs->m_size].m_name = name;
		//�����Ա�
		int sex=0;
		cout << "�������Ա�\n�С���1\nŮ����2" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->array[abs->m_size].m_sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//��������
		int age;
		cout << "����������\n";
		cin >> age;
		abs->array[abs->m_size].m_age = age;
		//����绰����
		string number;
		cout << "������绰����\n";
		cin >> number;
		abs->array[abs->m_size].m_phone = number;
		//����סַ
		string address;
		cout << "�������ͥסַ\n";
		cin >> address;
		abs->array[abs->m_size].m_address = address;
		abs->m_size++;
		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ��
void showMember(struct Addressbook *abs)
{
	if (abs->m_size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "����" << " " << abs->array[i].m_name << "\t";
			cout << "�Ա�" << " " << (abs->array[i].m_sex==1?"��":"Ů") << "\t";
			cout << "����" << " " << abs->array[i].m_age << "\t";
			cout << "�绰����" << " " << abs->array[i].m_phone << "\t";
			cout << "סַ" << " " << abs->array[i].m_address << endl;
		}
		system("pause");
		system("cls");
	}

}
//�����ϵ���Ƿ����
int detectPerson(struct Addressbook* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->array[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
//ɾ����ϵ��
void deletePerson(struct Addressbook* abs)
{
	cout << "������Ҫɾ������ϵ�˵�����\n";
	string name;
	cin >> name;
	int flag = detectPerson(abs, name);
	if (flag == -1)
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = flag; i < abs->m_size; i++)
		{
			abs->array[i] = abs->array[i + 1];
		}
		abs->m_size--;
		system("pause");
		system("cls");
	}
}
//������ϵ��
void findPerson(struct Addressbook *abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ������\n";
	cin >> name;
	int flag = 0;
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->array[i].m_name == name)
		{
			cout << "����" << " " << abs->array[i].m_name << "\t";
			cout << "�Ա�" << " " << (abs->array[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "����" << " " << abs->array[i].m_age << "\t";
			cout << "�绰����" << " " << abs->array[i].m_phone << "\t";
			cout << "סַ" << " " << abs->array[i].m_address << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�޸���ϵ��
void modifyPerson(struct Addressbook* abs)
{
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ��\n";
	cin >> name;
	int flag=detectPerson(abs, name);
	if (flag == -1)
	{
		cout << "���޴���\n";
	}
	else
	{
		//��������
		string name;
		cout << "����������\n";
		cin >> name;
		abs->array[flag].m_name = name;
		//�����Ա�
		int sex = 0;
		cout << "�������Ա�\n�С���1\nŮ����2" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->array[flag].m_sex = sex;
				break;
			}
			else
			{
				cout << "������������������" << endl;
			}
		}
		//��������
		int age;
		cout << "����������\n";
		cin >> age;
		abs->array[flag].m_age = age;
		//����绰����
		string number;
		cout << "������绰����\n";
		cin >> number;
		abs->array[flag].m_phone = number;
		//����סַ
		string address;
		cout << "�������ͥסַ\n";
		cin >> address;
		abs->array[flag].m_address = address;
		system("pause");
		system("cls");
	}
}
//�����ϵ��
void cleanPerson(struct Addressbook* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	struct Addressbook abs;
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
			addMember(&abs);
			break;
		case 2:
			showMember(&abs);
			break;
		case 3:
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
}