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
    //��ѭ�������������Ѿ�����iΪ�������������ֵ�����˶Ѷ���
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
        for(auto i:arr){
        cout<<i<<",";
    }
    cout<<endl;
    }

}
int main(){
    vector<int>arr{142, 543, 123, 65, 453, 879, 572, 434, 111, 242, 811, 102};
    heapSort(arr);
    // for(auto i:arr){
    //     cout<<i<<" ";
    // }
    system("pause");
    return 0;
}
