#include<iostream>
using namespace std;
#include"myArray.hpp"
void printintArray(myArray<int>&arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}
void test01()
{
	myArray<int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		arr1.Push_Back(i);
	}
	cout << "arr1�Ĵ�ӡ�����" << endl;
	printintArray(arr1);
	cout << "arr������Ϊ��" << arr1.getCapacity() << endl;
	cout << "arr�Ĵ�СΪ" << arr1.getSize() << endl;
	myArray<int>arr2(arr1);
	cout << "arr2�Ĵ�ӡ���Ϊ��" << endl;
	printintArray(arr2);
	//βɾ
	arr2.Pop_Back();
	cout << "arr2βɾ��" << endl;
	cout << "arr2������Ϊ��" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ��" << arr2.getSize() << endl;
	printintArray(arr2);
}
int main()
{
	test01();
	return 0;
}