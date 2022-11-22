#include<iostream>
#include<vector>
#include<queue>
#include"GraphClass.h"
using namespace std;
//���ʳ�ʼ���v�����v�ѱ�����
//���v���
//�����зǿ�ʱ������ִ�з����㷨����
//�����У�ȡ�ö���ͷ���u
//���ҽ��u�ĵ�һ���ڽӽ��
//�����u���ڽӽ��w�����ڣ���ת��������������ִ��������������
//�����w��δ�����ʣ�����ʽ��w�����Ϊ�ѷ���
//���w�����
//���ҽ��u�ļ�w�ڽӽڵ�����һ���ڽӽ��w��ת������6
void breathFirstSearch(Graph&graph,int v0){
    int u;//ͷ����Ӧ�±�
    int w;//�ڽӽ��w
    //���У���¼������˳��
    queue<int>que;
    //���ʽ��
    cout<<graph.getValue(v0)<<"->";
    graph.visit(v0);
    //�����������
    que.push(v0);
    while(!que.empty()){
        //ȡ�����е�ͷ����±�
        u=que.front();
        que.pop();
        w=graph.getFirstAdjacentVertexIndex(u);
        while(w!=-1){
            //�Ƿ���ʹ�
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