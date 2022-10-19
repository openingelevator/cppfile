/*
 * @Author: 郑岱锋 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by:   郑岱锋 
 * @SID:202130462264
 * @Last Modified time: 2022-09-24 12:14:29 
 */
#pragma once
#include<iostream>
#include<string>
using namespace std;
class VehicleInfo
{
public:
    VehicleInfo(string mfDate,string mod,string col,string pnum,string br):next(nullptr)
    {
        this->manufactureDate=mfDate;
        this->model=mod;
        this->color=col;
        this->plateNum=pnum;
        this->brand=br;
    }
    //汽车的基本数据
    string manufactureDate;
    string model;
    string color;
    string plateNum;
    string brand;
    //指向下一个节点的指针
    VehicleInfo*next;
};
class LinkedListOfVehicle
{
private:
    VehicleInfo*head=new VehicleInfo("0","","","","");
    int numOfNode=0;
public:
    //按出场日期添加汽车信息
    void addVehicle(VehicleInfo*node);
    //删除车辆信息，以汽车车牌号作为唯一标识
    bool deleteInfo(string plateNumber);
    //退出系统
    void exitSystem();
    //查找并显示汽车信息，以汽车车牌号作为唯一标识，返回位置信息
    int findInfo(string plateNumber,bool tag);
    //返回头结点
    VehicleInfo* getHead()const;
    //返回节点数目
    int getNum()const;
    //用于修改汽车数据
    bool modInfo(string plateNumber);
    //用于打印车辆单行信息
    void printInfo(VehicleInfo*temp);
    //显示全部的汽车信息
    void showList();
    //显示菜单
    void showMenu();
};