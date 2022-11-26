#include<iostream>
#include<deque>
using namespace std;
void printDeque(const deque<int>&d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//deque������С����
void test01()
{
	deque<int>d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty()) { cout << "d1Ϊ��" << endl; }
	else {
		cout << "d1��Ϊ��" << endl;
		//deque����ֻ�д�С��û������
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	}
	//����ָ����С
	d1.resize(15,1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}
//deque������ɾ��
void test02()
{
	deque<int>d1;
	//β��
	d1.push_back(20);
	d1.push_back(10);
	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//βɾ
	d1.pop_back();
	printDeque(d1);

	//ͷɾ
	d1.pop_front();
	printDeque(d1);
}
//ָ��λ��Ԫ�صĲ�����ɾ��
void test03()
{
	deque<int>d1;
	d1.push_back(20);
	d1.push_back(10);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	d1.insert(d1.begin(), 1000);
	printDeque(d1);

	d1.insert(d1.begin(),2, 10000);
	printDeque(d1);

	//����������в���
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d1.insert(d1.begin(),d2.begin(),d2.end());
	printDeque(d1);

}
void test04()
{
	deque<int>d1;
	d1.push_back(20);
	d1.push_back(10);
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);
	//ɾ��
	deque<int>::iterator it = d1.begin();
	it++;
	d1.erase(it);
	printDeque(d1);

	//�����䷽ʽɾ��
	d1.erase(d1.begin(), d1.end());
	printDeque(d1);
}
int main()
{
	//test01();
	/*test02();*/
	test03();
	test04();
	return 0;
}