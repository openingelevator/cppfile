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
    //递归形式添加结点
    void add(Node* node)
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
                this->left->add(node);
            }
        }else{
            if(this->right==nullptr){
                this->right=node;
            }else{
                //递归向右子树添加
                this->right->add(node);
            }
        }
        //当添加完一个结点后，如果右子树的高度比左子树的高度大于1
        if(rightHeight()-leftHeight()>1){
            //如果右子树的左子树高度大于其右子树高度
            if(right!=nullptr&&right->leftHeight()>right->rightHeight()){
                right->rightRotate();
                this->leftRotate();
            }else{            
                leftRotate();
            }
            //需要直接返回
            return ;
        }
        //如果左子树的高度比右子树的高度大于1
        if(leftHeight()-rightHeight()>1){
            //如果左子树的右子树高度大于其左子树高度
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
    //返回当前结点高度
    int height(){
        return max(left==nullptr?0:left->height(),right==nullptr?0:right->height())+1;
    }
    //返回左子树高度
    int leftHeight(){
        if(left==nullptr){
            return 0;
        }
        return left->height();
    }
    //返回右子树高度
    int rightHeight(){
        if(right==nullptr){
            return 0;
        }
        return right->height();
    }

    //左旋转
    void leftRotate(){
        //创建新的结点，以当前结点的值
        Node*newNode=new Node(this->value);
        //把新的结点的左子树设置为当前结点的左子树，
        newNode->left=this->left;
        //把新结点的右子树设置为当前结点右子树的左子树
        newNode->right=this->right->left;
        //把当前结点的值替换为右子结点的值
        this->value=this->right->value;
        //把当前结点的右子树设置为右子树的右子树
        Node* temp=this->right;
        this->right=this->right->right;
        //把当前结点的左子树设置为新的结点
        this->left=newNode;
        delete temp;
    }
    //右旋转
    void rightRotate(){
        //创建新的结点，以当前结点的值
        Node*newNode=new Node(this->value);
        //把新的结点的右子树设置为当前结点的右子树，
        newNode->right=this->right;
        //把新结点的左子树设置为当前结点左子树的右子树
        newNode->left=this->left->right;
        //把当前结点的值替换为左子结点的值
        this->value=this->left->value;
        //把当前结点的左子树设置为左子树的左子树
        Node* temp=this->left;
        this->left=this->left->left;
        //把当前结点的右子树设置为新的结点
        this->right=newNode;
        delete temp;
    }

};
class AVLtree{
public:
    Node* root;
    //添加结点
    void Add(Node*node){
        if(root==nullptr){
            root=node;
        }else{
            root->add(node);
        }
    }
    //中序遍历
    void InOrder(){
        if(root!=nullptr){
            root->inOrder();
        }else{
            cout<<"二叉树为空，不能遍历"<<endl;
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
    cout<<"平衡处理后"<<endl;
    cout<<"根节点的高度为"<<avl->root->height()<<endl;
    cout<<"树的左子树的高度"<<avl->root->leftHeight()<<endl;
    cout<<"树的右子树的高度"<<avl->root->rightHeight()<<endl;
    cout<<"当前根节点为"<<avl->root->value<<endl;
    // cout<<"根节点的左子节点为"<<avl->root->left->value<<endl;
    // cout<<"根节点的右子节点为"<<avl->root->right->value<<endl;
    system("pause");
    return 0;
}