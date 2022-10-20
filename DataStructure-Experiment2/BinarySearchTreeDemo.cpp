/*
 * @Author: 郑岱锋 
 * @Date: 2022-10-13 19:07:10 
 * @Last Modified by: 郑岱锋
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
    // cout<<"初始化树，请输入树结点的序列"<<endl;
    // int value;
    // for(int i=0;i<10;++i){
    //     cin>>value;
    //     bst->Insert(new Node(value));
    // }
    int choice = 0;
    while (true)
    {
        cout<<"****************  请输入您的选择  ****************"<<endl;
        cout<<"****************   0：退出系统    ****************"<<endl;
        cout<<"****************   1：前序遍历    ****************"<<endl;
        cout<<"****************   2：中序遍历    ****************"<<endl;
        cout<<"****************   3：后序遍历    ****************"<<endl;
        cout<<"****************   4：查找数值    ****************"<<endl;
        cout<<"****************   5：插入数值    ****************"<<endl;
        cout<<"****************   6：删除数值    ****************"<<endl;
        cout<<"****************   7：显示叶子结点 ****************"<<endl;
        cout << "请输入您的选择" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0://退出程序
            exit(0);
            break;
        case 1:
            cout<<"前序遍历结果为"<<endl;
            bst->PreOrder();
            break;
        case 2:
            cout<<"中序遍历结果为"<<endl;
            bst->InOrder();
            break;
        case 3:
            cout<<"后序遍历结果为"<<endl;
            bst->PostOrder();
            break;
        case 4:
            {cout<<"请输入要查找的值"<<endl;
            int value;
            cin>>value;
            Node* temp=nullptr;
            temp=bst->Find(value);
            if(temp!=nullptr){
                cout<<"查找成功"<<endl;
                cout<<"Node[value="<<temp->value<<"]在二叉树中"<<endl;
            }else{
                cout<<"查找失败"<<endl;
            }
            }
            break;
        case 5:
            {cout<<"请输入要插入的值"<<endl;
            int value;
            cin>>value;
            bst->Insert(new Node(value));
            cout<<"插入后的结果为"<<endl;
            bst->InOrder();
            }
            break;
        case 6:
            {cout<<"请输入要删除的值"<<endl;
            int value;
            cin>>value;
            bst->DeleteNode(value);
            cout<<"删除后的结果为"<<endl;
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