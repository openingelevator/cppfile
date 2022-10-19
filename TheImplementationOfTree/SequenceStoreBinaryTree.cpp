#include<iostream>
#include<vector>
using namespace std;
//顺序存储二叉树通常只考虑完全二叉树
//第n个元素的左子结点为2*n+1
//第n个元素的右子结点为2*n+2
//第n个元素的父结点为(n-1)/2

//编写一个ArrayBinaryTree实现顺序存储二叉树遍历
class ArrayBinaryTree
{
public:
    ArrayBinaryTree(vector<int> arr)
    {
        this->arrTree=arr;
    }

    void preOrder(int index)
    {
        //如果数组为空
        if(arrTree.size()==0)
        {
            cout<<"数组为空，不能按照二叉树前序遍历\n";
            return;
        }
        // if(index<0||index>=arrTree.size())
        // {
        //     cout<<"输入下标不合法\n";
        //     return;
        // }
        //输出当前元素
        cout<<this->arrTree[index]<<" ";
        //向左递归
        if(index*2+1<this->arrTree.size())
        {
            preOrder(2*index+1);
        }
        //向右递归
        if(index*2+2<this->arrTree.size())
        {
            preOrder(2*index+2);
        }
    }

    void inOrder(int index)
    {
        //如果数组为空
        if(arrTree.size()==0)
        {
            cout<<"数组为空，不能按照二叉树中序遍历\n";
            return;
        }
        //向左递归
        if(index*2+1<this->arrTree.size())
        {
            inOrder(2*index+1);
        }
        //输出当前结点的值
        cout<<this->arrTree[index]<<" ";
        //向右递归
        if(index*2+2<this->arrTree.size())
        {
            inOrder(2*index+2);
        }
    }

private:
    vector<int>arrTree;
};
int main()
{
    vector<int>arr{1,2,3,4,5,6,7};
    ArrayBinaryTree* ABT=new ArrayBinaryTree(arr);
    ABT->preOrder(0);
    cout<<endl;
    ABT->inOrder(0);
    system("pause");
    return 0;
}

