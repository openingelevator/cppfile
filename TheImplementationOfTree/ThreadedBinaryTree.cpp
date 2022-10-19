#include<iostream>
using namespace std;
//线索二叉树
//n个结点的二叉链表中含有n+1个空指针域
//利用二叉链表中的空指针域，存放指向结点在某中遍历次序下的前驱和后继结点的指针，这种附加指针称为“线索”
//这种加上了线索的二叉链表称为线索链表，相应的二叉树称为线索二叉树
//根据线索性质的不同可以将线索二叉树分为前序，中序和后序线索二叉树

//当线索化二叉树后，Node结点的属性left和right，有如下情况
//(1)left指向的是左子树，也可能是指向前驱结点
//(2)right指向的是右子树，也可能指向后继结点

class Node
{
public:
    Node(int no)
    {
        this->m_num=no;
        this->left=nullptr;
        this->right=nullptr;
        this->leftType=0;
        this->rightType=0;
    }
    void printInfo()
    {
        cout<<"node="<<m_num<<endl;
    }
    int m_num;
    Node* left;
    Node* right;
    //1.如果leftTyte==0表示指向的是左子树，如果为1则表示指向前驱结点
    //2.如果rightType==0表示指向的是右子树，如果为1则表示指向后继结点
    int leftType;
    int rightType;
};
class BinaryTree
{
public:
    Node*root;
    //为了实现线索化，需要创建指向当前结点的前驱结点的指针
    //在递归进行线索化时，pre总是保留前一个结点
    Node*pre=nullptr;
    //编写对二叉树进行中序线索化的方法
    //node即为当前需要线索化的结点
    void threadNodes()
    {
        threadNodes(root);
    }
    void threadNodes(Node*node)
    {
        //如果node==nullptr，不能线索化
        if(node==nullptr)
        {
            return;
        }
        //先线索化左子树
        threadNodes(node->left);
        //线索化当前结点
        //处理当前结点的前驱结点
        if(node->left==nullptr)
        {
            node->left=pre;
            node->leftType=1;
        }
        //处理后继结点
        if(pre!=nullptr&&pre->right==nullptr)
        {
            //让前驱结点的右指针指向当前结点
            pre->right=node;
            pre->rightType=1;
        }
        //每处理一个结点后，让当前结点是下一个结点的前驱结点
        pre=node;
        //再线索化右子树
         threadNodes(node->right);
    }
    //遍历中序线索化二叉树
    void threadList()
    {
        //定义一个变量，存储当前遍历的结点，从root开始
        Node*node=root;
        while(node!=nullptr)
        {
            //循环找到leftType==1的结点
            while(node->leftType==0)
            {
                node=node->left;
            }
            //打印当前结点
            node->printInfo();
            //如果当前结点的右指针指向的是后继结点，就一直输出
            while(node->rightType==1)
            {
                node=node->right;
                node->printInfo();
            }
            //替换这个遍历的结点
            node=node->right;
        }
    }
};

int main()
{
    Node*root=new Node(1);
    Node*node2=new Node(3);
    Node*node3=new Node(6);
    Node*node4=new Node(8);
    Node*node5=new Node(10);
    Node*node6=new Node(14);

    root->left=node2;
    root->right=node3;
    node2->left=node4;
    node2->right=node5;
    node3->left=node6;

    BinaryTree bst;
    bst.root=root;
    bst.threadNodes();
    // cout<<"node5前驱结点的值为"<<node5->left->m_num<<"\n后继结点的值为"<<node5->right->m_num<<"\n";

    //当线索化二叉树后，不能够再使用原来的遍历方式
    //此时需要用新的方式遍历线索化二叉树，各个结点可以采用线性方式进行遍历，无需采用递归的方式
    cout<<"使用线索化方式遍历线索化二叉树"<<endl;
    bst.threadList();
    system("pause");
    return 0;
}