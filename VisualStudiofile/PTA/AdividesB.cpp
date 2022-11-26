#include<iostream>
#include<string>
using namespace std;
int main()
{
	string A;
	int B=0;
	cin >> A >> B;
	int len = A.length();
	int t = (A[0] - '0') / B;
	if ((len > 1 && t != 0) || len == 1)
		cout << t;
	int temp= (A[0] - '0') % B;
	for (int i = 1; i < len; i++)
	{
		t = (temp * 10 + (A[i] - '0')) / B;
		cout << t;
		temp= (temp * 10 + (A[i] - '0')) % B;
	}
	cout << " " << temp;
	return 0;
}