#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int a, int b) { return a > b; }

int main()
{
	vector<int>v1;
	int num = 0;
	int N = 0,n,m,t=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v1.push_back(num);
	}
	int len = v1.size();
	sort(v1.begin(), v1.end(), cmp);
	for (n = (double)sqrt(N); n >= 0; n--)
	{
		if (N % n == 0) { m = N / n; break; }
	}
	vector<vector<int>>v2(m, vector<int>(n));
	int level = m / 2 + m % 2;
	for (int i = 0; i < level; i++)
	{
		for (int j = i; j < n - i && t <= N - 1; j++)
			v2[i][j] = v1[t++];
		for (int j = i+1; j < m - i - 1 && t <= N - 1; j++)
			v2[j][n-1-i] = v1[t++];
		for (int j = n - i - 1; j >= i && t <= N - 1; j--)
			v2[m-i-1][j] = v1[t++];
		for (int j = m - i - 2; j >= i+1 && t <= N - 1; j--)
			v2[j][i] = v1[t++];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d", v2[i][j]);
			if (j != n - 1)printf(" ");
		}
		printf("\n");
	}
	return 0;
}