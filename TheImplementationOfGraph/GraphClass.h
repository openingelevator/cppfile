#include<iostream>
#include<vector>
using namespace std;
const int INF=10000;
class Graph{
private:
    vector<char>vertexList;//�洢���㼯�� 
    vector<bool>isVisited;//�洢����Ƿ񱻷��ʵı�־
    vector<vector<int>>edges;
    vector<int>pre_visited;//ÿ���±��Ӧ��ֵΪǰһ������±�
    vector<int>dis;//��¼�������㵽�������ж������̾���
    int numOfEdges=0;
    int startIndex=0;//���������±�

public:
    Graph(int numOfVertex){
        //��ʼ��������vertexList
        this->edges=vector<vector<int>>(numOfVertex,vector<int>(numOfVertex,0));
        //��ʼ��isVisited
        this->isVisited.resize(numOfVertex);
        fill(this->isVisited.begin(),this->isVisited.end(),false);
        //��ʼ��pre_visited
        this->pre_visited.resize(numOfVertex);
        fill(this->pre_visited.begin(),this->pre_visited.end(),0);
        //��ʼ����������
        this->dis.resize(numOfVertex);
        fill(this->dis.begin(),this->dis.end(),INF);
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
    //�Զ�����з��ʲ���
    void visit(int index){
        this->isVisited[index]=true;
    }
    //�ж϶����Ƿ񱻷��ʹ�
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
        if(weight!=INF){
            this->numOfEdges++;
        }
    }
    //���³������㵽index����ľ���
    void updateDis(int index,int len){
        this->dis[index]=len;
    }
    //����index��������ǰ������Ϊpre
    void updatePre(int index,int pre){
        this->pre_visited[index]=pre;
    }
    //���س������㵽index����ľ���
    int getDis(int index){
        return this->dis[index];
    }
    //���ó��������±�
    void setStart(int index){
        this->startIndex=index;
        this->dis[this->startIndex]=0;
    }
    //����index�±궥�㵽��Χ����ľ������Χ�����ǰ������
    void update(int index){
        int len=0;
        this->visit(index);
        for(int j=0;j<this->vertexList.size();j++){
            //lenΪ�������㵽index����ľ���+��index���㵽j����ľ���
            len=this->getDis(index)+edges[index][j];
            if(!beVisited(j)&&len<getDis(j)){
                updateDis(j,len);
                updatePre(j,index);
            }
        }
    }
    //����ѡ�񲢷����µķ��ʶ���
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
        cout<<"ͼ���ڽӾ�������"<<endl;
        for(auto i:this->edges){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        cout<<"ͼ�Ķ�����������"<<":";
        for(auto i:this->vertexList){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void printList(){
        cout<<"ͼ����ʼ����Ϊ:"<<this->vertexList[this->startIndex];
        cout<<endl;
        cout<<"is_visited����:";
        for(auto i:this->isVisited){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"pre_visited����:";
        for(auto i:this->pre_visited){
        cout<<i<<" ";
        }
        cout<<endl;
        cout<<"dis����:";
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
    //���ؽ��i��Ӧ������
    char getValue(int index){
        return this->vertexList[index];
    }
    //����v1,v2λ�õ�Ȩֵ
    int getWeight(int v1,int v2){
        return this->edges[v1][v2];
    }
};