#include<iostream>
#include"OpenHashMap.hpp"
using namespace std;
int main(){
    int arr[10]={6 ,66, 87, 34, 86, 26, 13, 95, 0, 63};
    // int arr[20]={6 ,66, 87, 34, 86, 26, 13, 95, 0, 63, 74, 31, 24, 90, 20, 14, 49, 18, 51, 89};
    // int arr[7]={4371, 1323, 6173, 4199, 4344, 9679, 1989};
    HashTable<int>ht;
    for(int i=0;i<10;++i){
        ht.insert(arr[i]);
    }
    ht.printInfo();
    cout<<ht.collisionTimes()<<endl;
    system("pause");
    return 0;
}