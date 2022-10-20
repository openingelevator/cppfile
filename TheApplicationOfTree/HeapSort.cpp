#include<iostream>
#include<vector>
using namespace std;
//arr待调整的数组，i表示非叶子结点在数组中的索引，length表示对多少个元素继续调整
void adjustHeap(vector<int>&arr,int i,int length){
    int temp=arr[i];//先取出当前元素的值保存在临时变量
    //开始调整
    for(int k=i*2+1;k<length;k=k*2+1){
        if(k+1<length){
            //说明左子结点的值小于右子结点的值
            if(arr[k]<arr[k+1])
            k++;
        }
        if(arr[k]>temp){//如果子结点大于父结点
            arr[i]=arr[k];
            i=k;
        }else{
            break;
        }
    }
    //当循环结束后，我们已经将以i为父结点的树的最大值放在了最顶上
    arr[i]=temp;
}
void swap(int&a, int&b){
    int temp=a;
    a=b;
    b=temp;
}
void heapSort(vector<int>&arr){
    //构建大顶堆
    for(int i=arr.size()/2;i>=0;i--){
        adjustHeap(arr,i,arr.size());
    }
    for(int j=arr.size()-1;j>0;j--){
        //交换
        swap(arr[0],arr[j]);
        adjustHeap(arr,0,j);
    }

}
int main(){
    vector<int>arr{9,6,5,8,4,7};
    heapSort(arr);
    for(auto i:arr){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}
