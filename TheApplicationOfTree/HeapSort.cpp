#include<iostream>
#include<vector>
using namespace std;
//arr�����������飬i��ʾ��Ҷ�ӽ���������е�������length��ʾ�Զ��ٸ�Ԫ�ؼ�������
void adjustHeap(vector<int>&arr,int i,int length){
    int temp=arr[i];//��ȡ����ǰԪ�ص�ֵ��������ʱ����
    //��ʼ����
    for(int k=i*2+1;k<length;k=k*2+1){
        if(k+1<length){
            //˵�����ӽ���ֵС�����ӽ���ֵ
            if(arr[k]<arr[k+1])
            k++;
        }
        if(arr[k]>temp){//����ӽ����ڸ����
            arr[i]=arr[k];
            i=k;
        }else{
            break;
        }
    }
    //��ѭ�������������Ѿ�����iΪ�������������ֵ���������
    arr[i]=temp;
}
void swap(int&a, int&b){
    int temp=a;
    a=b;
    b=temp;
}
void heapSort(vector<int>&arr){
    //�����󶥶�
    for(int i=arr.size()/2;i>=0;i--){
        adjustHeap(arr,i,arr.size());
    }
    for(int j=arr.size()-1;j>0;j--){
        //����
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
