#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
	Stack<int>s(5);
	int value = 1;
	while (s.push(value))
	{
		cout << value << " ";
		value++;
	}
	return 0;
}