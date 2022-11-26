#include<iostream>
#include<string>
#include<vector>
#include"Package.h"
using namespace std;
int main()
{
	double sumOfPackageFee=0.0;
	vector<Package*>package(4);
	 package[0] = new OvernightPackage("Mike", "Tom", "California", "Huston", "93397", 10, 2.5, 1);
	 package[1] = new TwoDayPackage("May", "Peter", "New York", "Washington", "78533", 10, 2.4, 5);
	 package[2] = new OvernightPackage("Tom", "Mike", "Huston", "California", "93397", 10, 2.5, 1);
	 package[3] = new TwoDayPackage("Peter", "May", "Washington", "New York", "78533", 10, 2.4, 5);
	 for (int i = 0; i < 4; i++)
	 {
		 cout << "��" << i+1 << "����������" << typeid(*package[i]).name();
		 cout << "\n�ļ��˵�ַΪ:\n";
		 cout<<package[i]->getSenderAddress();
		 cout << "\n�ռ��˵�ַΪ:\n";
		 cout<<package[i]->getReceiverAddress();
		 cout << "\n�ð������ʼķ�Ϊ\n";
		 cout << package[i]->calculateCost() << endl;
		 cout << endl;
		 sumOfPackageFee += package[i]->calculateCost();
	 }
	 cout << "�������ܷ���Ϊ��\n";
	 cout << sumOfPackageFee;
	 for (int i = 0; i < 4; i++)
	 {
		 if (package[i] != NULL)
			 delete package[i];
	 }
	return 0;
}