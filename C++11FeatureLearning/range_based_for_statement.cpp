#include<iostream>
#include<vector>
using namespace std;

void test01()
{
	for (int i : {1, 2, 3, 4, 5, 6})
	{
		cout << i << " ";
	}
	cout << endl;

	vector<double>vec{ 1.2,2.3,4.8 };
	for (auto elem : vec)
	{
		cout << elem << " ";
	}
	cout << endl;

	for (auto& elem : vec)
	{
		elem *= 3;//Notice: the element of associative container cannot be changed
	}

}

//for (decl : coll)
//{
//	statement
//}
//for (auto _pos = coll.begin(), _end = coll.end(); _pos != _end; _pos++)
//{
//	decl = *_pos;
//	statement;
//}

//version one
template<typename T>
void printElement01(const T&coll)
{
	for (const auto& elem : coll)
	{
		cout << elem << " ";
	}
	cout << endl;
}

//version two
template<typename T>
void printElement02(const T& coll)
{
	for (auto pos = coll.begin(); pos != coll.end(); ++pos)
	{
		const auto elem = *pos;
		cout << elem << " ";
	}
	cout << endl;
}


void test02()
{
	vector<int>v{ 1,2,3,4,5 };
	printElement01(v);
	printElement02(v);
}

int main()
{
	/*test01();*/
	test02();
	system("pause");
	return 0;
}