#include<iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;
	//�Զ������Ƶ�
	mySwap(a, b);
	//��ʾָ������
	double c = 1.1;
	double d = 2.2;
	mySwap<double>(c, d);
	return 0;

}