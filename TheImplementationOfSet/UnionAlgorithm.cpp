#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
public:
    explicit DisjointSet(int numOfElements):s(numOfElements){
        fill(s.begin(),s.end(),-1);
    }
    int find(int x)const{
        if(s[x]<0){
            return x;
        }else{
            return find(s[x]);
        }
    }
    //随机求并
    void unionSetArbitrarily(int root1,int root2){
        s[root2]=root1;
    }
    //按高度求并
    void unionSetByHeight(int root1,int root2){
        root1=find(root1);
        root2=find(root2);
        //root2更深
        if(s[root2]<s[root1]){
            s[root1]=root2;
        }else{
            if(s[root2]==s[root1]){
                --s[root1];
            }
            s[root2]=root1;
        }
    }
    //按大小求并
    void unionSetBySize(int root1,int root2){
        root1=find(root1);
        root2=find(root2);
        //root2的大小更大
        if(s[root2]<s[root1]){
            s[root2]+=s[root1];
            s[root1]=root2;
        }else{
            s[root1]+=s[root2];
            s[root2]=root1;
        }
    }
    void printInfo(){
        for(int i=0;i<s.size();++i){
            cout<<"s["<<i<<"]="<<s[i]<<" ";
        }
        cout<<endl;
    }
private:
    vector<int>s;
};
int main(){
    DisjointSet ds1(17);
    ds1.unionSetBySize(1,2);
    ds1.unionSetBySize(3,4);
    ds1.unionSetBySize(3,5);
    ds1.unionSetBySize(1,7);
    ds1.unionSetBySize(3,6);
    ds1.unionSetBySize(8,9);
    ds1.unionSetBySize(1,8);
    ds1.unionSetBySize(3,10);
    ds1.unionSetBySize(3,11);
    ds1.unionSetBySize(3,12);
    ds1.unionSetBySize(3,13);
    ds1.unionSetBySize(14,15);
    ds1.unionSetBySize(16,0);
    ds1.unionSetBySize(14,16);
    ds1.unionSetBySize(1,3);
    ds1.unionSetBySize(1,14);

    // ds1.unionSetBySize(4,5);
    // ds1.unionSetBySize(6,7);
    // ds1.unionSetBySize(4,6);
    // ds1.unionSetBySize(3,4);
    
    ds1.printInfo();

    system("pause");
    return 0;
}