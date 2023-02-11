#include<iostream>
#include<vector>
#include"GraphClass.h"
using namespace std;
// �㷨����
// ���ó�������Ϊv�����㼯��ΪV{v1,v2,vi...}��v��V�и�����ľ��빹�ɾ��뼯��Dis
// Dis{d1,d2,di...}��Dis���ϼ�¼��v��ͼ�и�����ľ��루v��vi�ľ����Ϊdi��
// 1.��Dis��ѡ��ֵ��С��di���Ƴ�Dis���ϣ�ͬʱ�Ƴ�V�����ж�Ӧ�Ķ���vi����ʱv��vi��Ϊ���·��
// 2.����Dis���ϣ��Ƚ�v��V�����ж���ľ���ֵ����vͨ��vi��V�����ж���ľ���ֵ������ֵ��С��һ��
// 3.�ظ�ִ�������裬ֱ�����·������ΪĿ�궥�㼴�ɽ���
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
    //������ʾ���㲻��ͨ
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