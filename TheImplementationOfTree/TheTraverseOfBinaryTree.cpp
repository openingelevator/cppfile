#include<iostream>
#include<string>
using namespace std;
class HeroNode
{
public:
    HeroNode(int no,string name)
    {
        this->m_num=no;
        this->m_name=name;
        this->left=nullptr;
        this->right=nullptr;
    }
    void printInfo()
    {
        cout<<"Heronode["<<m_num<<"] = "<<m_name<<endl;
    }
    //��дǰ���������
    void preOrder()
    {
        this->printInfo();
        //�ݹ���������ǰ�����
        if(this->left!=nullptr)
        {
            this->left->preOrder();
        }
        //�ݹ���������ǰ�����
        if(this->right!=nullptr)
        {
            this->right->preOrder();
        }
    }
    //�������
    void inOrder()
    {
        //�ݹ����������������
        if(this->left!=nullptr)
        {
            this->left->inOrder();
        }
        //�����ǰ�ڵ�
        this->printInfo();
        //�ݹ����������������
        if(this->right!=nullptr)
        {
            this->right->inOrder();
        }
    }
    //�������
    void postOrder()
    {
        //�ݹ����������������
        if(this->left!=nullptr)
        {
            this->left->postOrder();
        }
        //�ݹ����������������
        if(this->right!=nullptr)
        {
            this->right->postOrder();
        }
        //�����ǰ�ڵ�
       this->printInfo();
    }

    //ǰ���������
    HeroNode* preOrderSearch(int no)
    {
        cout<<"����ǰ�����"<<endl;
        //�Ƚϵ�ǰ�ڵ��ǲ���
        if(this->m_num==no)
        {
            return this;
        }
        HeroNode*resNode=nullptr;
        //�ж����ӽڵ��Ƿ�Ϊ��
        if(this->left!=nullptr)
        {
            resNode=this->left->preOrderSearch(no);
        }
        if(resNode!=nullptr)
        {
            return resNode;
        }
        //�ж����ӽڵ��Ƿ�Ϊ��
        if(this->right!=nullptr)
        {
            resNode=this->right->preOrderSearch(no);
        }
        
        return resNode;
    }
    //�����������
    HeroNode*inOrderSearch(int no)
    {
        HeroNode*resNode=nullptr;
        if(this->left!=nullptr)
        {
            resNode=this->left->inOrderSearch(no);
        }
        if(resNode!=nullptr)
        {
            return resNode;
        }
        cout<<"�����������"<<endl;
        if(this->m_num==no)
        {
            return this;
        }
        //�ж����ӽڵ��Ƿ�Ϊ��
        if(this->right!=nullptr)
        {
            resNode=this->right->inOrderSearch(no);
        }
        
        return resNode;
    }
    //�����������
    HeroNode*postOrderSearch(int no)
    { 
        HeroNode*resNode=nullptr;
        if(this->left!=nullptr)
        {
            resNode=this->left->postOrderSearch(no);
        }
        if(resNode!=nullptr)
        {
            return resNode;
        }
        //�ж����ӽڵ��Ƿ�Ϊ��
        if(this->right!=nullptr)
        {
            resNode=this->right->postOrderSearch(no);
        }
        if(resNode!=nullptr)
        {
            return resNode;
        }
        cout<<"����������"<<endl;
        if(this->m_num==no)
        {
            return this;
        }
        return resNode;
    }

    //ɾ������
    void delNode(int no)
    {
        if(this->left!=nullptr&&this->left->m_num==no)
        {
            this->left=nullptr;
            return ;
        }
        if(this->right!=nullptr&&this->right->m_num==no)
        {
            this->right=nullptr;
            return;
        }
        if(this->left!=nullptr)
        {
            this->left->delNode(no);

        }
        if(this->right!=nullptr)
        {
            this->right->delNode(no);
        }
    }

    int m_num;
    string m_name;
    HeroNode* left;
    HeroNode* right;
};
//����һ��������
class BinaryTree
{
public:
    HeroNode*root;
    //ǰ�����
    void PreOrder()
    {
        if(this->root!=nullptr)
        {
            this->root->preOrder();
        }
        else
        {
            cout<<"������Ϊ�գ��޷�����"<<endl;
        }
    }
    //�������
    void InOrder()
    {
        if(this->root!=nullptr)
        {
            this->root->inOrder();
        }
        else
        {
            cout<<"������Ϊ�գ��޷�����"<<endl;
        }
    }
    //�������
    void PostOrder()
    {
        if(this->root!=nullptr)
        {
            this->root->postOrder();
        }
        else
        {
            cout<<"������Ϊ�գ��޷�����"<<endl;
        }
    }
    //ǰ�����
    HeroNode* PreOrderSearch(int no)
    {
        if(this->root!=nullptr)
        {
            return this->root->preOrderSearch(no);
        }
        else
        {
            cout<<"������Ϊ�գ��޷�����"<<endl;
            return nullptr;
        }
    }
    //�������
    HeroNode* InOrderSearch(int no)
    {
        if(this->root!=nullptr)
        {
            return this->root->inOrderSearch(no);
        }
        else
        {
            cout<<"������Ϊ�գ��޷�����"<<endl;
            return nullptr;
        }
    }
    //�������
    HeroNode* PostOrderSearch(int no)
    {
        if(this->root!=nullptr)
        {
            return this->root->postOrderSearch(no);
        }
        else
        {
            cout<<"������Ϊ�գ��޷�����"<<endl;
            return nullptr;
        }
    }
    //ɾ����㷽��
    void DelNode(int no)
    {
        if(root==nullptr)
        {
            cout<<"����Ϊ�����޷�ɾ��"<<endl;
        }
        if(root->m_num==no)
        {
            root=nullptr;
        }else
        {
            root->delNode(no);
        }
    }
};
int main()
{
    HeroNode*node1=new HeroNode(1,"�ν�");
    HeroNode*node2=new HeroNode(2,"�ֳ�");
    HeroNode*node3=new HeroNode(3,"����");
    HeroNode*node4=new HeroNode(4,"¬����");
    HeroNode*node5=new HeroNode(5,"��ʤ");
    node1->left=node2;
    node1->right=node3;
    node3->left=node5;
    node3->right=node4;
    BinaryTree BST;
    BST.root=node1;
    // cout<<"ǰ��������"<<endl;
    // BST.PreOrder();
    // cout<<"����������"<<endl;
    // BST.InOrder();
    // cout<<"����������"<<endl;
    // BST.PostOrder();
    
    //ǰ�����
    // cout<<"ǰ�������ʽ"<<endl;
    // HeroNode* res=BST.PreOrderSearch(5);
    // if(res!=nullptr)
    // {
    //     cout<<"���ҵ��ڵ㣬��ϢΪno="<<res->m_num<<" name="<<res->m_name<<endl;
    // }else
    // {
    //     cout<<"û���ҵ�"<<endl;
    // }
    // cout<<"���������ʽ"<<endl;
    // HeroNode* res1=BST.InOrderSearch(3);
    // if(res1!=nullptr)
    // {
    //     cout<<"���ҵ��ڵ㣬��ϢΪno="<<res1->m_num<<" name="<<res1->m_name<<endl;
    // }else
    // {
    //     cout<<"û���ҵ�"<<endl;
    // }
    // cout<<"���������ʽ"<<endl;
    // HeroNode* res2=BST.PostOrderSearch(5);
    // if(res2!=nullptr)
    // {
    //     cout<<"���ҵ��ڵ㣬��ϢΪno="<<res2->m_num<<" name="<<res2->m_name<<endl;
    // }else
    // {
    //     cout<<"û���ҵ�"<<endl;
    // }
    cout<<"ɾ��ǰ��ǰ�����"<<endl;
    BST.PreOrder();
    BST.DelNode(3);
    cout<<"ɾ����ǰ�����"<<endl;
    BST.PreOrder();
    system("pause");
    return 0;
}