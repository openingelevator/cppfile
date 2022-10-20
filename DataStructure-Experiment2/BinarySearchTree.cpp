/*
 * @Author: 郑岱锋 
 * @Date: 2022-10-13 19:07:17 
 * @Last Modified by:   郑岱锋 
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
        //如果当前结点左子结点为空
        if(this->left==nullptr){
            this->left=node;
        }else{
            //递归向左子树添加
            this->left->insert(node);
        }
    }else{
        if(this->right==nullptr){
            this->right=node;
        }else{
            //递归向右子树添加
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
    }else if(val<this->value){//如果查找的值小于当前值，则向当前结点的左子树查找
        if(this->left==nullptr){
            return nullptr;
        }else{
            return this->left->search(val);
        }
    }else if(val>this->value){//如果查找的值大于当前值，则向当前结点的右子树查找
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
        //如果查找的值小于当前结点的值，并且当前结点的左子结点不为空
        if(val<this->value&&this->left!=nullptr){//向左子树递归查找
            return this->left->searchParent(val);
        }else if(val>this->value&&this->right!=nullptr){//向右子树递归查找
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
        cout<<"二叉树为空，没有叶子结点"<<endl;
    }else{
        int num=0;
        root->inOrder(num);
        cout<<"叶子节点数量为"<<num<<endl;
    }
}
void BinarySearchTree::PreOrder(){
    if(root!=nullptr){
        root->preOrder();
    }else{
        cout<<"二叉树为空，不能遍历"<<endl;
    }
}
void BinarySearchTree::InOrder(){
    if(root!=nullptr){
        root->inOrder();
    }else{
        cout<<"二叉树为空，不能遍历"<<endl;
    }
}
void BinarySearchTree::PostOrder(){
    if(root!=nullptr){
        root->postOrder();
    }else{
        cout<<"二叉树为空，不能遍历"<<endl;
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
        cout<<"二叉树为空，无法删除"<<endl;
        return ;
    }else{
        Node* targetNode=Find(val);
        //如果没有找到要删除的结点
        if(targetNode==nullptr){
            return ;
        }
        //如果当前二叉树只有一个结点
        if(root->left==nullptr&&root->right==nullptr){
            root=nullptr;
            return ;
        }
        //寻找targetNode的父结点
        Node* parent = SearchParent(val);
        //如果要删除的是叶子结点
        if(targetNode->left==nullptr&&targetNode->right==nullptr){
            //确定targetNode是parent的左子结点还是右子结点
            if(parent->left!=nullptr&&parent->left->value==val){
                parent->left=nullptr;
            }else if(parent->right!=nullptr&&parent->right->value==val){
                parent->right=nullptr;
            }
        }else if(targetNode->left!=nullptr&&targetNode->right!=nullptr){//要删除有两颗子树的结点
            int minVal=delRightTreeMin(targetNode->right);
            targetNode->value=minVal;
        }else{
            //如果要删除的结点有左子结点
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
            }else{//如果要删除的结点有右子结点
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