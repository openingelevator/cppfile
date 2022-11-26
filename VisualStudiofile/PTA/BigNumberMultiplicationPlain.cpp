#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int L = 100;
string Mul(string s1, string s2)
{
	string s;
	int len1 = s1.size();
	int len2 = s2.size();
	int num1[L], num2[L], numM[L];
	fill(num1, num1 + L, 0), fill(num2, num2 + L, 0), fill(numM, numM + L, 0);
	for (int i = len1 - 1; i >= 0; i--)num1[len1 - i] = s1[i] - '0';
	for (int i = len2 - 1; i >= 0; i--)num2[len2 - i] = s2[i] - '0';
	for (int i = 1; i <=len1; i++)
	{
		for (int j = 1; j <=len2; j++)
		{
			numM[i + j - 1] += num1[i] * num2[j];
		}
	}
	for (int i = len1 + len2; i >= 0; i--)
	{
		numM[i + 1] += numM[i] / 10;
		numM[i] %= 10;
	}
	if (numM[len1 + len2])s += numM[len1 + len2] + '0';
	for(int i=len1+len2-1;i>=1;i--)s += numM[i] + '0';
	return s;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << Mul(s1, s2);
	return 0;
	
}