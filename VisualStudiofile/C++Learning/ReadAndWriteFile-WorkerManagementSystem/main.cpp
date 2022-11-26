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
        cout << "请输入您的选择" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0://退出系统
            w1.exitSystem();
            break;
        case 1://添加职工
            w1.Add_Emp();
            break;
        case 2://显示职工
            w1.Show_Emp();
            break;
        case 3://删除职工
            w1.Del_Emp();
            break;
        case 4://修改职工
            w1.Mod_Emp();
            break;
        case 5://查找职工
            w1.Find_Emp();
            break;
        case 6://排序职工
            w1.Sort_Emp();
            break;
        case 7://清空文件
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