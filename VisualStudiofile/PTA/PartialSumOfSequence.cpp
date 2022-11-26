#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
//int main()
//{
//	int N = 0;
//	double num = 0.0;
//	vector<double>Num;
//	cin >> N;
//	int count = N;
//	while (count > 0)
//	{
//		cin >> num;
//		Num.push_back(num);
//		count--;
//	}
//	vector<double>sum;
//	double total = 0.0;
//	for (int i = 0; i < N; i++)
//	{
//		int k = N;
//		while (k >= 0)
//		{
//			double Sum = 0.0;
//			for (int j = i; j < k; j++)
//			{
//				Sum += Num[j];
//			}
//			sum.push_back(Sum);
//			k--;
//		}
//	}
//	for (int i = 0; i < sum.size(); i++)
//	{
//		total += sum[i];
//	}
//	cout << fixed << setprecision(2) << total;
//	return 0;
//}
int main()
{
	int N = 0;
	double sum = 0.0;
	double temp = 0.0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		sum = sum + temp * i * (N - i + 1);
	}
	printf("%.2f", sum);
	return 0;
}