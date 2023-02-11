#include<iostream>
#include<vector>
#include"GraphClass.h"
using namespace std;
// 算法过程
// 设置出发顶点为v，顶点集合为V{v1,v2,vi...}，v到V中个顶点的距离构成距离集合Dis
// Dis{d1,d2,di...}，Dis集合记录着v到图中各顶点的距离（v到vi的距离记为di）
// 1.从Dis中选择值最小的di并移出Dis集合，同时移出V集合中对应的顶点vi，此时v到vi即为最短路径
// 2.更新Dis集合，比较v到V集合中顶点的距离值，与v通过vi到V集合中顶点的距离值，保留值较小的一个
// 3.重复执行两步骤，直到最短路径顶点为目标顶点即可结束
void creatGraph(Graph&graph,int numOfVertex,char* data,int**weight){
    for(int i=0;i<numOfVertex;++i){
        graph.insertVertex(data[i]);
        for(int j=i+1;j<numOfVertex;++j){
            graph.insertEdge(i,j,weight[i][j]);
            }
        }
}

void Dijkstra(int index,Graph& graph){
    graph.setStart(index);
    graph.update(index);
    for(int j=1;j<graph.getNumOfVertex();j++){
        index=graph.updateArr();
        graph.update(index);
    }
}

int main(){
    Graph graph(7);
    char data[7]={'A','B','C','D','E','F','G'};
    char*ptr1=data;
    //大数表示两点不连通
    int weight[7][7]=
    {{INF,5,7,INF,INF,INF,2},
    {5,INF,INF,9,INF,INF,3},
    {7,INF,INF,INF,8,INF,INF},
    {INF,9,INF,INF,INF,4,INF},
    {INF,INF,8,INF,INF,5,4},
    {INF,INF,INF,4,5,INF,6},
    {2,3,INF,INF,4,6,INF}};
    int**ptr2=new int*[7];
    for(int i=0;i<7;++i){
        *(ptr2+i)=new int[7];
    }
    for(int i=0;i<7;++i){
        for(int j=0;j<7;++j){
            ptr2[i][j]=weight[i][j];
        }
    }
    creatGraph(graph,7,ptr1,ptr2);
    graph.printGraph();
    Dijkstra(6,graph);
    graph.printList();
    system("pause");
    return 0;
}