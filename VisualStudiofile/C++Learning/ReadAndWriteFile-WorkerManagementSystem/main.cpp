#include<iostream>
#include"workerManager.h"
#include"worker.h"
#include"employee.h"
using namespace std;
int main()
{
    WorkerManager w1;
    int choice = 0;
    while (true)
    {
        w1.Show_Menu();
        cout << "����������ѡ��" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0://�˳�ϵͳ
            w1.exitSystem();
            break;
        case 1://���ְ��
            w1.Add_Emp();
            break;
        case 2://��ʾְ��
            w1.Show_Emp();
            break;
        case 3://ɾ��ְ��
            w1.Del_Emp();
            break;
        case 4://�޸�ְ��
            w1.Mod_Emp();
            break;
        case 5://����ְ��
            w1.Find_Emp();
            break;
        case 6://����ְ��
            w1.Sort_Emp();
            break;
        case 7://����ļ�
            w1.Clean_File();
            break;
        default:
            system("cls");
            break;

        }
    }
    system("pause");
    return 0;
}