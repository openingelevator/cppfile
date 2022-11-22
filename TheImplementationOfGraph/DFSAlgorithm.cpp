#include<iostream>
#include<vector>
#include"GraphClass.h"
using namespace std;
//深度优先遍历从初始访问结点出发，初始访问结点可能有多个邻接结点，深度优先遍历的策略是首先访问第一个邻接结点
//然后再以这个被访问的邻接结点座位初始结点，访问它的第一个邻接结点，之后再递归地执行下去
void depthFirstSearch(Graph&graph,int v0){
    //第一次搜索时，访问该结点
    cout<<graph.getValue(v0)<<"->";
    //将访问过的结点置为已访问
    graph.visit(v0);
    int v1=graph.getFirstAdjacentVertexIndex(v0);
    while(v1!=-1){
        if(!graph.beVisited(v1)){
            depthFirstSearch(graph,v1);
        }
        //如果v1结点存在且已经被访问过
        v1=graph.getNextAdjacentVertexIndex(v0,v1);
    }
}
//对dfs进行重载，需要遍历所有的结点
// void depthFirstSearch(Graph&graph){
//     for(int i=0;i<graph.getNumOfVertex();++i){
//         if(!graph.beVisited(i)){
//             depthFirstSearch(graph,i);
//         }
//     }
// }
int main(){
    Graph graph(5);
    char vertex[5]={'A','B','C','D','E'};
    for(int i=0;i<5;++i){
        graph.insertVertex(vertex[i]);
    }
    graph.insertEdge(0,1,1);
    graph.insertEdge(0,2,1);
    graph.insertEdge(1,2,1);
    graph.insertEdge(1,3,1);
    graph.insertEdge(1,4,1);
    // graph.insertEdge(2,4,1);
    // graph.printGraph();

    depthFirstSearch(graph,1);
    system("pause");
    return 0;
}
