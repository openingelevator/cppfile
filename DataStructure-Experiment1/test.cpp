/*
 * @Author: 郑岱锋 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by: 郑岱锋
 * @SID:202130462264
 * @Last Modified time: 2022-09-24 12:15:45
 */
#include"VehicleManager.h"
#include"VehicleManager.cpp"
#include<iostream>
#include<string>
#include<fstream>
#define FILENAME "DataStructure-Experiment1/DataOfVehicle.txt"
using namespace std;
void initialize(LinkedListOfVehicle&list)
{
    ifstream ifs;
	ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
        ifs.close();
        return ;
    }
    string mDate;
    string mod;
    string col;
    string pNum;
    string br;
    while(ifs>>mDate&&ifs>>mod&&ifs>>col&&ifs>>pNum&&ifs>>br)
    {
        VehicleInfo*temp=new VehicleInfo(mDate,mod,col,pNum,br);
        list.addVehicle(temp);
    }
    ifs.close();
}
void save(LinkedListOfVehicle&list)
{
    ofstream ofs;
	ofs.open(FILENAME, ios::out);
    VehicleInfo*temp=list.getHead()->next;
	for (int i = 0; i < list.getNum(); i++)
	{
		ofs<<temp->manufactureDate<<" "<<
        temp->model<<" "<<temp->color<<" "<<temp->plateNum<<" "<<temp->brand<<endl;
        temp=temp->next;
	}
	ofs.close();
}
int main()
{
    LinkedListOfVehicle List;
    initialize(List);
    int choice = 0;
    string mDate;
    string mod;
    string col;
    string pNum;
    string br;
    string info;
    while (true)
    {
        List.showMenu();
        cout << "请输入您的选择" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0://退出系统
           List.exitSystem();
            break;
        case 1://添加车辆信息
            {cout<<"请输入您要添加的车辆信息"<<endl;
            cout<<"请输入汽车出厂信息"<<endl;
            cin>>mDate;
            cout<<"请输入汽车型号"<<endl;
            cin>>mod;
            cout<<"请输入汽车颜色"<<endl;
            cin>>col;
            cout<<"请输入汽车的车牌号"<<endl;
            cin>>pNum;
            cout<<"请输入汽车的品牌"<<endl;
            cin>>br;
            VehicleInfo*temp=new VehicleInfo(mDate,mod,col,pNum,br);
            List.addVehicle(temp);
            save(List);
            break;}
        case 2://显示车辆
           {List.showList();
            break;}
        case 3://删除车辆
           {cout<<"请输入您要删除车辆的车牌号"<<endl;
            cin>>info;
            List.deleteInfo(info);
             save(List);
            break;}
        case 4://修改车辆
            {cout<<"请输入您要修改车辆的车牌号"<<endl;
            cin>>info;
            List.modInfo(info);
             save(List);
            break;}
        case 5://查找车辆
            {cout<<"请输入您要查找车辆的车牌号"<<endl;
            cin>>info;
            List.findInfo(info,1);
            break;}
        default:
            system("cls");
            break;
        }
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}