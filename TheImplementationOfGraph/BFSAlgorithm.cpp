#include<iostream>
#include<vector>
#include<queue>
#include"GraphClass.h"
using namespace std;
//访问初始结点v并标记v已被访问
//结点v入队
//当队列非空时，继续执行否则算法结束
//出队列，取得队列头结点u
//查找结点u的第一个邻接结点
//若结点u的邻接结点w不存在，则转到步骤三，否则执行以下三个步骤
//若结点w尚未被访问，则访问结点w并标记为已访问
//结点w入队列
//查找结点u的继w邻接节点后的下一个邻接结点w，转到步骤6
void breathFirstSearch(Graph&graph,int v0){
    int u;//头结点对应下标
    int w;//邻接结点w
    //队列，记录结点访问顺序
    queue<int>que;
    //访问结点
    cout<<graph.getValue(v0)<<"->";
    graph.visit(v0);
    //将结点加入队列
    que.push(v0);
    while(!que.empty()){
        //取出队列的头结点下标
        u=que.front();
        que.pop();
        w=graph.getFirstAdjacentVertexIndex(u);
        while(w!=-1){
            //是否访问过
            if(!graph.beVisited(w)){
                cout<<graph.getValue(w)<<"=>";
                que.push(w);
                graph.visit(w);
            }
            w=graph.getNextAdjacentVertexIndex(u,w);
        }
    }
}
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

    breathFirstSearch(graph,0);
    system("pause");
    return 0;
}