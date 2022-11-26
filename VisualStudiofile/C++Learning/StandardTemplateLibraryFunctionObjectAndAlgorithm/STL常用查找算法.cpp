#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//find�����������ҵ��򷵻�ָ�������ĵ��������Ҳ����򷵻ص�����end
//����������������
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it=find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << *it << endl;
	}

}
class Person
{
public:
	Person(string name, int age)
	{
		m_Age = age;
		m_Name = name;
	}
	bool operator==(const Person&p)
	{
		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name)
			return true;
		else return false;
	}
	string m_Name;
	int m_Age;
};

//�����Զ�����������
void test02()
{
	vector<Person>v;
	//��������
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	//����������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person p5("cd", 30);
	vector<Person>::iterator it = find(v.begin(), v.end(), p5);
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << (* it).m_Name << endl;
	}

}
//find_if���ò����㷨
//����������������
//�����Զ�����������
class Greater20
{
public:
	bool operator()(const Person &p)
	{
		return p.m_Age > 20;
	}
};
void test03()
{
	vector<Person>v;
	//��������
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	//����������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//�����������20����
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "�ҵ���" << "����" << (*it).m_Name << "����" <<it->m_Age<< endl;
	}

	int num = count_if(v.begin(), v.end(), Greater20());
	cout <<"����20��������У�" << num << endl;
}
//adjecent_find���������ظ�Ԫ�ز���������Ԫ�صĵ�һ��λ�õĵ�����
void test04()
{
	vector<int>v;
	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end())
	{
		cout << "δ�ҵ������ظ�Ԫ��" << endl;
	}
	else
	{
		cout << "�ҵ������ڵ��ظ�Ԫ��" << *it << endl;
	}
}
//binary_search����ָ��Ԫ���Ƿ����
void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//�����������Ƿ���9
	bool ret=binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "�ҵ���Ԫ��" << endl;
	}
	else
	{
		cout << "û���ҵ�Ԫ��" << endl;
	}
}
//count_if�㷨
//ͳ��������������
class GreaterThan20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}

};
void test06()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(20);

	int num = count_if(v.begin(), v.end(), GreaterThan20());
	cout << num << endl;

}
//ͳ���Զ������������

int main()
{
	//test01();
	//test02();
	test03();
	//test04();
	/*test05();*/
	test06();
	return 0;
}