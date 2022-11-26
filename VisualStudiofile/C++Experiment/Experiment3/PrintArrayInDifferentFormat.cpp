#include<iostream>
using namespace std;
void printArray(const char* const ch[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << ch[i] << endl;
	}
}

int main()
{
	const int chsize = 3;
	const char* ch[chsize] = {"hun","faf","gae"};
	printArray(ch, chsize);
	return 0;
}