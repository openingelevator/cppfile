//#include<iostream>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	long int N=0, p=0, M=0;
//	cin >> N >> p;
//	long int a[100000] = { 0 };
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a[i];
//	}
//	sort(a, a + N);
//	long int counter = N;
//	long int i = 0, j = N-1;
//	while (i != j)
//	{
//		if ((a[i] * p) >= a[j])
//		{
//			break;
//		}
//		else
//		{
//			N--;
//			if ((a[i + 1] / 1.0 / a[i]) > (a[j] / 1.0 / a[j - 1]))
//			{
//				i++;
//			}
//			else
//			{
//				j--;
//			}
//		}
//	}
//	cout << N << endl;
//
//	return 0;
//	
//}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	long long p;
	cin >>n >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int result = 0, temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + result; j < n; j++) {
			if (v[j] <= v[i] * p) {
				temp = j - i + 1;
				if (temp > result)
					result = temp;
			}
			else {
				break;
			}
		}
	}
	cout << result;
	return 0;
}