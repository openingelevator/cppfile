#include<iostream>
#include<vector>
using namespace std;
class MaxHeap{
public:
    MaxHeap(vector<int>arr):m_size(arr.size()-1),m_arr(arr){
        buildHeap();
    }
    //大顶堆的结点往下沉
    void percolateDown(int index,int val){
        if(2*index>m_size){
            m_arr.at(index)=val;
            return;
        }else if(2*index==m_size){
            if(m_arr.at(2*index)>val){
                m_arr.at(index)=m_arr.at(2*index);
                m_arr.at(2*index);
            }
        }else{
            int j=0;
            if(m_arr.at(2*index)>m_arr.at(2*index+1)){
                j=2*index;
            }else{
                j=2*index+1;
            }
            if(m_arr.at(j)>val){
                m_arr.at(index)=m_arr.at(j);
                percolateDown(j,val);
            }else{
                m_arr.at(index)=val;
            }
        }
    }
    void percolateUp(int index,int val){
        if(m_arr.at(index/2)>val){
            m_arr.at(index)=val;
        }else{
            m_arr.at(index)=m_arr.at(index/2);
            percolateUp(index/2,val);
        }

    }
    void insertVal(int val){
       m_arr.push_back(val);
       m_size++;
       percolateUp(m_size,val); 
    }
    void deleteMax(){
        m_arr.at(0)=m_arr.at(m_size);
        m_arr.pop_back();
        m_size--;
        percolateDown(0,m_arr.at(0));
    }
    void buildHeap(){
        for(int i=m_size/2;i>=1;i--){
            percolateDown(i,m_arr.at(i));
        }
    }
    void printInfo(){
        for(int i=1;i<=m_size;i++){
            cout<<m_arr.at(i)<<" ";
        }
    }
private:
    int m_size;
    vector<int>m_arr;
};
int main(){
    vector<int>arr{-1,4,2,5,7,9,6,1};
    MaxHeap heap(arr);
    //heap.insert(8);
    heap.deleteMax();
    heap.deleteMax();
    heap.printInfo();
    system("pause");
    return 0;
}