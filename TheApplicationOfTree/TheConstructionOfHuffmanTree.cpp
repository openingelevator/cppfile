//����n��Ȩֵ��Ϊn��Ҷ�ӽ�㣬����һ�ö��������������Ĵ�Ȩ·�����ȴﵽ��С������������Ϊ���Ŷ�����
//·����·�����ȣ���һ�����У���һ���ڵ����¿��Դﵽ�ĺ��ӻ����ӽ��֮���ͨ·��Ϊ·��
//ͨ·�з�֧����Ŀ��Ϊ·������
//���涨�����Ĳ���Ϊ1����Ӹ��ڵ㵽��L�����·������ΪL-1
//����Ȩ����Ȩ·�����ȣ��������н�㸳��һ������ĳ�ֺ������ֵ���������ֵ��Ϊ�ý���Ȩ
//���Ĵ�Ȩ·������Ϊ���Ӹ���㵽�ý��֮���·��������ý���Ȩ�ĳ˻�
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
//�����շ�����
//1.�Ը������д�С�����������ÿ�����ݶ���һ����㣬ÿһ����㶼���Կ�����һ����򵥵Ķ�����
//2.ȡ�������Ȩֵ��С�����ö�����
//3.���һ���µĶ����������µĶ������ĸ��ڵ��Ȩֵʱǰ�����ö����������Ȩֵ�ĺ�
//4.�ٽ�����µĶ��������Ը�����Ȩֵ��С�ٴ����򣬲����ظ�1-2-3-4�Ĳ��裬ֱ�����������е����ݶ���������ʱ�͵õ�һ�úշ�����
class Node{
public:
    Node(int val){
        this->value=val;
        this->left=nullptr;
        this->right=nullptr;
    }
    int value;//���Ȩֵ
    Node*left;
    Node*right;
    void printInfo(){
        cout<<"Node[value="<<value<<"] \n";
    }
    void preOrder(){
        this->printInfo();
        //�ݹ���������ǰ�����
        if(this->left!=nullptr){
            this->left->preOrder();
        }
        //�ݹ���������ǰ�����
        if(this->right!=nullptr){
            this->right->preOrder();
        }
    }
};
class Cmp{
    public:
    bool operator()(Node* n1,Node* n2){
        return n1->value<=n2->value;
    }
};
Node* CreateHuffmanTree(vector<int>&arr){
    deque<Node*>nodes;//list��������ʹ�ñ�׼�������sort
    //����ʹ��list�Դ���sort list<int>l;l.sort();
    for(int value:arr){
        nodes.push_back(new Node(value));
    }
    // cout<<"��һ�δ���ǰ"<<endl;
    // for(Node* item:nodes){
    //     item->printInfo();
    // }
    while(nodes.size()>1){
    //����
    sort(nodes.begin(),nodes.end(),Cmp());
    //ȡ�����ڵ�Ȩֵ��С�����ö�����
    Node*leftNode=nodes.at(0);
    Node*rightNode=nodes.at(1);
    //����һ���µĶ�����
    Node* parent=new Node(leftNode->value+rightNode->value);
    parent->right=rightNode;
    parent->left=leftNode;
    //��������ɾ��������Ķ�����
    nodes.pop_front();
    nodes.pop_front();
    //��parent�����������
    nodes.push_back(parent);
    }
    // for(Node* item:nodes){
    //     item->printInfo();
    // }
    return nodes.at(0);
}
void PreOrder(Node*root){
    if(root!=nullptr){
        root->preOrder();
    }else{
        cout<<"�����޷�����"<<endl;
    }

}
int main(){
    vector<int>arr{13,7,8,3,29,6,1,4};
    Node* root = CreateHuffmanTree(arr);
    PreOrder(root);
    system("pause");
    return 0;
}
