//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	string s1, s2;
//	vector<char>v1;
//	cin >> s1 >> s2;
//	int a[80] = { 0 },b[80]={0};
//	for (int i = 0; i < s2.size(); i++)
//	{
//		for (int j = 0; j < s1.size(); j++)
//		{
//			if (s1[j] == s2[i])
//			{
//				a[j] = 1;
//			}
//		}
//	}
//	for (int k = 0; k < s1.size(); k++)
//	{
//		if (a[k] ==0 )
//		{
//			if (s1[k]>='a'&&s1[k]<='z')
//			{
//				s1[k] -= 32;
//				v1.push_back(s1[k]);
//			}
//			else
//			{
//				v1.push_back(s1[k]);
//			}
//		}
//	}
//	for (int i = 0; i < v1.size(); i++)
//	{
//		for (int j = i+1; j < v1.size(); j++)
//		{
//			if (v1[j] == v1[i])
//			{
//				b[j] = 1;
//			}
//		}
//	}
//	for (int k = 0; k < v1.size(); k++)
//	{
//		if (b[k] == 0)
//		{
//			cout << v1[k];
//		}
//	}
//
//	return 0;
//}
#include <iostream>
#include <cctype>
using namespace std;
int main() {
	string s1, s2, ans;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++)
		if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) ==
			string::npos)
			ans += toupper(s1[i]);
	cout << ans;
	return 0;
}