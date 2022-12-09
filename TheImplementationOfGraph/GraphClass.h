#include<iostream>
#include<vector>
using namespace std;
class Graph{
private:
    vector<char>vertexList;//�洢���㼯�� 
    vector<bool>isVisited;//�洢����Ƿ񱻷��ʵı�־
    vector<vector<int>>edges;
    int numOfEdges;

public:
    Graph(int numOfVertex){
        //��ʼ��������vertexList
        this->edges=vector<vector<int>>(numOfVertex,vector<int>(numOfVertex,0));
        // this->vertexList=vector<char>(numOfVertex);
        isVisited.resize(numOfVertex);
        fill(isVisited.begin(),isVisited.end(),false);
        this->numOfEdges=0;
    }
    //����ǰһ���ڽӽ����±��ȡ��һ���ڽӽ��
    int getNextAdjacentVertexIndex(int v1,int v2){
        for(int i=v2+1;i<this->vertexList.size();++i){
            if(edges[v1][i]>0){
                return i;
            }
        }
        return -1;
    }
    //�õ�ĳ������һ���ڽӽ����±�
    int getFirstAdjacentVertexIndex(int index){
        for(int i=0;i<this->vertexList.size();++i){
            //������ڷ��ض�Ӧ�±���򷵻�-1
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
    //������
    void insertVertex(char vertex){
        this->vertexList.push_back(vertex);
    }
    //��ӱ�
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
        cout<<"ͼ���ڽӾ�������"<<endl;
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
    //���ؽ��i��Ӧ������
    char getValue(int index){
        return this->vertexList[index];
    }
    //����v1,v2λ�õ�Ȩֵ
    int getWeight(int v1,int v2){
        return this->edges[v1][v2];
    }
};