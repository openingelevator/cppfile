#include<algorithm>
#include<iostream>
#include<vector>
#include<functional>
#include<ctime>
using namespace std;
//���������㷨sort
void myPrint(int val)
{
	cout << val << endl;
}
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);
	//sort��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	//sort���н���
	sort(v.begin(), v.end(),greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}
//ϴ���㷨��random_shuffle
void test02()
{
	vector<int>v;
	for(int i=0;i<10;i++)
	v.push_back(i);
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}
//�ϲ��㷨��merge
void test03()
{
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	//Ŀ������
	vector<int>vTarget;
	vTarget.resize(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	for_each(vTarget.begin(), vTarget.end(), myPrint);
	cout << endl;

}
//��ת����Ԫ��reverse
void test04()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	cout << "��תǰ" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
	reverse(v.begin(), v.end());
	cout << "��ת��" << endl;
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;


}
int main()
{
	//test01();
	//srand(static_cast<unsigned int>(time(0)));
	//test02();
	//test03();
	test04();
	return 0;
}
