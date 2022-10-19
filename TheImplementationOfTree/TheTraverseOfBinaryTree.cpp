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
    //编写前序遍历方法
    void preOrder()
    {
        this->printInfo();
        //递归向左子树前序遍历
        if(this->left!=nullptr)
        {
            this->left->preOrder();
        }
        //递归向右子树前序遍历
        if(this->right!=nullptr)
        {
            this->right->preOrder();
        }
    }
    //中序遍历
    void inOrder()
    {
        //递归向左子树中序遍历
        if(this->left!=nullptr)
        {
            this->left->inOrder();
        }
        //输出当前节点
        this->printInfo();
        //递归向右子树中序遍历
        if(this->right!=nullptr)
        {
            this->right->inOrder();
        }
    }
    //后序遍历
    void postOrder()
    {
        //递归向左子树后序遍历
        if(this->left!=nullptr)
        {
            this->left->postOrder();
        }
        //递归向右子树后序遍历
        if(this->right!=nullptr)
        {
            this->right->postOrder();
        }
        //输出当前节点
       this->printInfo();
    }

    //前序遍历查找
    HeroNode* preOrderSearch(int no)
    {
        cout<<"进入前序遍历"<<endl;
        //比较当前节点是不是
        if(this->m_num==no)
        {
            return this;
        }
        HeroNode*resNode=nullptr;
        //判断左子节点是否为空
        if(this->left!=nullptr)
        {
            resNode=this->left->preOrderSearch(no);
        }
        if(resNode!=nullptr)
        {
            return resNode;
        }
        //判断右子节点是否为空
        if(this->right!=nullptr)
        {
            resNode=this->right->preOrderSearch(no);
        }
        
        return resNode;
    }
    //中序遍历查找
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
        cout<<"进入中序遍历"<<endl;
        if(this->m_num==no)
        {
            return this;
        }
        //判断右子节点是否为空
        if(this->right!=nullptr)
        {
            resNode=this->right->inOrderSearch(no);
        }
        
        return resNode;
    }
    //后序遍历查找
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
        //判断右子节点是否为空
        if(this->right!=nullptr)
        {
            resNode=this->right->postOrderSearch(no);
        }
        if(resNode!=nullptr)
        {
            return resNode;
        }
        cout<<"进入后序遍历"<<endl;
        if(this->m_num==no)
        {
            return this;
        }
        return resNode;
    }

    //删除操作
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
//定义一个二叉树
class BinaryTree
{
public:
    HeroNode*root;
    //前序遍历
    void PreOrder()
    {
        if(this->root!=nullptr)
        {
            this->root->preOrder();
        }
        else
        {
            cout<<"二叉树为空，无法遍历"<<endl;
        }
    }
    //中序遍历
    void InOrder()
    {
        if(this->root!=nullptr)
        {
            this->root->inOrder();
        }
        else
        {
            cout<<"二叉树为空，无法遍历"<<endl;
        }
    }
    //后序遍历
    void PostOrder()
    {
        if(this->root!=nullptr)
        {
            this->root->postOrder();
        }
        else
        {
            cout<<"二叉树为空，无法遍历"<<endl;
        }
    }
    //前序查找
    HeroNode* PreOrderSearch(int no)
    {
        if(this->root!=nullptr)
        {
            return this->root->preOrderSearch(no);
        }
        else
        {
            cout<<"二叉树为空，无法遍历"<<endl;
            return nullptr;
        }
    }
    //中序查找
    HeroNode* InOrderSearch(int no)
    {
        if(this->root!=nullptr)
        {
            return this->root->inOrderSearch(no);
        }
        else
        {
            cout<<"二叉树为空，无法遍历"<<endl;
            return nullptr;
        }
    }
    //后序查找
    HeroNode* PostOrderSearch(int no)
    {
        if(this->root!=nullptr)
        {
            return this->root->postOrderSearch(no);
        }
        else
        {
            cout<<"二叉树为空，无法遍历"<<endl;
            return nullptr;
        }
    }
    //删除结点方法
    void DelNode(int no)
    {
        if(root==nullptr)
        {
            cout<<"该树为空树无法删除"<<endl;
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
    HeroNode*node1=new HeroNode(1,"宋江");
    HeroNode*node2=new HeroNode(2,"林冲");
    HeroNode*node3=new HeroNode(3,"吴用");
    HeroNode*node4=new HeroNode(4,"卢俊义");
    HeroNode*node5=new HeroNode(5,"关胜");
    node1->left=node2;
    node1->right=node3;
    node3->left=node5;
    node3->right=node4;
    BinaryTree BST;
    BST.root=node1;
    // cout<<"前序遍历结果"<<endl;
    // BST.PreOrder();
    // cout<<"中序遍历结果"<<endl;
    // BST.InOrder();
    // cout<<"后序遍历结果"<<endl;
    // BST.PostOrder();
    
    //前序遍历
    // cout<<"前序遍历方式"<<endl;
    // HeroNode* res=BST.PreOrderSearch(5);
    // if(res!=nullptr)
    // {
    //     cout<<"已找到节点，信息为no="<<res->m_num<<" name="<<res->m_name<<endl;
    // }else
    // {
    //     cout<<"没有找到"<<endl;
    // }
    // cout<<"中序遍历方式"<<endl;
    // HeroNode* res1=BST.InOrderSearch(3);
    // if(res1!=nullptr)
    // {
    //     cout<<"已找到节点，信息为no="<<res1->m_num<<" name="<<res1->m_name<<endl;
    // }else
    // {
    //     cout<<"没有找到"<<endl;
    // }
    // cout<<"后序遍历方式"<<endl;
    // HeroNode* res2=BST.PostOrderSearch(5);
    // if(res2!=nullptr)
    // {
    //     cout<<"已找到节点，信息为no="<<res2->m_num<<" name="<<res2->m_name<<endl;
    // }else
    // {
    //     cout<<"没有找到"<<endl;
    // }
    cout<<"删除前，前序遍历"<<endl;
    BST.PreOrder();
    BST.DelNode(3);
    cout<<"删除后，前序遍历"<<endl;
    BST.PreOrder();
    system("pause");
    return 0;
}