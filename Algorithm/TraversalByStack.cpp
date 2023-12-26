#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int>inorderTraversal(TreeNode*root){
   vector<int>res;
   stack<TreeNode*>st;
   if(root!=nullptr)st.push(root);
   while(!st.empty()){
      TreeNode*node=st.top();
      if(node!=nullptr){
        st.pop();// �˲����ڵ㵯���������ظ�����
        if(node->right!=nullptr)st.push(node->right);

        st.push(node);
        st.push(nullptr);// ��ָ����Ϊ��ǣ�ָʾ�����ʹ���δ������������нڵ�

        if(node->left!=nullptr)st.push(node->left);
      }else{
        st.pop();
        int val=st.top()->val;
        res.push_back(val);
        st.pop();
      }
   }
   return res;
}

int main(){
  vector<int>res;
  TreeNode*root=new TreeNode(5);
  TreeNode*node1=new TreeNode(4);
  TreeNode*node2=new TreeNode(6);
  TreeNode*node3=new TreeNode(1);
  TreeNode*node4=new TreeNode(2);
  root->left=node1;
  root->right=node2;
  node1->left=node3;
  node1->right=node4;
  res=inorderTraversal(root);
  for(auto i:res){
    cout<<i<<" ";
  }
  system("pause");
  return 0;
}