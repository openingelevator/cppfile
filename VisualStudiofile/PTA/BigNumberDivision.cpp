#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int num = 40;
int sub(int *a,int *b,int len1,int len2)
{
	if (len1 < len2)return -1;
	if(len1==len2)
    {
		for (int i =len1-1;i>=0; i--)
			if (a[i] >b[i])break;
			else if (a[i] < b[i])return -1;
	}
	for (int i = 0; i < len1; i++)
	{
		a[i] -=b[i];
		if (a[i] < 0) 
			a[i] += 10,
			a[i+1]--;
	}
	for (int i = len1 - 1; i >= 0; i--)
		if (a[i])return i + 1;
	return 0;
}
string divisor(const string& s1, const string& s2)
{
	string divisor;
	int a[num], b[num], result[num];
	unsigned int len1 = s1.length(), len2 = s2.length(),len3=num;
	fill(a, a + num, 0); fill(b, b + num, 0); fill(result, result + num, 0);
	for (int i = len1 - 1; i >= 0; i--)a[len1-1-i] = s1[i] - '0';
	for (int i = len2 - 1; i >= 0; i--)b[len2-1-i] = s2[i] - '0';
	if (len1 < len2||(len1==len2&&s1<s2))
	{
		string s = "0";
		return s;
	}
	unsigned int t = len1 - len2;
	for(int i=len1-1;i>=0;i--)
	{
		if (i >= t) {
			b[i] = b[i - t]; }
		else b[i] = 0;
	}
	len2 = len1;
	for (unsigned int j = 0; j <= t; j++)
	{
		int temp;
		while ((temp = sub(a, b + j, len1, len2 - j ))>= 0)
		{
			len1 = temp;
			result[t - j]++;
		}
	}
	for (int i = 0; i < num-1; i++)
	{
		result[i + 1]+= result[i] / 10, result[i] %= 10;
		
	}
	while (result[len3-1] == 0) {
		len3--;
	}
	for (int i = len3-1; i>=0; i--)
	{
		divisor += result[i] + '0';
	}
	return divisor;
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	cout << "ÉÌÎª£º" << divisor(s1, s2)<<endl;
	return 0;
}