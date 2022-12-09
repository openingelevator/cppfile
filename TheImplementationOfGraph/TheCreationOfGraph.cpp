#include<iostream>
#include<vector>
#include"GraphClass.h"
using namespace std;
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
    graph.printGraph();
    system("pause");
    return 0;
}