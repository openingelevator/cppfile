#include<iostream>
#include<vector>
using namespace std;
void swap(int&a, int& b){
    int temp=a;
    a=b;
    b=temp;
}
void rotate(vector<vector<int>>& matrix) {
    int row=matrix.size();
    int col=matrix[0].size();
    if(row==1&&col==1){return;}
    //先进行转置操作
    for(int i=0;i<row;i++){
        for(int j=i;j<col;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //再进行左右对称操作
    for(int i=0;i<row;i++){
        for(int j=0;j<col/2;j++){
            if(j!=col-j)
            swap(matrix[i][j],matrix[i][col-1-j]);
        }
    }
}
int main()
{
    vector<vector<int>>matrix{{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    int row=matrix.size();
    int col=matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}