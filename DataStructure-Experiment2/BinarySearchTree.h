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
    //添加结点
    //递归形式添加结点
    void insert(Node*node);
    //前序遍历
    void preOrder();
    //中序遍历
    void inOrder();
    void inOrder(int&num);
    //后序遍历
    void postOrder();
    //查找要删除的结点，返回要删除的结点
    Node*search(int val);
    //查找要删除结点的父结点，返回要删除节点的父结点
    Node* searchParent(int val);
};
class BinarySearchTree{
public:
    Node* root;
    //添加结点
    void Insert(Node*node);
    //叶子结点的遍历
    void traverseOfLeaf();
    //前序遍历
    void PreOrder();
    //中序遍历
    void InOrder();
    //后序遍历
    void PostOrder();
    //查找要删除的结点
    Node*Find(int val);
    //查找要删除的结点的父结点
    Node*SearchParent(int val);
    //查找右子树中值最小的结点
    int delRightTreeMin(Node*node);
    //删除结点
    void  DeleteNode(int val);
};
