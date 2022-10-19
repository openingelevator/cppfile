#include<iostream>
#include<vector>
using namespace std;
//˳��洢������ͨ��ֻ������ȫ������
//��n��Ԫ�ص����ӽ��Ϊ2*n+1
//��n��Ԫ�ص����ӽ��Ϊ2*n+2
//��n��Ԫ�صĸ����Ϊ(n-1)/2

//��дһ��ArrayBinaryTreeʵ��˳��洢����������
class ArrayBinaryTree
{
public:
    ArrayBinaryTree(vector<int> arr)
    {
        this->arrTree=arr;
    }

    void preOrder(int index)
    {
        //�������Ϊ��
        if(arrTree.size()==0)
        {
            cout<<"����Ϊ�գ����ܰ��ն�����ǰ�����\n";
            return;
        }
        // if(index<0||index>=arrTree.size())
        // {
        //     cout<<"�����±겻�Ϸ�\n";
        //     return;
        // }
        //�����ǰԪ��
        cout<<this->arrTree[index]<<" ";
        //����ݹ�
        if(index*2+1<this->arrTree.size())
        {
            preOrder(2*index+1);
        }
        //���ҵݹ�
        if(index*2+2<this->arrTree.size())
        {
            preOrder(2*index+2);
        }
    }

    void inOrder(int index)
    {
        //�������Ϊ��
        if(arrTree.size()==0)
        {
            cout<<"����Ϊ�գ����ܰ��ն������������\n";
            return;
        }
        //����ݹ�
        if(index*2+1<this->arrTree.size())
        {
            inOrder(2*index+1);
        }
        //�����ǰ����ֵ
        cout<<this->arrTree[index]<<" ";
        //���ҵݹ�
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

