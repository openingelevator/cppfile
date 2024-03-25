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
    }
    void inOrder(){
        if(this->left!=nullptr){
            this->left->inOrder();
        }
        cout<<this->value<<" ";
        if(this->right!=nullptr){
            this->right->inOrder();
        }
    }
    //删除结点操作
    //情况一：删除叶子结点
    //首先找到要删除结点targetNode的父结点parent（考虑是否存在父结点）
    //确定targetNode是parent的左子结点还是右子结点
    //情况二：删除只有一颗子树的结点
    //首先找到要删除结点targetNode的父结点parent
    //确定targetNode的子结点是左子结点还是右子结点
    //确定targetNode是parent的左子结点还是右子结点
    //（1）判断targetNode有左子结点
    //如果targetNode是parent的左子结点
    //parent->left=targetNode->left;
    //如果targetNode是parent的右子结点
    //parent->right=targetNode->left;
    //（2）判断targetNode有右子结点
    //如果targetNode是parent的左子结点
    //parent->left=targetNode->right;
    //如果targetNode是parent的右子结点
    //parent->right=targetNode->right;
    //情况三：删除两颗子树的结点
    //首先找到要删除结点targetNode的父结点parent
    //从targetNode的右子树找到最小的结点
    //用一个临时变量将最小结点的值保存temp
    //删除该最小结点
    //targetNode->value=temp;

    //查找要删除的结点，返回要删除的结点
    Node*search(int val){
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
    //查找要删除结点的父结点，返回要删除节点的父结点
    Node* searchParent(int val){
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
};
class BinarySearchTree{
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
    //查找要删除的结点
    Node*Search(int val){
        if(root==nullptr){
            return nullptr;
        }else{
            return root->search(val);
        }
    }
    //查找要删除的结点的父结点
    Node*SearchParent(int val){
        if(root==nullptr){
            return nullptr;
        }else{
            return root->searchParent(val);
        }
    }
    //编写方法查找右子树中值最小的结点
    int delRightTreeMin(Node*node){
        Node* temp=node;
        while(temp->left!=nullptr){
            temp=temp->left;
        }
        int tempVal=temp->value;
        DeleteNode(temp->value);
        return tempVal;
    }

    void DeleteNode(int val){
        if(root==nullptr){
            cout<<"二叉树为空，无法删除"<<endl;
            return ;
        }else{
            Node* targetNode=Search(val);
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
                    if(parent->left!=nullptr&&parent->left->value==val){
                        parent->left=targetNode->left;
                    }else{
                        parent->right=targetNode->left;
                    }
                    }else{
                        root=targetNode->left;
                    }
                }else{//如果要删除的结点有右子结点
                    if(parent!=nullptr){
                    if(parent->left!=nullptr&&parent->left->value==val){
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
};
int main(){
    int arr[8]={7,3,10,12,5,1,9,2};
    BinarySearchTree* bst=new BinarySearchTree();
    //循环添加结点到二叉排序树
    for(int i=0;i<8;i++){
        bst->Add(new Node(arr[i]));
    }
    bst->InOrder();
    cout<<endl;
    bst->DeleteNode(2);
    bst->DeleteNode(5);
    bst->DeleteNode(9);
    bst->DeleteNode(12);
    bst->DeleteNode(7);
    bst->DeleteNode(3);
    bst->DeleteNode(1);
    bst->DeleteNode(10);
    bst->InOrder();
    system("pause");
    return 0;
}