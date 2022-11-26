//#include<iostream>
//using namespace std;
//int main()
//{
//    int a, b, flag = 0;
//    while (cin >> a >> b)
//    {
//        if (b != 0)
//        {
//            if (flag == 1)cout << " ";
//            cout << a * b << " " << b - 1;
//            flag = 1;
//        }
//    }
//    if (flag == 0)
//        cout << "0 0";
//    return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T = 0;
	long int A = 0, B = 0, C = 0;
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cin >> T;
	vector<int>v;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B >> C;
		if (A + B > C)
			v.push_back(1);
		else
			v.push_back(0);
	}
	for (int i = 0; i < T; i++)
	{
		if (v[i] == 1)
			cout << "Case #" << a[i] << ": true" << endl;
		else if (v[i] == 0)
			cout << "Case #" << a[i] << ": false" << endl;
	}
	return 0;
}