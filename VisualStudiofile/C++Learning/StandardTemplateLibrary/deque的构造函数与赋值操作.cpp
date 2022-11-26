#include<iostream>
#include<deque>
using namespace std;
void printDeque(deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//ʹ��const_iterator��ֹ*it�����ݱ��޸�
		cout << *it << " ";
	}
	cout << endl;
}
void test01()
{
	//Ĭ�Ϲ���
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);
	//���䷽ʽ��ֵ
	deque<int>d2(d1.begin(), d1.end()-1);
	printDeque(d2);
	
	deque<int>d3(10, 100);
	printDeque(d3);

	//��������
	deque<int>d4(d3);
	printDeque(d4);
}
int main()
{
	test01();
	return 0;
}