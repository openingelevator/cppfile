#include<iostream>
using namespace std;
template<class T>
void printArray(const T* const array, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
template<class T>
int printArray(const T* const array, int count, int lowSubscript, int highSubscript)
{
	if (lowSubscript >= highSubscript || lowSubscript >= count ||
		highSubscript >= count|| lowSubscript<0|| highSubscript<0)
		return 0;
	else
	{
		for (int i = lowSubscript; i <= highSubscript; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;

	}
	return (highSubscript - lowSubscript +1);
}
int main()
{
	const int aCount = 5;
	const int bCount = 7;
	const int cCount = 6;

	int a[aCount] = { 1,2,3,4,5 };
	double b[bCount] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7 };
	char c[cCount] = "hello";
	//test the original version of function printArray
	cout << "Array a contains" << endl;
	printArray(a, aCount);
	cout << "Array b contains" << endl;
	printArray(b, bCount);
	cout << "Array b contains" << endl;
	printArray(c, cCount);

	//test the overloading version of function printArray
	cout << "Array a contains" << endl;
	cout<<"the number of element being printed are"<<printArray(a, aCount, 3, 4);
	cout << "\nArray b contains" << endl;
	cout << "the number of element being printed are" << printArray(b, bCount,4,6);
	cout << "\nArray b contains" << endl;
	cout << "the number of element being printed are" << printArray(c, cCount, 1, 5) << endl;

	//test the unexpecting cases
	int flag1=printArray(a, aCount, -3, 4);
	if (!flag1)cout << "lowSubscript or highSubscript is out of range or lowSubcript is bigger than hignSubscript" << endl;
	int flag2 = printArray(a, aCount, 7, 4);
	if (!flag2)cout << "lowSubscript or highSubscript is out of range or lowSubcript is bigger than hignSubscript" << endl;

	return 0;
}