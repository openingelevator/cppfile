/*
 * @Author: ֣᷷� 
 * @Date: 2022-10-13 19:07:17 
 * @Last Modified by:   ֣᷷� 
 * @Id:202130462264
 * @Last Modified time: 2022-10-13 19:07:17 
 */
#include"BinarySearchTree.h"
#include<iostream>
using namespace std;
void Node::insert(Node* node)
{
    if(node==nullptr){
        return ;
    }
    if(node->value<this->value){
        //�����ǰ������ӽ��Ϊ��
        if(this->left==nullptr){
            this->left=node;
        }else{
            //�ݹ������������
            this->left->insert(node);
        }
    }else{
        if(this->right==nullptr){
            this->right=node;
        }else{
            //�ݹ������������
            this->right->insert(node);
        }
    }
}
void Node::preOrder(){
    cout<<"Node[value="<<this->value<<"] "<<endl;
    if(this->left!=nullptr){
        this->left->preOrder();
    }
    if(this->right!=nullptr){
        this->right->preOrder();
    }
}
void Node::inOrder(){
    if(this->left!=nullptr){
        this->left->inOrder();
    }
    cout<<"Node[value="<<this->value<<"] "<<endl;
    if(this->right!=nullptr){
        this->right->inOrder();
    }
}
void Node::inOrder(int&num){
    if(this->left!=nullptr){
        this->left->inOrder(num);
    }
    if(this->left==nullptr&&this->right==nullptr){
        num++;
        cout<<"leafNodes[value="<<this->value<<"] "<<endl;
    }
    if(this->right!=nullptr){
        this->right->inOrder(num);
    }
}
void Node::postOrder(){
    if(this->left!=nullptr){
        this->left->inOrder();
    }
    if(this->right!=nullptr){
        this->right->inOrder();
    }
    cout<<"Node[value="<<this->value<<"] "<<endl;
}
Node* Node::search(int val){
    if(this->value==val){
        return this;
    }else if(val<this->value){//������ҵ�ֵС�ڵ�ǰֵ������ǰ��������������
        if(this->left==nullptr){
            return nullptr;
        }else{
            return this->left->search(val);
        }
    }else if(val>this->value){//������ҵ�ֵ���ڵ�ǰֵ������ǰ��������������
        if(this->right==nullptr){
            return nullptr;
        }else{
            return this->right->search(val);
        }
    }
    return nullptr;
}
Node* Node::searchParent(int val){
    if((this->left!=nullptr&&this->left->value==val)||
    (this->right!=nullptr&&this->right->value==val)){
        return this;
    }else{
        //������ҵ�ֵС�ڵ�ǰ����ֵ�����ҵ�ǰ�������ӽ�㲻Ϊ��
        if(val<this->value&&this->left!=nullptr){//���������ݹ����
            return this->left->searchParent(val);
        }else if(val>this->value&&this->right!=nullptr){//���������ݹ����
            return this->right->searchParent(val);
        }
    }
    return nullptr;
}
void BinarySearchTree::Insert(Node*node){
    if(root==nullptr){
        root=node;
    }else{
        root->insert(node);
    }
}
void BinarySearchTree::traverseOfLeaf(){
    if(root==nullptr){
        cout<<"������Ϊ�գ�û��Ҷ�ӽ��"<<endl;
    }else{
        int num=0;
        root->inOrder(num);
        cout<<"Ҷ�ӽڵ�����Ϊ"<<num<<endl;
    }
}
void BinarySearchTree::PreOrder(){
    if(root!=nullptr){
        root->preOrder();
    }else{
        cout<<"������Ϊ�գ����ܱ���"<<endl;
    }
}
void BinarySearchTree::InOrder(){
    if(root!=nullptr){
        root->inOrder();
    }else{
        cout<<"������Ϊ�գ����ܱ���"<<endl;
    }
}
void BinarySearchTree::PostOrder(){
    if(root!=nullptr){
        root->postOrder();
    }else{
        cout<<"������Ϊ�գ����ܱ���"<<endl;
    }
}
Node*BinarySearchTree::Find(int val){
    if(root==nullptr){
        return nullptr;
    }else{
        return root->search(val);
    }
}
Node*BinarySearchTree::SearchParent(int val){
    if(root==nullptr){
        return nullptr;
    }else{
        return root->searchParent(val);
    }
}
int BinarySearchTree::delRightTreeMin(Node*node){
    Node* temp=node;
    while(temp->left!=nullptr){
        temp=temp->left;
    }
    int tempVal=temp->value;
    DeleteNode(temp->value);
    return tempVal;
}
void BinarySearchTree::DeleteNode(int val){
    if(root==nullptr){
        cout<<"������Ϊ�գ��޷�ɾ��"<<endl;
        return ;
    }else{
        Node* targetNode=Find(val);
        //���û���ҵ�Ҫɾ���Ľ��
        if(targetNode==nullptr){
            return ;
        }
        //�����ǰ������ֻ��һ�����
        if(root->left==nullptr&&root->right==nullptr){
            root=nullptr;
            return ;
        }
        //Ѱ��targetNode�ĸ����
        Node* parent = SearchParent(val);
        //���Ҫɾ������Ҷ�ӽ��
        if(targetNode->left==nullptr&&targetNode->right==nullptr){
            //ȷ��targetNode��parent�����ӽ�㻹�����ӽ��
            if(parent->left!=nullptr&&parent->left->value==val){
                parent->left=nullptr;
            }else if(parent->right!=nullptr&&parent->right->value==val){
                parent->right=nullptr;
            }
        }else if(targetNode->left!=nullptr&&targetNode->right!=nullptr){//Ҫɾ�������������Ľ��
            int minVal=delRightTreeMin(targetNode->right);
            targetNode->value=minVal;
        }else{
            //���Ҫɾ���Ľ�������ӽ��
            if(targetNode->left!=nullptr){
                if(parent!=nullptr){
                if(parent->left->value==val){
                    parent->left=targetNode->left;
                }else{
                    parent->right=targetNode->left;
                }
                }else{
                    root=targetNode->left;
                }
            }else{//���Ҫɾ���Ľ�������ӽ��
                if(parent!=nullptr){
                if(parent->left->value==val){
                    parent->left=targetNode->right;
                }else{
                    parent->right=targetNode->right;
                }
                }else{
                    root=targetNode->right;
                }
            }
        }
    }
}