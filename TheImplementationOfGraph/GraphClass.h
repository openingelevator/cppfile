#include<iostream>
#include<vector>
using namespace std;
const int INF=10000;
class Graph{
private:
    vector<char>vertexList;//存储顶点集合 
    vector<bool>isVisited;//存储结点是否被访问的标志
    vector<vector<int>>edges;
    vector<int>pre_visited;//每个下标对应的值为前一个结点下标
    vector<int>dis;//记录出发顶点到其他所有顶点的最短距离
    int numOfEdges=0;
    int startIndex=0;//出发顶点下标

public:
    Graph(int numOfVertex){
        //初始化矩阵与vertexList
        this->edges=vector<vector<int>>(numOfVertex,vector<int>(numOfVertex,0));
        //初始化isVisited
        this->isVisited.resize(numOfVertex);
        fill(this->isVisited.begin(),this->isVisited.end(),false);
        //初始化pre_visited
        this->pre_visited.resize(numOfVertex);
        fill(this->pre_visited.begin(),this->pre_visited.end(),0);
        //初始化距离数组
        this->dis.resize(numOfVertex);
        fill(this->dis.begin(),this->dis.end(),INF);
    }
    //根据前一个邻接结点的下标获取下一个邻接结点
    int getNextAdjacentVertexIndex(int v1,int v2){
        for(int i=v2+1;i<this->vertexList.size();++i){
            if(edges[v1][i]>0){
                return i;
            }
        }
        return -1;
    }
    //得到某个结点第一个邻接结点的下标
    int getFirstAdjacentVertexIndex(int index){
        for(int i=0;i<this->vertexList.size();++i){
            //如果存在返回对应下标否则返回-1
            if(this->edges[index][i]>0){
                return i;
            }
        }
        return -1;
    }
    //对顶点进行访问操作
    void visit(int index){
        this->isVisited[index]=true;
    }
    //判断顶点是否被访问过
    bool beVisited(int index){
        return this->isVisited[index];
    }
    //插入结点
    void insertVertex(char vertex){
        this->vertexList.push_back(vertex);
    }
    //添加边
    void insertEdge(int v1,int v2,int weight,bool flag=true){
        if(flag){
        this->edges[v1][v2]=weight;
        this->edges[v2][v1]=weight;
        }else{
            this->edges[v1][v2]=weight;
        }
        if(weight!=INF){
            this->numOfEdges++;
        }
    }
    //更新出发顶点到index顶点的距离
    void updateDis(int index,int len){
        this->dis[index]=len;
    }
    //更新index这个顶点的前驱顶点为pre
    void updatePre(int index,int pre){
        this->pre_visited[index]=pre;
    }
    //返回出发顶点到index顶点的距离
    int getDis(int index){
        return this->dis[index];
    }
    //设置出发顶点下标
    void setStart(int index){
        this->startIndex=index;
        this->dis[this->startIndex]=0;
    }
    //更新index下标顶点到周围顶点的距离和周围顶点的前驱顶点
    void update(int index){
        int len=0;
        this->visit(index);
        for(int j=0;j<this->vertexList.size();j++){
            //len为出发顶点到index顶点的距离+从index顶点到j顶点的距离
            len=this->getDis(index)+edges[index][j];
            if(!beVisited(j)&&len<getDis(j)){
                updateDis(j,len);
                updatePre(j,index);
            }
        }
    }
    //继续选择并返回新的访问顶点
    int updateArr(){
        int min=INF,index=0;
        for(int i=0;i<this->isVisited.size();i++){
            if(this->isVisited[i]==0&&dis[i]<min){
                min=this->dis[i];
                index=i;
            }
        }
        return index;
    }
    void printGraph(){
        cout<<"图的邻接矩阵如下"<<endl;
        for(auto i:this->edges){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<"图的顶点数组如下"<<":";
        for(auto i:this->vertexList){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void printList(){
        cout<<"图的起始顶点为:"<<this->vertexList[this->startIndex];
        cout<<endl;
        cout<<"is_visited数组:";
        for(auto i:this->isVisited){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"pre_visited数组:";
        for(auto i:this->pre_visited){
        cout<<i<<" ";
        }
        cout<<endl;
        cout<<"dis数组:";
        for(int i=0;i<this->dis.size();i++){
            cout<<this->vertexList[i]<<"("<<this->dis[i]<<")";
        }
        cout<<endl;
    }
    int getNumOfVertex(){
        return this->vertexList.size();
    }
    int getNumOfEdges(){
        return this->numOfEdges;
    }
    //返回结点i对应的数据
    char getValue(int index){
        return this->vertexList[index];
    }
    //返回v1,v2位置的权值
    int getWeight(int v1,int v2){
        return this->edges[v1][v2];
    }
};