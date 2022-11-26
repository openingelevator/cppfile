#include<iostream>
#include"Time.h"
int main()
{
	Time t;
	t.printStandard();
	t.printUniversal();
	t.setTime(3, 27, 6);
	t.printStandard();
	t.printUniversal();
	return 0;
}