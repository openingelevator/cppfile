#include<iostream>
#include<vector>
#include<string>
#include<ccomplex>
using namespace std;
//Initilization could happen with parentheses, braces ,and/or assignment operators
//C++11 introduced the concept of uniform initialization, which means that for any initilization. 
//you can use one common syntax.

//ԭ���������ڿ���{n1,n2,...}֮�������һ��initializer_list<T>��������һ��array<T,n>����
//���ú���ʱ����construtor����array�ڵ�Ԫ�ػᱻ�������ֽ���һ��������
//�������������Ǹ�initializer_list<T>��������ȴ���ܸ�������T����Ȼ����Ϊ���ǻᱻ�Զ�תΪһ��initializer_list<T>����
	
void test01()
{
	int values[]{ 1,2,3 };
	vector<int>v{ 2,3,5,7,11,13,17 };
	vector<string>cities{ "Berlin","New York","Cairo" };
	for (auto it = cities.begin(); it != cities.end(); it++)
	{
		cout << *it<<" ";
	}
	complex<double>c{ 4.0,3.0};//equivalent to c(4.0,3.0);
}
int main()
{
	test01();
	system("pause");
	return 0;
}