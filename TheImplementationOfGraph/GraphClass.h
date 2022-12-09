#include<iostream>
#include<vector>
using namespace std;
class Graph{
private:
    vector<char>vertexList;//存储顶点集合 
    vector<bool>isVisited;//存储结点是否被访问的标志
    vector<vector<int>>edges;
    int numOfEdges;

public:
    Graph(int numOfVertex){
        //初始化矩阵与vertexList
        this->edges=vector<vector<int>>(numOfVertex,vector<int>(numOfVertex,0));
        // this->vertexList=vector<char>(numOfVertex);
        isVisited.resize(numOfVertex);
        fill(isVisited.begin(),isVisited.end(),false);
        this->numOfEdges=0;
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
    void visit(int index){
        this->isVisited[index]=true;
    }
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
        if(weight!=10000){
            this->numOfEdges++;
        }
    }
    void printGraph(){
        cout<<"图的邻接矩阵如下"<<endl;
        for(auto i:edges){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        for(auto i:this->vertexList){
            cout<<i<<" ";
        }
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