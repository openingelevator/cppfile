/*
 * @Author: ֣᷷� 
 * @Date: 2022-10-27 20:39:25 
 * @StudentId:202130462264
 * @Last Modified by:   ֣᷷� 
 * @Last Modified time: 2022-10-27 20:39:25 
 */
#pragma once
#include<vector>
#include<cmath>
using namespace std;
//�ж�һ�����Ƿ�Ϊ����
bool isPrime(int val){
    int flag=true;
    for(int i=2;i<sqrt(val)+1;i+=1){
        if(val%i==0){
            flag=false;
        }
    }
    return flag;
}
//Ѱ��ĳ����������һ������
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
    //���캯������ʼ������Ĵ�СΪ����
    explicit HashTable(int size=61):array(nextPrime(size)){
        prime=size;
        //��ʼ��װ������Ϊ0
        this->loadFactor=0;
        //��ʼ������״̬Ϊ��
        this->makeEmpty();
    }
    //�ж�Ԫ���Ƿ��ڹ�ϣ����
    bool contains(const HashObj&element)const{
        return isActive(findPos(element));
    }
    //����ϣ���в۵�״̬��Ϊ��
    void makeEmpty(){
        this->currentSize=0;
        for(auto&i:this->array){
            i.state=EMPTY;
        }
    }
    //���뺯��
    bool insert(const HashObj&element){
        //����Ԫ��ӳ���Ļ�׼λ��
        int currentPos=findPos(element,true);
        //�жϸ�λ���Ƿ�Ϊ�ɲ����״̬
        if(isActive(currentPos)){
            return false;
        }
        array[currentPos].element=element;
        array[currentPos].state=ACTIVE;
        //����װ�����ӣ���װ�����Ӵ���0.5������ٹ�ϣ����
        loadFactor=++currentSize/array.size();
        if(loadFactor>=0.5){
            rehash();
        }
        return true;
    }
    //ɾ������
    bool remove(const HashObj&element){
        int currentPos=findPos(element);
        if(!isActive(currentPos)){
            return false;
        }
        //��ɾ�������۵�״̬��Ϊɾ��״̬
        array[currentPos].state=DELETED;
        return true;
    }
    //�����ͻ����
    int collisionTimes()const{
        int sum=0;
        //������ϣ����ÿ��λ�õĳ�ͻ�����ۼ�
        for(auto i:array){
            if(i.state==ACTIVE){
                sum+=i.collisionTimes;
            }
        }
        return sum;
    }
    //ö�����ͣ�ö�ٲ۵�״̬
    enum stateType{
        ACTIVE,
        EMPTY,
        DELETED
    };
    //��ӡ���Թ�ϣ��
    void printInfo()const{
        for(int i=0;i<array.size();++i){
            if(array[i].state==ACTIVE){
            cout<<"HashTable["<<i<<"]="<<array[i].element<<"  collisionTimes="<<array[i].collisionTimes<<endl;
            }
        }
    }
    //���ص�ǰ��ϣ���ʵ�ʴ�С
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
    int prime;

    //�жϹ�ϣ���в۵�״̬�Ƿ��Ծ
    bool isActive(int currentPos)const{
        if(currentPos>0&&currentPos<array.size()){
           return array[currentPos].state==ACTIVE;
        }else{
            return false;
        }
    }
    //Ѱ�ҹؼ���ӳ����ڱ��е�ʵ��λ��
    int findPos(const HashObj&x,int flag=false){
        // int offset=-1;
        int currentPos=myHash(x);
        //��¼̽�����
        int count=0;
        // int bias=doubleHash(x);
        while(array[currentPos].state!=EMPTY
        &&array[currentPos].element!=x){
            // currentPos+=linearProbe(offset);
            // currentPos+=quadraticProbe(offset);
            int size=array.size();
            currentPos+=pseudoRamdomProbe(size);
            currentPos+=bias;

            if(currentPos>=array.size()){
                currentPos-=array.size();
            }
            count++;
             //����ͻ�������࣬������ô�̽��
            if(count>array.size()){
                currentPos=-1;
                break;
            }
        }
        if(flag==true&&currentPos!=-1){
          array[currentPos].collisionTimes=count;
        }
        return currentPos;
    }
    //����̽��
    int linearProbe(int&offset){
        return offset;
    }
    //ƽ��̽��
    int quadraticProbe(int&offset){
          offset+=2;
          return offset;
    }
    //α���̽��
    int pseudoRamdomProbe(int size){
        return rand()%size;
    }
    //˫ɢ��̽��
    size_t doubleHash(const HashObj&x){
        //��ֹx�����ڶ���ɢ�к���ӳ����ֵΪ0����������̽������Ϊ0�����
        return x%prime+1;
    }
    //�ٹ�ϣ
    void rehash(){
        //������ʱ�������ԭ�����е�����
        vector<HashEntry>temp=array;
        //��ԭ�����������������
        array.resize(2*array.size());
        //���ԭ�����е�����
        for(auto& i:array){
            array.clear();
        }
        currentSize=0;
        //����ʱ�����е����ݲ��뵽�±���
        for(auto&i:temp){
            insert(i.element);
        }
    }

    size_t myHash(const HashObj&x)const{
        return x%(array.size());
    }
};

