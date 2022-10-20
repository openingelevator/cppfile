/*
 * @Author: ֣᷷� 
 * @Date: 2022-10-13 19:07:10 
 * @Last Modified by: ֣᷷�
 * @Id:202130462264
 * @Last Modified time: 2022-10-13 19:54:21
 */
#include<iostream>
#include"BinarySearchTree.h"
#include"BinarySearchTree.cpp"
using namespace std;
int main(){
    // int arr1[10]={7,3,10,12,5,1,9,2,8,15};
    // int arr2[10]={9,13,10,6,8,11,1,4,5,19};
    int arr3[10]={17,8,20,6,9,25,14,19,4,5};
    BinarySearchTree* bst=new BinarySearchTree();
    for(int i=0;i<10;++i){
        bst->Insert(new Node(arr3[i]));
    }
    // cout<<"��ʼ����������������������"<<endl;
    // int value;
    // for(int i=0;i<10;++i){
    //     cin>>value;
    //     bst->Insert(new Node(value));
    // }
    int choice = 0;
    while (true)
    {
        cout<<"****************  ����������ѡ��  ****************"<<endl;
        cout<<"****************   0���˳�ϵͳ    ****************"<<endl;
        cout<<"****************   1��ǰ�����    ****************"<<endl;
        cout<<"****************   2���������    ****************"<<endl;
        cout<<"****************   3���������    ****************"<<endl;
        cout<<"****************   4��������ֵ    ****************"<<endl;
        cout<<"****************   5��������ֵ    ****************"<<endl;
        cout<<"****************   6��ɾ����ֵ    ****************"<<endl;
        cout<<"****************   7����ʾҶ�ӽ�� ****************"<<endl;
        cout << "����������ѡ��" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0://�˳�����
            exit(0);
            break;
        case 1:
            cout<<"ǰ��������Ϊ"<<endl;
            bst->PreOrder();
            break;
        case 2:
            cout<<"����������Ϊ"<<endl;
            bst->InOrder();
            break;
        case 3:
            cout<<"����������Ϊ"<<endl;
            bst->PostOrder();
            break;
        case 4:
            {cout<<"������Ҫ���ҵ�ֵ"<<endl;
            int value;
            cin>>value;
            Node* temp=nullptr;
            temp=bst->Find(value);
            if(temp!=nullptr){
                cout<<"���ҳɹ�"<<endl;
                cout<<"Node[value="<<temp->value<<"]�ڶ�������"<<endl;
            }else{
                cout<<"����ʧ��"<<endl;
            }
            }
            break;
        case 5:
            {cout<<"������Ҫ�����ֵ"<<endl;
            int value;
            cin>>value;
            bst->Insert(new Node(value));
            cout<<"�����Ľ��Ϊ"<<endl;
            bst->InOrder();
            }
            break;
        case 6:
            {cout<<"������Ҫɾ����ֵ"<<endl;
            int value;
            cin>>value;
            bst->DeleteNode(value);
            cout<<"ɾ����Ľ��Ϊ"<<endl;
            bst->InOrder();
            }
            break;
        case 7:
            bst->traverseOfLeaf();
            break;
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