#include<iostream>
#include<string>
#include<time.h>
#include"Date.h"
using namespace std;
int main()
{
	Date d1(2, 13, 2000);
	Date d2("June", 13, 1992);
	Date d3(37, 2001);
	//��ȡϵͳʱ��
	struct tm t;
	time_t now ;
	time(&now);
	localtime_s(&t,&now);
	cout << "ϵͳʱ��Ϊ��" << endl;
	Date d4(t.tm_mon+1,t.tm_mday,t.tm_year + 1900);
	return 0;
}