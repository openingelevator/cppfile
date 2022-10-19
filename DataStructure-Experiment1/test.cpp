/*
 * @Author: ֣᷷� 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by: ֣᷷�
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
		cout << "�ļ�������" << endl;
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
        cout << "����������ѡ��" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0://�˳�ϵͳ
           List.exitSystem();
            break;
        case 1://��ӳ�����Ϣ
            {cout<<"��������Ҫ��ӵĳ�����Ϣ"<<endl;
            cout<<"����������������Ϣ"<<endl;
            cin>>mDate;
            cout<<"�����������ͺ�"<<endl;
            cin>>mod;
            cout<<"������������ɫ"<<endl;
            cin>>col;
            cout<<"�����������ĳ��ƺ�"<<endl;
            cin>>pNum;
            cout<<"������������Ʒ��"<<endl;
            cin>>br;
            VehicleInfo*temp=new VehicleInfo(mDate,mod,col,pNum,br);
            List.addVehicle(temp);
            save(List);
            break;}
        case 2://��ʾ����
           {List.showList();
            break;}
        case 3://ɾ������
           {cout<<"��������Ҫɾ�������ĳ��ƺ�"<<endl;
            cin>>info;
            List.deleteInfo(info);
             save(List);
            break;}
        case 4://�޸ĳ���
            {cout<<"��������Ҫ�޸ĳ����ĳ��ƺ�"<<endl;
            cin>>info;
            List.modInfo(info);
             save(List);
            break;}
        case 5://���ҳ���
            {cout<<"��������Ҫ���ҳ����ĳ��ƺ�"<<endl;
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