#pragma once
#include<vector>
#include<cmath>
using namespace std;
//判断一个数是否为素数
bool isPrime(int val){
    int flag=true;
    for(int i=2;i<sqrt(val)+1;++i){
        if(val%i==0){
            flag=false;
        }
    }
    return flag;
}
//寻找某个素数的下一个素数
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
    //构造函数，初始化数组的大小为素数
    explicit HashTable(int size=17):array(nextPrime(size)){
        //初始化装填因子为0
        this->loadFactor=0;
        //初始化数组状态为空
        this->makeEmpty();
    }
    //判断元素是否在哈希表中
    bool contains(const HashObj&element)const{
        return isActive(findPos(element));
    }
    //将哈希表中槽的状态置为空
    void makeEmpty(){
        this->currentSize=0;
        for(auto&i:this->array){
            i.state=EMPTY;
        }
    }
    //插入函数
    bool insert(const HashObj&element){
        //查找元素映射后的基准位置
        int currentPos=findPos(element,true);
        //判断该位置是否为可插入的状态
        if(isActive(currentPos)){
            return false;
        }
        array[currentPos].element=element;
        array[currentPos].state=ACTIVE;
        //更新装填因子，若装填因子大于0.5则进行再哈希操作
        loadFactor=++currentSize/array.size();
        if(loadFactor>=0.5){
            rehash();
        }
        return true;
    }
    //删除操作
    bool remove(const HashObj&element){
        int currentPos=findPos(element);
        if(!isActive(currentPos)){
            return false;
        }
        //懒删除，将槽的状态置为删除状态
        array[currentPos].state=DELETED;
        return true;
    }
    //计算冲突次数
    int collisionTimes()const{
        int sum=0;
        //遍历哈希表，将每个位置的冲突次数累加
        for(auto i:array){
            if(i.state==ACTIVE){
                sum+=i.collisionTimes;
            }
        }
        return sum;
    }
    //枚举类型，枚举槽的状态
    enum stateType{
        ACTIVE,
        EMPTY,
        DELETED
    };
    //打印测试哈希表
    void printInfo()const{
        for(int i=0;i<array.size();++i){
            if(array[i].state==ACTIVE){
            cout<<"HashTable["<<i<<"]="<<array[i].element<<endl;
            }
        }
    }
    //返回当前哈希表的实际大小
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
    int loadFactor;
    int prime=nextPrime(array.size());

    //判断哈希表中槽的状态是否活跃
    bool isActive(int currentPos)const{
        if(currentPos>0&&currentPos<array.size()){
           return array[currentPos].state==ACTIVE;
        }else{
            return false;
        }
    }
    //寻找关键码映射后在表中的实际位置
    int findPos(const HashObj&x,int flag=false){
        int offset=1;
        int currentPos=myHash(x);
        //记录探测次数
        int count=0;
        while(array[currentPos].state!=EMPTY&&
        array[currentPos].element!=x){
            // currentPos+=linearProbe(offset);
            currentPos+=quaraticProbe(offset);

            if(currentPos>=array.size()){
                currentPos-=array.size();
            }
            if(flag==true){
                array[currentPos].collisionTimes++;
            }
            //若冲突次数过多，则结束该次探测
            count++;
            if(count>array.size()){
                return -1;
            }
        }
        return currentPos;
    }
    //线性探测
    int linearProbe(int&offset){
        return offset;
    }
    //平方探测
    int quaraticProbe(int&offset){
        offset+=2;
        return offset;
    }
    //伪随机探测
    int pseudoRamdomProbe(){
        int size=array.size();
        return rand()%size;
    }
    //双散列探测
    size_t doubleHash(const HashObj&x){
        return x%prime;
    }
    //再哈希
    void rehash(){
        //创建临时容器存放原来表中的数据
        vector<HashEntry>temp=array;
        //将原来表的容量扩大两倍
        array.resize(2*array.size());
        //清除原来表中的内容
        for(auto& i:array){
            array.clear();
        }
        currentSize=0;
        //将临时容器中的数据插入到新表中
        for(auto&i:temp){
            insert(i.element);
        }
    }

    size_t myHash(const HashObj&x)const{
        return x%(array.size());
    }
};

