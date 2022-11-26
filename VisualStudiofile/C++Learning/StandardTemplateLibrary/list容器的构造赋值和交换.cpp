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

	//���䷽ʽ����
	list<int>L2(L1.begin(),L1.end());
	printList(L2);

	//��������
	list<int>L3(L1);
	printList(L3);

	list<int>L4(10, 100);
	printList(L4);

}
void test02()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);

	list<int>L2;
	L2 = L1;	
	printList(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);


	cout << "����ǰL1������Ϊ" << endl;
	printList(L1);
	cout << "����ǰL4������Ϊ" << endl;
	printList(L4);
	L1.swap(L4);
	cout << "������L1������Ϊ" << endl;
	printList(L1);
	cout << "������L4������Ϊ" << endl;
	printList(L4);
}

int main()
{
	/*test01();*/
	test02();
	return 0;
}