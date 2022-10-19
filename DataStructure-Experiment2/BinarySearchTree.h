#pragma once
#include<iostream>
using namespace std;
class Node{
public:
    Node(int val){
        this->value=val;
        this->left=nullptr;
        this->right=nullptr;
    }
    int value;
    Node*left;
    Node*right;
    //��ӽ��
    //�ݹ���ʽ��ӽ��
    void insert(Node*node);
    //ǰ�����
    void preOrder();
    //�������
    void inOrder();
    void inOrder(int&num);
    //�������
    void postOrder();
    //����Ҫɾ���Ľ�㣬����Ҫɾ���Ľ��
    Node*search(int val);
    //����Ҫɾ�����ĸ���㣬����Ҫɾ���ڵ�ĸ����
    Node* searchParent(int val);
};
class BinarySearchTree{
public:
    Node* root;
    //��ӽ��
    void Insert(Node*node);
    //Ҷ�ӽ��ı���
    void traverseOfLeaf();
    //ǰ�����
    void PreOrder();
    //�������
    void InOrder();
    //�������
    void PostOrder();
    //����Ҫɾ���Ľ��
    Node*Find(int val);
    //����Ҫɾ���Ľ��ĸ����
    Node*SearchParent(int val);
    //������������ֵ��С�Ľ��
    int delRightTreeMin(Node*node);
    //ɾ�����
    void  DeleteNode(int val);
};
