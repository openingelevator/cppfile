#include<iostream>
#include<ctime>
#include"speechManager.h"
using namespace std;
int main()
{
	srand(static_cast<unsigned int>(time(0)));
	SpeechManager sm;
	//测试12名选手的创建
	//sm.printTest();

	int choice;
	while (true)
	{
		sm.showMenu();
		cout << "请输入您的选择" << endl;
		//接受用户选项
		cin >> choice;

		switch(choice)
		{
		case 1:  //开始比赛
			sm.startSpeech();
			break;
		case 2:  //查看记录
			sm.showRecord();
			break;
		case 3:  //清空记录
			sm.clearRecord();
			break;
		case 0:  //退出程序
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