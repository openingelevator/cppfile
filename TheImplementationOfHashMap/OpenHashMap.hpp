#pragma once
#include<vector>
#include<cmath>
using namespace std;
bool isPrime(int val){
    int flag=true;
    for(int i=2;i<sqrt(val)+1;++i){
        if(val%i==0){
            flag=false;
        }
    }
    return flag;
}
int nextPrime(int prime){
    int nextPri;
    for(int i=prime+1;;++i){
        if(isPrime(i)){
            nextPri=i;
            break;
        }
    }
    return nextPri;
}
template<typename HashObj>
class HashTable{
public:
    explicit HashTable(int size=17):array(nextPrime(size)){
        this->makeEmpty();
    }

    bool contains(const HashObj&element)const{
        return isActive(findPos(element));
    }

    void makeEmpty(){
        this->currentSize=0;
        for(auto&i:this->array){
            i.state=EMPTY;
        }
    }

    bool insert(const HashObj&element){
        int currentPos=findPos(element,true);
        if(isActive(currentPos)){
            return false;
        }
        array[currentPos].element=element;
        array[currentPos].state=ACTIVE;

        if(++currentSize>array.size()/2){
            rehash();
        }
        return true;
    }
    bool remove(const HashObj&element){
        int currentPos=findPos(element);
        if(!isActive(currentPos)){
            return false;
        }
        array[currentPos].state=DELETED;
        return true;
    }
    int probeTimes()const{
        int sum=0;
        for(auto i:array){
            if(i.state==ACTIVE){
                sum+=i.collisionTimes;
            }
        }
        return sum;
    }
    enum stateType{
        ACTIVE,
        EMPTY,
        DELETED
    };
    void printInfo()const{
        for(int i=0;i<array.size();++i){
            if(array[i].state==ACTIVE){
            cout<<"HashTable["<<i<<"]="<<array[i].element<<endl;
            }
        }
    }
    int getCurrentSize()const{
        return currentSize;
    }
private:
    struct HashEntry{
        HashObj element;
        stateType state;
        int collisionTimes;
        HashEntry(const HashObj&e=HashObj{},stateType i=EMPTY)
        :element{e},state{i},collisionTimes(0){}
    };

    vector<HashEntry>array;
    int currentSize;

    bool isActive(int currentPos)const{
        if(currentPos>0&&currentPos<array.size()){
           return array[currentPos].state==ACTIVE;
        }else{
            return false;
        }
    }
    int count=0;
    int findPos(const HashObj&x,int flag=false){
        int offset=1;
        int currentPos=myHash(x);
        int count=0;
        while(array[currentPos].state!=EMPTY&&
        array[currentPos].element!=x){
            currentPos+=offset;//¼ÆËãµÚi´ÎÌ½²â
            offset++;
            if(currentPos>=array.size()){
                currentPos-=array.size();
            }
            if(flag==true){
                array[currentPos].collisionTimes++;
            }
            count++;
            if(count>array.size()){
                return -1;
            }
        }
        return currentPos;
    }
    void rehash(){
        vector<HashEntry>temp=array;
        array.resize(2*array.size());
        for(auto& i:array){
            array.clear();
        }
        currentSize=0;
        for(auto&i:temp){
            insert(i.element);
        }
    }
    size_t myHash(const HashObj&x)const{
        return x%(array.size());
    }
};

