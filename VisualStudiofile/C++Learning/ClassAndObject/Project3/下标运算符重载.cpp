#include<iostream>
using namespace std;
const int SIZE = 10;
class safeArray
{
private:
	int arr[SIZE];
public:
	safeArray()
	{
		register int i;
		for (i = 0; i < SIZE; i++)
		{
			arr[i] = i;
		}
	}
	int& operator[](int n)
	{
		if (n > SIZE-1)
		{
			cout << "索引超过最大值" << endl;
			return arr[0];
		}
		else { return this->arr[n]; }
	}

};
int main()
{
	safeArray A;
	cout << "A[2]的值为" << A[2] << endl;
	cout << "A[12]的值为" << A[12] << endl;
	return 0;
}