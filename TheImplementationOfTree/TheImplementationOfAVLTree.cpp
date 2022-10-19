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
    //�ݹ���ʽ��ӽ��
    void add(Node* node)
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
                this->left->add(node);
            }
        }else{
            if(this->right==nullptr){
                this->right=node;
            }else{
                //�ݹ������������
                this->right->add(node);
            }
        }
        //�������һ����������������ĸ߶ȱ��������ĸ߶ȴ���1
        if(rightHeight()-leftHeight()>1){
            //������������������߶ȴ������������߶�
            if(right!=nullptr&&right->leftHeight()>right->rightHeight()){
                right->rightRotate();
                this->leftRotate();
            }else{            
                leftRotate();
            }
            //��Ҫֱ�ӷ���
            return ;
        }
        //����������ĸ߶ȱ��������ĸ߶ȴ���1
        if(leftHeight()-rightHeight()>1){
            //������������������߶ȴ������������߶�
            if(left!=nullptr&&left->rightHeight()>left->leftHeight()){
                left->leftRotate();
                this->rightRotate();
            }else{            
                rightRotate();
            }
        }
    }
    void inOrder(){
        if(this->left!=nullptr){
            this->left->inOrder();
        }
        cout<<"Node[value="<<this->value<<"] "<<endl;
        if(this->right!=nullptr){
            this->right->inOrder();
        }
    }
    //���ص�ǰ���߶�
    int height(){
        return max(left==nullptr?0:left->height(),right==nullptr?0:right->height())+1;
    }
    //�����������߶�
    int leftHeight(){
        if(left==nullptr){
            return 0;
        }
        return left->height();
    }
    //�����������߶�
    int rightHeight(){
        if(right==nullptr){
            return 0;
        }
        return right->height();
    }

    //����ת
    void leftRotate(){
        //�����µĽ�㣬�Ե�ǰ����ֵ
        Node*newNode=new Node(this->value);
        //���µĽ�������������Ϊ��ǰ������������
        newNode->left=this->left;
        //���½�������������Ϊ��ǰ�����������������
        newNode->right=this->right->left;
        //�ѵ�ǰ����ֵ�滻Ϊ���ӽ���ֵ
        this->value=this->right->value;
        //�ѵ�ǰ��������������Ϊ��������������
        Node* temp=this->right;
        this->right=this->right->right;
        //�ѵ�ǰ��������������Ϊ�µĽ��
        this->left=newNode;
        delete temp;
    }
    //����ת
    void rightRotate(){
        //�����µĽ�㣬�Ե�ǰ����ֵ
        Node*newNode=new Node(this->value);
        //���µĽ�������������Ϊ��ǰ������������
        newNode->right=this->right;
        //���½�������������Ϊ��ǰ�����������������
        newNode->left=this->left->right;
        //�ѵ�ǰ����ֵ�滻Ϊ���ӽ���ֵ
        this->value=this->left->value;
        //�ѵ�ǰ��������������Ϊ��������������
        Node* temp=this->left;
        this->left=this->left->left;
        //�ѵ�ǰ��������������Ϊ�µĽ��
        this->right=newNode;
        delete temp;
    }

};
class AVLtree{
public:
    Node* root;
    //��ӽ��
    void Add(Node*node){
        if(root==nullptr){
            root=node;
        }else{
            root->add(node);
        }
    }
    //�������
    void InOrder(){
        if(root!=nullptr){
            root->inOrder();
        }else{
            cout<<"������Ϊ�գ����ܱ���"<<endl;
        }
    }

};
int main(){
    int arr[6]={10,11,7,6,8,9};
    AVLtree*avl=new AVLtree();
    for(int i=0;i<6;i++){
        avl->Add(new Node(arr[i]));
    }
    avl->InOrder();
    cout<<"ƽ�⴦���"<<endl;
    cout<<"���ڵ�ĸ߶�Ϊ"<<avl->root->height()<<endl;
    cout<<"�����������ĸ߶�"<<avl->root->leftHeight()<<endl;
    cout<<"�����������ĸ߶�"<<avl->root->rightHeight()<<endl;
    cout<<"��ǰ���ڵ�Ϊ"<<avl->root->value<<endl;
    // cout<<"���ڵ�����ӽڵ�Ϊ"<<avl->root->left->value<<endl;
    // cout<<"���ڵ�����ӽڵ�Ϊ"<<avl->root->right->value<<endl;
    system("pause");
    return 0;
}