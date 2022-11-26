//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int N = 0, index = 0;
//	char C={'0'};
//	cin >> N >> C;
//	int MIN = 2*N;
//	int n = sqrt((N + 1) / 2)+1;
//	for (int i = 0; i <= n; i++)
//	{
//		if (abs(N - 2 * pow(i, 2)) < MIN)
//		{
//			MIN = abs(N - (2 * pow(i, 2)-1));
//			if (N - (2 * pow(i, 2) - 1) >= 0)
//			{
//				MIN = N - (2 * pow(i, 2) - 1);
//				index = i;
//
//			}
//			else if (N - (2 * pow(i, 2) - 1) < 0)
//			{
//				MIN = abs(N - (2 * pow(i-1, 2) - 1));
//				index = i - 1;
//			}
//
//		}
//	}
//	for (int row = 0; row < 2 * index - 1; row++)
//	{
//		if (row < index - 1)
//		{
//			for (int column = 0;column < 2 * index - 1; column++)
//			{
//				if (column < row||column>2 * index - 1 - row - 1)
//					cout << " ";
//				else
//					cout << C;
//			}
//		}
//		else if (row == index - 1)
//		{
//			for (int column = 0; column < 2 * index - 1; column++)
//			{
//				if (column == index-1)
//					cout << C;
//				else
//					cout << " ";
//			}
//		}
//		else
//		{
//			for (int column = 0; column < 2 * index - 1; column++)
//			{
//				if (column < 2 * index - 1-row-1||column>row)
//					cout << " ";
//				else
//					cout << C;
//			}
//		}
//		cout << endl;
//	}
//	cout << MIN;
//	return 0;
//}
#include <iostream>
using namespace std;
int main() {
	int N, row = 0;
	char c;
	cin >> N >> c;
			for (int i = 0; i < N; i++) {
				if ((2 * i * (i + 2) + 1) > N) {
					row = i - 1;
					break;
				}
			}
	for (int i = row; i >= 1; i--) {
		for (int k = row - i; k >= 1; k--) cout << " ";
		for (int j = i * 2 + 1; j >= 1; j--) cout << c;
		cout << endl;
	}
	for (int i = 0; i < row; i++) cout << " ";
	cout << c << endl;
	for (int i = 1; i <= row; i++) {
		for (int k = row - i; k >= 1; k--) cout << " ";
		for (int j = i * 2 + 1; j >= 1; j--) cout << c;
		cout << endl;
	}
	cout << (N - (2 * row * (row + 2) + 1));
	return 0;
}