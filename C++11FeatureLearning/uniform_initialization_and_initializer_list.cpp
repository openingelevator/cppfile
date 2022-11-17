#include<iostream>
#include<vector>
#include<string>
#include<ccomplex>
using namespace std;
//Initilization could happen with parentheses, braces ,and/or assignment operators
//C++11 introduced the concept of uniform initialization, which means that for any initilization. 
//you can use one common syntax.

//原理：编译器在看到{n1,n2,...}之后便作出一个initializer_list<T>它关联至一个array<T,n>容器
//调用函数时（如construtor），array内的元素会被编译器分解逐一传给函数
//但若函数参数是个initializer_list<T>，调用者却不能给予数个T参数然后以为它们会被自动转为一个initializer_list<T>传入
	
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