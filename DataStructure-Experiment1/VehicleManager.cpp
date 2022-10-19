/*
 * @Author: 郑岱锋 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by: 郑岱锋
 * @SID:202130462264
 * @Last Modified time: 2022-09-24 12:15:41
 */

#include"VehicleManager.h"
#include<iostream>
#include<iomanip>
using namespace std;

void LinkedListOfVehicle::addVehicle(VehicleInfo*node)
{
    //建立临时指针，遍历到链表的最后一个结点
    VehicleInfo* temp=head;
    bool flag=false;
    while(true)
    {
        if(temp->next==nullptr)
        {
            break;
        }
        else if(temp->next->manufactureDate.compare(node->manufactureDate)==1)
        {
            break;
        }
        else if(temp->next->manufactureDate==node->manufactureDate)
        {
            flag=true;
            cout<<"出厂日期已存在"<<endl;
            break;
        }
        temp=temp->next;
    }
    if(flag)
    {
        cout<<"准备插入的车辆信息已存在，无法继续添加"<<endl;
        return ;
    }else
    {
        //插入到链表中
        node->next=temp->next;
        temp->next=node;
        this->numOfNode++;
    }
}
bool LinkedListOfVehicle::deleteInfo(string plateNumber)
{
    //如果未查找到车辆信息则无法删除结点
    int pos=findInfo(plateNumber,0);
    if(pos==-1)
    {
        return false;
    }
    VehicleInfo*temp=head;
    //找到待删除结点的前一个结点
    while(pos>0)
    {
        temp=temp->next;
        pos--;
    }
    VehicleInfo*node=temp->next;
    temp->next=node->next;
    this->numOfNode--;
    delete node;
    cout<<"删除操作成功"<<endl;
    return true;
}
void LinkedListOfVehicle::exitSystem()
{
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);
}
int LinkedListOfVehicle::findInfo(string plateNumber,bool tag)
{
    //判断链表是否为空
    if(head->next==nullptr)
    {
        cout<<"车辆管理信息为空"<<endl;
        return -1;
    }
    int pos=0;
    VehicleInfo*temp=head;
    bool flag=false;
    while(true)
    {
        if(temp->next==nullptr)
        {
            break;
        }
        if(temp->next->plateNum==plateNumber)
        {
            flag=true;
            break;
        }
        temp=temp->next;
        pos++;
    }
    if(flag)
    {
        if(tag)
        {
        cout<<"所要查找的车辆信息如下"<<endl;
        printInfo(temp->next);
        cout<<pos;
        }
        return pos;
    }
    else
    {
        cout<<"车辆信息未找到，请确认车牌号是否输入正确"<<endl;
        return -1;
    }

}
VehicleInfo*LinkedListOfVehicle::getHead()const
{
    return this->head;
}
int LinkedListOfVehicle::getNum()const
{
    return this->numOfNode;
}
bool LinkedListOfVehicle::modInfo(string plateNumber)
{
    //如果未查找到车辆信息则无法修改结点
    int pos=findInfo(plateNumber,0);
    if(pos==-1)
    {
        return false;
    }
    VehicleInfo*temp=head;
    //找到待修改结点
    while(pos>=0)
    {
        temp=temp->next;
        pos--;
    }
    //查找成功，提示用户输入信息
    cout<<"请输入要修改的汽车信息"<<endl;
    cout<<"1.汽车车牌号"<<endl;
    cout<<"2.汽车颜色"<<endl;
    int choice;
    string Info;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"请输入汽车新的车牌号"<<endl;
        cin>>Info;
        temp->plateNum=Info;
        break;
    case 2:
        cout<<"请输入汽车新的颜色"<<endl;
        cin>>Info;
        temp->color=Info;
        break;
    default:
        break;
    }
    cout<<"修改操作成功"<<endl;
    return true;
}
void LinkedListOfVehicle::printInfo(VehicleInfo*temp)
{
    cout<<"汽车的出厂日期"<<setw(10)<<temp->manufactureDate<<" 型号为 "<<setw(10)<<temp->model
    <<" 颜色 "<<setw(8)<<temp->color<<" 车牌号 "<<setw(12)<<temp->plateNum
    <<" 品牌 "<<setw(12)<<temp->brand<<endl;
}
void LinkedListOfVehicle::showList()
{
    //判断链表是否为空
    if (head->next == nullptr)
    {
        cout << "链表为空" << endl;
        return;
    }
    //遍历，通过辅助变量遍历链表
    VehicleInfo* temp = head->next;
    while (true)
    {
        //判断是否到链表最后
        if (temp == nullptr)
        {
            break;
        }
        //输出节点信息
        printInfo(temp);
        temp = temp->next;
    }
}
void LinkedListOfVehicle::showMenu()
{
    cout << "****************************" << endl;
	cout << "****欢迎使用车辆管理系统****" << endl;
	cout << "***** 0、退出管理系统  *****" << endl;
	cout << "***** 1、增加车辆信息  *****" << endl;
	cout << "***** 2、显示车辆信息  *****" << endl;
	cout << "***** 3、删除车辆信息  *****" << endl;
	cout << "***** 4、修改车辆信息  *****" << endl;
	cout << "***** 5、查找车辆信息  *****" << endl;
	cout << "****************************" << endl;
	cout << endl;
}
