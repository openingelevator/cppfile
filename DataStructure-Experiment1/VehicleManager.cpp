/*
 * @Author: ֣᷷� 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by: ֣᷷�
 * @SID:202130462264
 * @Last Modified time: 2022-09-24 12:15:41
 */

#include"VehicleManager.h"
#include<iostream>
#include<iomanip>
using namespace std;

void LinkedListOfVehicle::addVehicle(VehicleInfo*node)
{
    //������ʱָ�룬��������������һ�����
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
            cout<<"���������Ѵ���"<<endl;
            break;
        }
        temp=temp->next;
    }
    if(flag)
    {
        cout<<"׼������ĳ�����Ϣ�Ѵ��ڣ��޷��������"<<endl;
        return ;
    }else
    {
        //���뵽������
        node->next=temp->next;
        temp->next=node;
        this->numOfNode++;
    }
}
bool LinkedListOfVehicle::deleteInfo(string plateNumber)
{
    //���δ���ҵ�������Ϣ���޷�ɾ�����
    int pos=findInfo(plateNumber,0);
    if(pos==-1)
    {
        return false;
    }
    VehicleInfo*temp=head;
    //�ҵ���ɾ������ǰһ�����
    while(pos>0)
    {
        temp=temp->next;
        pos--;
    }
    VehicleInfo*node=temp->next;
    temp->next=node->next;
    this->numOfNode--;
    delete node;
    cout<<"ɾ�������ɹ�"<<endl;
    return true;
}
void LinkedListOfVehicle::exitSystem()
{
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);
}
int LinkedListOfVehicle::findInfo(string plateNumber,bool tag)
{
    //�ж������Ƿ�Ϊ��
    if(head->next==nullptr)
    {
        cout<<"����������ϢΪ��"<<endl;
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
        cout<<"��Ҫ���ҵĳ�����Ϣ����"<<endl;
        printInfo(temp->next);
        cout<<pos;
        }
        return pos;
    }
    else
    {
        cout<<"������Ϣδ�ҵ�����ȷ�ϳ��ƺ��Ƿ�������ȷ"<<endl;
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
    //���δ���ҵ�������Ϣ���޷��޸Ľ��
    int pos=findInfo(plateNumber,0);
    if(pos==-1)
    {
        return false;
    }
    VehicleInfo*temp=head;
    //�ҵ����޸Ľ��
    while(pos>=0)
    {
        temp=temp->next;
        pos--;
    }
    //���ҳɹ�����ʾ�û�������Ϣ
    cout<<"������Ҫ�޸ĵ�������Ϣ"<<endl;
    cout<<"1.�������ƺ�"<<endl;
    cout<<"2.������ɫ"<<endl;
    int choice;
    string Info;
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"�����������µĳ��ƺ�"<<endl;
        cin>>Info;
        temp->plateNum=Info;
        break;
    case 2:
        cout<<"�����������µ���ɫ"<<endl;
        cin>>Info;
        temp->color=Info;
        break;
    default:
        break;
    }
    cout<<"�޸Ĳ����ɹ�"<<endl;
    return true;
}
void LinkedListOfVehicle::printInfo(VehicleInfo*temp)
{
    cout<<"�����ĳ�������"<<setw(10)<<temp->manufactureDate<<" �ͺ�Ϊ "<<setw(10)<<temp->model
    <<" ��ɫ "<<setw(8)<<temp->color<<" ���ƺ� "<<setw(12)<<temp->plateNum
    <<" Ʒ�� "<<setw(12)<<temp->brand<<endl;
}
void LinkedListOfVehicle::showList()
{
    //�ж������Ƿ�Ϊ��
    if (head->next == nullptr)
    {
        cout << "����Ϊ��" << endl;
        return;
    }
    //������ͨ������������������
    VehicleInfo* temp = head->next;
    while (true)
    {
        //�ж��Ƿ��������
        if (temp == nullptr)
        {
            break;
        }
        //����ڵ���Ϣ
        printInfo(temp);
        temp = temp->next;
    }
}
void LinkedListOfVehicle::showMenu()
{
    cout << "****************************" << endl;
	cout << "****��ӭʹ�ó�������ϵͳ****" << endl;
	cout << "***** 0���˳�����ϵͳ  *****" << endl;
	cout << "***** 1�����ӳ�����Ϣ  *****" << endl;
	cout << "***** 2����ʾ������Ϣ  *****" << endl;
	cout << "***** 3��ɾ��������Ϣ  *****" << endl;
	cout << "***** 4���޸ĳ�����Ϣ  *****" << endl;
	cout << "***** 5�����ҳ�����Ϣ  *****" << endl;
	cout << "****************************" << endl;
	cout << endl;
}
