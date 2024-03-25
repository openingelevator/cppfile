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
    //ɾ��������
    //���һ��ɾ��Ҷ�ӽ��
    //�����ҵ�Ҫɾ�����targetNode�ĸ����parent�������Ƿ���ڸ���㣩
    //ȷ��targetNode��parent�����ӽ�㻹�����ӽ��
    //�������ɾ��ֻ��һ�������Ľ��
    //�����ҵ�Ҫɾ�����targetNode�ĸ����parent
    //ȷ��targetNode���ӽ�������ӽ�㻹�����ӽ��
    //ȷ��targetNode��parent�����ӽ�㻹�����ӽ��
    //��1���ж�targetNode�����ӽ��
    //���targetNode��parent�����ӽ��
    //parent->left=targetNode->left;
    //���targetNode��parent�����ӽ��
    //parent->right=targetNode->left;
    //��2���ж�targetNode�����ӽ��
    //���targetNode��parent�����ӽ��
    //parent->left=targetNode->right;
    //���targetNode��parent�����ӽ��
    //parent->right=targetNode->right;
    //�������ɾ�����������Ľ��
    //�����ҵ�Ҫɾ�����targetNode�ĸ����parent
    //��targetNode���������ҵ���С�Ľ��
    //��һ����ʱ��������С����ֵ����temp
    //ɾ������С���
    //targetNode->value=temp;

    //����Ҫɾ���Ľ�㣬����Ҫɾ���Ľ��
    Node*search(int val){
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
    //����Ҫɾ�����ĸ���㣬����Ҫɾ���ڵ�ĸ����
    Node* searchParent(int val){
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
};
class BinarySearchTree{
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
    //����Ҫɾ���Ľ��
    Node*Search(int val){
        if(root==nullptr){
            return nullptr;
        }else{
            return root->search(val);
        }
    }
    //����Ҫɾ���Ľ��ĸ����
    Node*SearchParent(int val){
        if(root==nullptr){
            return nullptr;
        }else{
            return root->searchParent(val);
        }
    }
    //��д����������������ֵ��С�Ľ��
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
            cout<<"������Ϊ�գ��޷�ɾ��"<<endl;
            return ;
        }else{
            Node* targetNode=Search(val);
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
                    if(parent->left!=nullptr&&parent->left->value==val){
                        parent->left=targetNode->left;
                    }else{
                        parent->right=targetNode->left;
                    }
                    }else{
                        root=targetNode->left;
                    }
                }else{//���Ҫɾ���Ľ�������ӽ��
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
    //ѭ����ӽ�㵽����������
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