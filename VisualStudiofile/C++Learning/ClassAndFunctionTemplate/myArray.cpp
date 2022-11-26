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
	cout << "arr1的打印输出：" << endl;
	printintArray(arr1);
	cout << "arr的容量为：" << arr1.getCapacity() << endl;
	cout << "arr的大小为" << arr1.getSize() << endl;
	myArray<int>arr2(arr1);
	cout << "arr2的打印输出为：" << endl;
	printintArray(arr2);
	//尾删
	arr2.Pop_Back();
	cout << "arr2尾删后：" << endl;
	cout << "arr2的容量为：" << arr2.getCapacity() << endl;
	cout << "arr2的大小为：" << arr2.getSize() << endl;
	printintArray(arr2);
}
int main()
{
	test01();
	return 0;
}