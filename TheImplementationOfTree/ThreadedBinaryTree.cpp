#include<iostream>
using namespace std;
//����������
//n�����Ķ��������к���n+1����ָ����
//���ö��������еĿ�ָ���򣬴��ָ������ĳ�б��������µ�ǰ���ͺ�̽���ָ�룬���ָ���ָ���Ϊ��������
//���ּ����������Ķ��������Ϊ����������Ӧ�Ķ�������Ϊ����������
//�����������ʵĲ�ͬ���Խ�������������Ϊǰ������ͺ�������������

//����������������Node��������left��right�����������
//(1)leftָ�������������Ҳ������ָ��ǰ�����
//(2)rightָ�������������Ҳ����ָ���̽��

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
    //1.���leftTyte==0��ʾָ����������������Ϊ1���ʾָ��ǰ�����
    //2.���rightType==0��ʾָ����������������Ϊ1���ʾָ���̽��
    int leftType;
    int rightType;
};
class BinaryTree
{
public:
    Node*root;
    //Ϊ��ʵ������������Ҫ����ָ��ǰ����ǰ������ָ��
    //�ڵݹ����������ʱ��pre���Ǳ���ǰһ�����
    Node*pre=nullptr;
    //��д�Զ��������������������ķ���
    //node��Ϊ��ǰ��Ҫ�������Ľ��
    void threadNodes()
    {
        threadNodes(root);
    }
    void threadNodes(Node*node)
    {
        //���node==nullptr������������
        if(node==nullptr)
        {
            return;
        }
        //��������������
        threadNodes(node->left);
        //��������ǰ���
        //����ǰ����ǰ�����
        if(node->left==nullptr)
        {
            node->left=pre;
            node->leftType=1;
        }
        //�����̽��
        if(pre!=nullptr&&pre->right==nullptr)
        {
            //��ǰ��������ָ��ָ��ǰ���
            pre->right=node;
            pre->rightType=1;
        }
        //ÿ����һ�������õ�ǰ�������һ������ǰ�����
        pre=node;
        //��������������
         threadNodes(node->right);
    }
    //��������������������
    void threadList()
    {
        //����һ���������洢��ǰ�����Ľ�㣬��root��ʼ
        Node*node=root;
        while(node!=nullptr)
        {
            //ѭ���ҵ�leftType==1�Ľ��
            while(node->leftType==0)
            {
                node=node->left;
            }
            //��ӡ��ǰ���
            node->printInfo();
            //�����ǰ������ָ��ָ����Ǻ�̽�㣬��һֱ���
            while(node->rightType==1)
            {
                node=node->right;
                node->printInfo();
            }
            //�滻��������Ľ��
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
    // cout<<"node5ǰ������ֵΪ"<<node5->left->m_num<<"\n��̽���ֵΪ"<<node5->right->m_num<<"\n";

    //���������������󣬲��ܹ���ʹ��ԭ���ı�����ʽ
    //��ʱ��Ҫ���µķ�ʽ���������������������������Բ������Է�ʽ���б�����������õݹ�ķ�ʽ
    cout<<"ʹ����������ʽ����������������"<<endl;
    bst.threadList();
    system("pause");
    return 0;
}