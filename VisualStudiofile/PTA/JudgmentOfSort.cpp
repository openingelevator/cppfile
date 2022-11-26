#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N = 0, a[100] = {0}, b[100]={0};
	int i, j;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N; i++)
	{
		cin >> b[i];
	}
	for (i = 0; (i<N-1&&b[i]<=b[i+1]); i++);
	for (j = i+1; (a[j] == b[j]&&j<N); j++);//最后退出循环时j的值为N
	if (j == N)
	{
		cout << "Insertion Sort" << endl;
		sort(a, a + i + 2);
	}
	else
	{
		cout << "Merge Sort" << endl;
		int k=1, flag = 1;
		while (flag)
		{
			flag = 0;
			for (i = 0; i < N; i++)
			{
				if (a[i] != b[i])
					flag = 1;
			}
			k = k * 2;
			for (i = 0; i < N / k; i++)
			{
				sort(a + i * k, a + (i + 1) * k);
			}
			sort(a+N/k*k,a+N);

		}
	}
	for (int i = 0; i < N; i++)
	{
		if (i != 0)cout << " ";
		cout << a[i];
	}
	return 0;
}