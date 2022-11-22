#include<iostream>
#include<vector>
#include"GraphClass.h"
using namespace std;
//������ȱ����ӳ�ʼ���ʽ���������ʼ���ʽ������ж���ڽӽ�㣬������ȱ����Ĳ��������ȷ��ʵ�һ���ڽӽ��
//Ȼ��������������ʵ��ڽӽ����λ��ʼ��㣬�������ĵ�һ���ڽӽ�㣬֮���ٵݹ��ִ����ȥ
void depthFirstSearch(Graph&graph,int v0){
    //��һ������ʱ�����ʸý��
    cout<<graph.getValue(v0)<<"->";
    //�����ʹ��Ľ����Ϊ�ѷ���
    graph.visit(v0);
    int v1=graph.getFirstAdjacentVertexIndex(v0);
    while(v1!=-1){
        if(!graph.beVisited(v1)){
            depthFirstSearch(graph,v1);
        }
        //���v1���������Ѿ������ʹ�
        v1=graph.getNextAdjacentVertexIndex(v0,v1);
    }
}
//��dfs�������أ���Ҫ�������еĽ��
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
