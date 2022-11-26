#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//find遍历容器，找到则返回指定容器的迭代器，找不到则返回迭代器end
//查找内置数据类型
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
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << *it << endl;
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

//查找自定义数据类型
void test02()
{
	vector<Person>v;
	//创建数据
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	//放入容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person p5("cd", 30);
	vector<Person>::iterator it = find(v.begin(), v.end(), p5);
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << (* it).m_Name << endl;
	}

}
//find_if常用查找算法
//查找内置数据类型
//查找自定义数据类型
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
	//创建数据
	Person p1("a", 10);
	Person p2("b", 20);
	Person p3("c", 30);
	Person p4("d", 40);

	//放入容器中
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//查找年龄大于20的人
	vector<Person>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "找到了" << "姓名" << (*it).m_Name << "年龄" <<it->m_Age<< endl;
	}

	int num = count_if(v.begin(), v.end(), Greater20());
	cout <<"大于20岁的人数有：" << num << endl;
}
//adjecent_find查找相邻重复元素并返回相邻元素的第一个位置的迭代器
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
		cout << "未找到相邻重复元素" << endl;
	}
	else
	{
		cout << "找到了相邻的重复元素" << *it << endl;
	}
}
//binary_search查找指定元素是否存在
void test05()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//查找容器中是否有9
	bool ret=binary_search(v.begin(), v.end(), 9);
	if (ret)
	{
		cout << "找到了元素" << endl;
	}
	else
	{
		cout << "没有找到元素" << endl;
	}
}
//count_if算法
//统计内置数据类型
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
//统计自定义的数据类型

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