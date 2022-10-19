/*
 * @Author: ֣᷷� 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by:   ֣᷷� 
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
    //�����Ļ�������
    string manufactureDate;
    string model;
    string color;
    string plateNum;
    string brand;
    //ָ����һ���ڵ��ָ��
    VehicleInfo*next;
};
class LinkedListOfVehicle
{
private:
    VehicleInfo*head=new VehicleInfo("0","","","","");
    int numOfNode=0;
public:
    //�������������������Ϣ
    void addVehicle(VehicleInfo*node);
    //ɾ��������Ϣ�����������ƺ���ΪΨһ��ʶ
    bool deleteInfo(string plateNumber);
    //�˳�ϵͳ
    void exitSystem();
    //���Ҳ���ʾ������Ϣ�����������ƺ���ΪΨһ��ʶ������λ����Ϣ
    int findInfo(string plateNumber,bool tag);
    //����ͷ���
    VehicleInfo* getHead()const;
    //���ؽڵ���Ŀ
    int getNum()const;
    //�����޸���������
    bool modInfo(string plateNumber);
    //���ڴ�ӡ����������Ϣ
    void printInfo(VehicleInfo*temp);
    //��ʾȫ����������Ϣ
    void showList();
    //��ʾ�˵�
    void showMenu();
};