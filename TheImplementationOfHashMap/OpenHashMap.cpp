#include<iostream>
#include<vector>
#include"OpenHashMap.hpp"
using namespace std;
int main(){
    int arr[6]={20,16,24,5,3,22};
    HashTable<int>ht;
    for(int i=0;i<6;++i){
        ht.insert(arr[i]);
    }
    ht.printInfo();
    cout<<ht.probeTimes()<<endl;
    system("pause");
    return 0;
}