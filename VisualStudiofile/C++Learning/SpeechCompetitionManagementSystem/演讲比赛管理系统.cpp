#include<iostream>
#include<ctime>
#include"speechManager.h"
using namespace std;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	SpeechManager sm;
	//����12��ѡ�ֵĴ���
	//sm.printTest();

	int choice;
	while (true)
	{
		sm.showMenu();
		cout << "����������ѡ��" << endl;
		//�����û�ѡ��
		cin >> choice;

		switch(choice)
		{
		case 1:  //��ʼ����
			sm.startSpeech();
			break;
		case 2:  //�鿴��¼
			sm.showRecord();
			break;
		case 3:  //��ռ�¼
			sm.clearRecord();
			break;
		case 0:  //�˳�����
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}