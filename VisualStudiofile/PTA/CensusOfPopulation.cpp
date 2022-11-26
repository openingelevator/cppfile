#include<iostream>
using namespace std;
int main()
{
	int n = 0, cnt = 0;
	cin >> n;
	string name, birthdate, maxBirthdate = "1814/09/06", minBirthdate = "2014/09/06", maxname, minname;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> birthdate;
		if (birthdate >= "1814/09/06" && birthdate <= "2014/09/06")
		{
			cnt++;
			if (birthdate >= maxBirthdate)
			{
				maxBirthdate = birthdate;
				maxname = name;
			}
			if (birthdate <= minBirthdate)
			{
				minBirthdate = birthdate;
				minname = name;
			}
		}
	}
	cout << cnt;
	if (cnt != 0)cout<<" " << minname << " " << maxname;
	return 0;
}
