#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
void printList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//list�����ĵ�������֧��������ʣ���˲���ʹ���±귽ʽ����at()��ʽ����
//���ݽӿ�ֻ��front()��back()
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	cout << "��һ��Ԫ��Ϊ��" << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ��" << L1.back() << endl;

	//��֤��������֧���������
	//list<int>::iterator it = L1.begin();֧��˫�����������֧���������(it+=1����)
}
bool cmp(int a,int b)
{
	return a > b;
}
void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(40);
	L1.push_back(40);
	L1.push_back(80);
	cout << "��תǰ��" << endl;
	printList(L1);
	L1.reverse();
	cout << "��ת��" << endl;
	printList(L1);

	//�������в�֧��������ʵ�������������������ʹ�ñ�׼����㷨����˱���ʹ�ó�Ա����sort()��������
	/*sort(L1.begin(), L1.end());*/
	cout << "���������" << endl;
	L1.sort();
	printList(L1);
	cout << "����󣨽���" << endl;
	L1.sort(cmp);
	printList(L1);
}
int main()
{
	/*test01();*/
	test02();
	return 0;

}

