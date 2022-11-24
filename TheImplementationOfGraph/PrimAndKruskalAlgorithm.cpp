#include<iostream>
#include<iostream>
#include"GraphClass.h"
using namespace std;
//最小生成树：给定一个带权的无向连通图，如何选取一棵生成树，使得树上所有边上权的总和最小
//N个顶点，N-1条边
//包含全部顶点
//N-1条边都在图中
//Prim算法
//（1）设G=(V,E)为连通网，T=(U,D)为最小生成树，U,V是顶点集合，E,D为边的集合
//（2）若从顶点u开始构造最小生成树，则从集合V中取出顶点u放入集合U中，标记顶点v的isVisited[u]=1
//（3）若集合U中顶点ui与集合V-U中的顶点vj之间存在边，则寻找这些边中权值最小的边，但不能构成回路，将顶点vj加入集合U中
//将边(ui,vj)加入集合D中，标记isVisited[vj]=1
//（4）重复步骤（2）直到U与V相等，即所有顶点都被标记为访问过，此时D中有n-1条边
class MinTree{
public:
    void creatGraph(Graph&graph,int numOfVertex,char* data,int**weight){
        for(int i=0;i<numOfVertex;++i){
            graph.insertVertex(data[i]);
            for(int j=0;j<numOfVertex;++j){
                graph.insertEdge(i,j,weight[i][j],false);
            }
        }
    }

    //编写prim算法
    void prim(Graph graph,int v){
        //标记此顶点已经访问过
        graph.visit(v);
        //h1，h2记录两个顶点的下标
        int h1=-1;
        int h2=-1;
        int minWeight=10000;
        //N个顶点，N-1条边
        for(int i=1;i<graph.getNumOfVertex();++i){

            //确定每一次生成的子图和哪个结点的距离最近
            for(int j=0;j<graph.getNumOfVertex();++j){//j结点表示被访问过的结点
                for(int k=0;k<graph.getNumOfVertex();++k){//k结点表示未被访问过的结点
                    if(graph.beVisited(j)==1&&graph.beVisited(k)==0&&
                    graph.getWeight(j,k)<minWeight){
                        minWeight=graph.getWeight(j,k);
                        h1=j;
                        h2=k;
                    }
                }
            }
            cout<<"边<"<<graph.getValue(h1)<<","<<graph.getValue(h2)<<"> 权值："<<minWeight<<endl;
            graph.visit(h2);
            minWeight=10000;
        }

    }
};
int main(){
    Graph graph(7);
    char data[7]={'A','B','C','D','E','F','G'};
    char*ptr1=data;
    //大数表示两点不连通
    int weight[7][7]=
    {{10000,5,7,10000,10000,10000,2},
    {5,10000,10000,9,10000,10000,3},
    {7,10000,10000,10000,8,10000,10000},
    {10000,9,10000,10000,10000,4,10000},
    {10000,10000,8,10000,10000,5,4},
    {10000,10000,10000,4,5,10000,6},
    {2,3,10000,10000,4,6,10000}};
    int**ptr2=new int*[7];
    for(int i=0;i<7;++i){
        *(ptr2+i)=new int[7];
    }
    for(int i=0;i<7;++i){
        for(int j=0;j<7;++j){
            ptr2[i][j]=weight[i][j];
        }
    }
    MinTree tree;
    tree.creatGraph(graph,7,ptr1,ptr2);
    graph.printGraph();
    cout<<endl;
    tree.prim(graph,0);
    system("pause");
    return 0;
}

