#include<iostream>
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
void test01()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	if (L1.empty())
	{
		cout << "L1Ϊ��" << endl;
	}
	else
	{
		cout << "L1��Ϊ��" << endl;
		cout << "L1��Ԫ�ظ���Ϊ��" << L1.size() << endl;
	}
	L1.resize(10, 1000);
	printList(L1);

	L1.resize(2);
	printList(L1);

}
void test02()
{
	list<int>L1;
	//β��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	//ͷ��
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);
	printList(L1);

	//βɾ
	L1.pop_back();
	printList(L1);

	//ͷɾ
	L1.pop_front();
	printList(L1);

	//insert����
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList(L1);

	//ɾ��
	it = L1.begin();
	L1.erase(it);
	printList(L1);

	//�Ƴ�
	L1.push_back(10000);
	printList(L1);
	//�Ƴ���ɾ�����������к�elementƥ���Ԫ��
	L1.remove(10000);
	printList(L1);

	//���
	L1.clear();
	printList(L1);
}
int main()
{
	/*test01();*/
	test02();
	return 0;

}