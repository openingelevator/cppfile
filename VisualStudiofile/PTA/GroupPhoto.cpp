#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct Student
{
	string name;
	int height;
};
int cmp(struct Student s1,struct Student s2)
{
	return s1.height != s2.height ? s1.height > s2.height:s1.name < s2.name;
}
int main()
{
	int N = 0, k = 0;
	cin >> N >> k;
	vector<Student>v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].name;
		cin >> v[i].height;
	}
	sort(v.begin(), v.end(), cmp);
	int m = 0, t = 0,row=k;
	while (row)
	{
		if (row == k)
		{
			m = N - N / k * (k - 1);
		}
		else {
			m = N / k;
		}
		vector<string>ans(m);
		ans[m / 2] = v[t].name;
		//左边一列
		int j = m / 2 - 1;
		for (int i = t + 1; i < t + m; i=i+2)
		{
			ans[j--] = v[i].name;
		}
		//右边一列
		j = m / 2 + 1;
		for (int i = t + 2; i < t + m; i = i + 2)
		{
			ans[j++] = v[i].name;
		}
		cout << ans[0];
		for (int i = 1; i < m; i++)
		{
			cout << " " << ans[i];
		}
		cout << endl;
		row--;
		t =t+ m;
	}
	return 0;

}