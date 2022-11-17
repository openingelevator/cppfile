#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//An initializer list forces so-called value initialization, which means that even local variables of fundamental data type,
//which usually have an undefined initial value, are initialized by zero.

void print(std::initializer_list<int>vals)
{
	for (auto it = vals.begin(); it != vals.end(); ++it)
	{
		std::cout << *it << "\n";
	}
}

class P
{
public:
	//When there are constructors for both a specific numbers of arguments and an initializer list
	//the version with initilizer list is preferred
	P(int a, int b)//complex<T>就是这种情况
	{
		cout << "P(int a,int b), a=" << a << " b=" << b << endl;
	}
	P(initializer_list<int>initlist)
	{
		cout << "P(initializer_list<int>initlist), values=" << endl;
		for (auto i : initlist)
		{
			cout << i << " ";
		}
		cout << endl;
	}
};

void test01()
{
	P p( 5,7 );
	P q{ 5,7 };
	P r{ 5,7,9 };
	P s = { 5,7 };
    //without the constructor for the initializer list
	//the constructor taking two ints would be called  to initialize q and s.
}

void test02()
{
	vector<int>v1{ 1,2,3 };//uniform initialization
	vector<int>v2({ 1,2,3 });//the version of constructor that uses initializer_list
	vector<int>v3;
	v3 = { 1,2,3,5,9 };//the overloading of operator= that uses initializer_list	 
	v3.insert(v3.begin() + 2, { 22,14,53 });

	for (auto i: v3)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << max({ 3,5,1,6,9 })<<endl;
	cout << min({ 3,5,1,6,9 });
}

int main()
{
	int i;//i has undefined value
	int j{};//j is initialized by zero
	int* p;//p has undefined value
	int* q{};//q is initialized by nullptr

	//However, the narrowing initialization, 
	//those that reduce the precision or where the supplied value gets modified, are not possible with braces 
	//int x{ 4.5 };is not allowed

	//print({ 3,4,2,1 });

	//void (*ptr)() = &test01;
	//(* ptr)();

	//The initializer_list object refers to the elements of this array without containing them
	//copying an initializer_list object produces another object referring to the same underlying elements, not to new copies of them

	test02();
	system("pause");
	return 0;
}