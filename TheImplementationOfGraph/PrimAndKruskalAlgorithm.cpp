#include<iostream>
#include<vector>
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

//Kruskal算法
//按照权值从小到大选择n-1条边，并保证这n-1条边不构成回路
//首先构造一个只含有n个结点的森林，然后依照权值从小到大连通网中选择边加入到森林中，并使森林不产生回路，直到森林变成一棵树为止
class EData{
public:
    char start;//边的一个点
    char end;//边的另一个点
    int weight;//边的权值
    EData(char ini_start,char ini_end,int ini_weight){
        this->start=ini_start;
        this->end=ini_end;
        this->weight=ini_weight;
    }
    void to_string(){
        cout<<"EData[start="<<start<<", end="<<end<<", weight="<<weight<<"]"<<endl;
    }
};
void swap(EData&a,EData&b){
    EData temp=a;
    a=b;
    b=temp;
}
void sortEdges(vector<EData>&edges){
    for(int i=0;i<edges.size();++i){
        for(int j=0;j<edges.size()-1-i;++j){
            if(edges[j].weight>edges[j+1].weight){
                swap(edges[j],edges[j+1]);
            }
        }
    }
}
//传入顶点的值返回对应下标找不到返回-1
int getPosition(Graph graph,char ch){
    for(int i=0;i<graph.getNumOfVertex();++i){
        if(graph.getValue(i)==ch){
            return i;
        }
    }
    return -1;
}

vector<EData>getEdges(Graph graph){
    vector<EData>edges;
    int weight=0;
    EData temp(0,0,0);
    for(int i=0;i<graph.getNumOfVertex();++i){
        for(int j=i+1;j<graph.getNumOfVertex();++j){
            weight=graph.getWeight(i,j);
            if(weight!=10000){
                temp.start=graph.getValue(i);
                temp.end=graph.getValue(j);
                temp.weight=weight;
                edges.push_back(temp);
            }
        }
    }
    return edges;
}

//获取下标为i的顶点的终点，用于判断两个顶点的终点是否相同
int getEnd(vector<int>ends,int i){
    while(ends[i]!=0){
        i=ends[i];
    }
    return i;
}

class MinTree{
public:
    void creatGraph(Graph&graph,int numOfVertex,char* data,int**weight){
        for(int i=0;i<numOfVertex;++i){
            graph.insertVertex(data[i]);
            for(int j=i+1;j<numOfVertex;++j){
                graph.insertEdge(i,j,weight[i][j]);
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

    void kruskal(Graph graph){
        int numOfEdges=graph.getNumOfEdges();
        vector<int>ends(numOfEdges,0);//用于保存已有最小生成树中每个顶点的在最小生成树中的终点
        //创建结果数组，保存最后生成的最小生成树
        vector<EData>rets;
        //获取图中所有边的集合
        vector<EData>edges=getEdges(graph);
        //按照边的权值大小进行排序
        sortEdges(edges);
        //遍历edges数组，将边添加到最小生成树，判断准备加入的边是否形成了回路，如果没有，则加入rets，否则不能加入
        for(int i=0;i<numOfEdges;++i){
            //获取到第i条的第一个顶点（起点）
            int p1=getPosition(graph,edges[i].start);
            int p2=getPosition(graph,edges[i].end);

            //获取p1顶点的在已有的最小生成树对应的终点
            int m=getEnd(ends,p1);
             //获取p2顶点的在当前的最小生成树对应的终点
            int n=getEnd(ends,p2);

            //判断是否构成回路
            if(m!=n){//不构成回路
                ends[m]=n;//设置m在已有最小生成树的顶点
                rets.push_back(edges[i]);
            }
        }
        //输出最小生成树
        cout<<"最小生成树为"<<endl;
        for(auto i:rets){
            i.to_string();
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
    MinTree mintree;
    mintree.creatGraph(graph,7,ptr1,ptr2);
    graph.printGraph();
    cout<<endl;
    // mintree.prim(graph,0);
    // vector<EData>edges=getEdges(graph);
    // cout<<"排序前"<<endl;
    // for(auto i:edges){
    //     i.to_string();
    // }
    // sortEdges(edges);
    // cout<<"排序后"<<endl;
    // for(auto i:edges){
    //     i.to_string();
    // }
    mintree.kruskal(graph);
    system("pause");
    return 0;
}