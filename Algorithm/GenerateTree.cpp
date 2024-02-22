#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0)return nullptr;
        int rootValue=postorder[postorder.size()-1];
        TreeNode*root=new TreeNode(rootValue);
        if(postorder.size()==1)return root;

        // 找分割点
        int delimiterIndex;
        for(delimiterIndex=0;delimiterIndex<inorder.size();delimiterIndex++){
            if(inorder[delimiterIndex]==rootValue)break;
        }

        // 分割中序数组
        vector<int>leftInorder(inorder.begin(),inorder.begin()+delimiterIndex);
        vector<int>rightInorder(inorder.begin()+delimiterIndex+1,inorder.end());

        // 分割后序数组
        // 舍弃末尾元素
        postorder.resize(postorder.size()-1);
        vector<int>leftPostorder(postorder.begin(),postorder.begin()+delimiterIndex);
        vector<int>rightPostorder(postorder.begin()+delimiterIndex,postorder.end());

        cout<<"-------------"<<endl;
        cout << "leftInorder :";
        for (int i : leftInorder) {
            cout << i << " ";
        }
        cout << endl;

        cout << "rightInorder :";
        for (int i : rightInorder) {
            cout << i << " ";
        }
        cout << endl;

        cout << "leftPostorder :";
        for (int i : leftPostorder) {
            cout << i << " ";
        }
        cout << endl;
         cout << "rightPostorder :";
        for (int i : rightPostorder) {
            cout << i << " ";
        }
        cout << endl;
        
        root->left=buildTree(leftInorder,leftPostorder);
        root->right=buildTree(rightInorder,rightPostorder);

        return root;
    }
};
int main(){
  vector<int>inorder={9,3,15,20,7};
  vector<int>postorder={9,15,7,20,3};
  Solution s;
  s.buildTree(inorder,postorder);
  system("pause");
  return 0;
}