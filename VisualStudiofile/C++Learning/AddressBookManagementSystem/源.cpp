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
//显示菜单界面
void showMenu()
{
	cout << "*************************" << endl;
	cout << "****  1、添加联系人  ****" << endl;
	cout << "****  2、显示联系人  ****" << endl;
	cout << "****  3、删除联系人  ****" << endl;
	cout << "****  4、查找联系人  ****" << endl;
	cout << "****  5、修改联系人  ****" << endl;
	cout << "****  6、清空联系人  ****" << endl;
	cout << "****  0、退出通讯录  ****" << endl;
	cout << "*************************" << endl;
}
//添加联系人
void addMember(struct Addressbook *abs)
{
	if (abs->m_size == Max)
	{
		cout << "通讯录已满无法继续添加" << endl;
		return;
	}
	else
	{
		//输入姓名
		string name;
		cout << "请输入姓名\n";
		cin >> name;
		abs->array[abs->m_size].m_name = name;
		//输入性别
		int sex=0;
		cout << "请输入性别\n男——1\n女——2" << endl;
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
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//输入年龄
		int age;
		cout << "请输入年龄\n";
		cin >> age;
		abs->array[abs->m_size].m_age = age;
		//输入电话号码
		string number;
		cout << "请输入电话号码\n";
		cin >> number;
		abs->array[abs->m_size].m_phone = number;
		//输入住址
		string address;
		cout << "请输入家庭住址\n";
		cin >> address;
		abs->array[abs->m_size].m_address = address;
		abs->m_size++;
		system("pause");
		system("cls");
	}
}
//显示联系人
void showMember(struct Addressbook *abs)
{
	if (abs->m_size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名" << " " << abs->array[i].m_name << "\t";
			cout << "性别" << " " << (abs->array[i].m_sex==1?"男":"女") << "\t";
			cout << "年龄" << " " << abs->array[i].m_age << "\t";
			cout << "电话号码" << " " << abs->array[i].m_phone << "\t";
			cout << "住址" << " " << abs->array[i].m_address << endl;
		}
		system("pause");
		system("cls");
	}

}
//检测联系人是否存在
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
//删除联系人
void deletePerson(struct Addressbook* abs)
{
	cout << "请输入要删除的联系人的姓名\n";
	string name;
	cin >> name;
	int flag = detectPerson(abs, name);
	if (flag == -1)
	{
		cout << "查无此人" << endl;
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
//查找联系人
void findPerson(struct Addressbook *abs)
{
	string name;
	cout << "请输入要查找的联系人姓名\n";
	cin >> name;
	int flag = 0;
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->array[i].m_name == name)
		{
			cout << "姓名" << " " << abs->array[i].m_name << "\t";
			cout << "性别" << " " << (abs->array[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄" << " " << abs->array[i].m_age << "\t";
			cout << "电话号码" << " " << abs->array[i].m_phone << "\t";
			cout << "住址" << " " << abs->array[i].m_address << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//修改联系人
void modifyPerson(struct Addressbook* abs)
{
	string name;
	cout << "请输入您要修改的联系人\n";
	cin >> name;
	int flag=detectPerson(abs, name);
	if (flag == -1)
	{
		cout << "查无此人\n";
	}
	else
	{
		//输入姓名
		string name;
		cout << "请输入姓名\n";
		cin >> name;
		abs->array[flag].m_name = name;
		//输入性别
		int sex = 0;
		cout << "请输入性别\n男——1\n女——2" << endl;
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
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//输入年龄
		int age;
		cout << "请输入年龄\n";
		cin >> age;
		abs->array[flag].m_age = age;
		//输入电话号码
		string number;
		cout << "请输入电话号码\n";
		cin >> number;
		abs->array[flag].m_phone = number;
		//输入住址
		string address;
		cout << "请输入家庭住址\n";
		cin >> address;
		abs->array[flag].m_address = address;
		system("pause");
		system("cls");
	}
}
//清空联系人
void cleanPerson(struct Addressbook* abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
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
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
}