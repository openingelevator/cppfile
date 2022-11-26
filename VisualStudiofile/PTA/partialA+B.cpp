#include<iostream>
#include<iostream>
using namespace std;
int main()
{
	string A, B;
	int DA=0, DB=0,counterA=0,counterB=0;
	int sum1 = 0, sum2 = 0;
	cin >> A >> DA>> B >> DB;
	for (int i = 0; i < A.size(); i++)
	{
		if ((A[i]-'0') == DA)
			counterA++;
	}
	if (counterA != 0)
	{
		for (int i = 0; i < counterA; i++)
		{
			sum1 = 10 * sum1 + DA;
		}
	}
	else
	{
		sum1 = 0;
	}
	for (int i = 0; i < B.size(); i++)
	{
		if ((B[i]-'0') == DB)
			counterB++;
		
	}
	if (counterB != 0)
	{
		for (int i = 0; i < counterB; i++)
		{
			sum2 = 10 * sum2 + DB;
		}
	}
	else { sum2 = 0; }
    cout << sum1 + sum2 << endl;
    return 0;
}