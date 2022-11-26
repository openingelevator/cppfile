#include<iostream>
using namespace std;
const int N = 3;
int max(int a[N])
{
	int index = 0;
	int imax = -1;
	for (int i = 0; i < N ; i++)
	{
		if (a[i] >imax )
		{
			imax = a[i];
			index = i;
		}
		
	}
	return index;

}
int main()
{
	
	char s = { '0' }, t = { '0' };
	int jiawin = 0, yiwin = 0;
	int n = 0;
	int jia[N] = { 0 }, yi[N] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		if (s == 'B' && t == 'C')
		{
			jiawin++;
			jia[0]++;
		}
		else if (s == 'B' && t == 'J')
		{
			yiwin++;
			yi[2]++;
		}
		else if (s == 'C' && t == 'B')
		{
			yiwin++;
			yi[0]++;
		}
		else if (s == 'C' && t == 'J')
		{
			jiawin++;
			jia[1]++;
		}
		else if (s == 'J' && t == 'B')
		{
			jiawin++;
			jia[2]++;
		}
		else if(s=='J'&&t=='C')
		{
			yiwin++;
			yi[1]++;
		}
	}
	cout << jiawin << " " << n - jiawin - yiwin << " " << yiwin << endl;
	cout << yiwin << " " << n - jiawin - yiwin << " " << jiawin << endl;
	int jmax = max(jia);
	int ymax = max(yi);
	char str[4] = { "BCJ" };
	cout << str[jmax] << " " << str[ymax] << endl;
	return 0;
}