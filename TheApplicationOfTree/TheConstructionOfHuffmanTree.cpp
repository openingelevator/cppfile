//给定n个权值作为n个叶子结点，构造一棵二叉树，若该树的带权路径长度达到最小，称这样的树为最优二叉树
//路径和路径长度，在一棵树中，从一个节点往下可以达到的孩子或孙子结点之间的通路称为路径
//通路中分支的数目称为路径长度
//若规定根结点的层数为1，则从根节点到第L层结点的路径长度为L-1
//结点的权及带权路径长度：若将树中结点赋给一个有着某种含义的数值，则这个数值称为该结点的权
//结点的带权路径长度为：从根结点到该结点之间的路径长度与该结点的权的乘积
#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;
//构建赫夫曼树
//1.对给定序列从小到大进行排序，每个数据都是一个结点，每一个结点都可以看成是一颗最简单的二叉树
//2.取出根结点权值最小的两棵二叉树
//3.组成一颗新的二叉树，该新的二叉树的根节点的权值时前面两棵二叉树根结点权值的和
//4.再将这棵新的二叉树，以根结点的权值大小再次排序，不断重复1-2-3-4的步骤，直到序列中所有的数据都被处理，此时就得到一棵赫夫曼树
class Node{
public:
    Node(int val){
        this->value=val;
        this->left=nullptr;
        this->right=nullptr;
    }
    int value;//结点权值
    Node*left;
    Node*right;
    void printInfo(){
        cout<<"Node[value="<<value<<"] \n";
    }
    void preOrder(){
        this->printInfo();
        //递归向左子树前序遍历
        if(this->left!=nullptr){
            this->left->preOrder();
        }
        //递归向右子树前序遍历
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
    deque<Node*>nodes;//list容器不能使用标准库里面的sort
    //可以使用list自带的sort list<int>l;l.sort();
    for(int value:arr){
        nodes.push_back(new Node(value));
    }
    // cout<<"第一次处理前"<<endl;
    // for(Node* item:nodes){
    //     item->printInfo();
    // }
    while(nodes.size()>1){
    //排序
    sort(nodes.begin(),nodes.end(),Cmp());
    //取出根节点权值最小的两棵二叉树
    Node*leftNode=nodes.at(0);
    Node*rightNode=nodes.at(1);
    //构建一棵新的二叉树
    Node* parent=new Node(leftNode->value+rightNode->value);
    parent->right=rightNode;
    parent->left=leftNode;
    //从容器中删除处理过的二叉树
    nodes.pop_front();
    nodes.pop_front();
    //将parent加入二叉树中
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
        cout<<"空树无法遍历"<<endl;
    }

}
int main(){
    vector<int>arr{13,7,8,3,29,6,1,4};
    Node* root = CreateHuffmanTree(arr);
    PreOrder(root);
    system("pause");
    return 0;
}
