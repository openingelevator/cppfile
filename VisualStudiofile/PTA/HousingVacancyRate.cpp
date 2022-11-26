#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float e = 0.0,e1=0.0;
	int numOfHouse =0,Domain= 0;
	int days = 0;
	int NumOfEmpty = 0, NumOfPossible = 0;
	cin >> numOfHouse >> e >> Domain;
	for (int i = 0; i < numOfHouse; i++)
	{
		cin >> days;
		int count = 0;
		for (int j = 0; j < days; j++)
		{
			cin >> e1;
			if (e1 < e)count++;
		}
		if (count > days / 2 && days <= Domain)NumOfPossible++;
		if (count > days / 2 && days > Domain)NumOfEmpty++;
	
	}
	cout <<fixed<<setprecision(1) << NumOfPossible / 1.0 / numOfHouse*100 <<"% " << NumOfEmpty /1.0/ numOfHouse*100<<"%";
	
	return 0;
}