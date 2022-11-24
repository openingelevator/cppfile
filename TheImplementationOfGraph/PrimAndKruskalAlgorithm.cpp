#include<iostream>
#include<iostream>
#include"GraphClass.h"
using namespace std;
//��С������������һ����Ȩ��������ͨͼ�����ѡȡһ����������ʹ���������б���Ȩ���ܺ���С
//N�����㣬N-1����
//����ȫ������
//N-1���߶���ͼ��
//Prim�㷨
//��1����G=(V,E)Ϊ��ͨ����T=(U,D)Ϊ��С��������U,V�Ƕ��㼯�ϣ�E,DΪ�ߵļ���
//��2�����Ӷ���u��ʼ������С����������Ӽ���V��ȡ������u���뼯��U�У���Ƕ���v��isVisited[u]=1
//��3��������U�ж���ui�뼯��V-U�еĶ���vj֮����ڱߣ���Ѱ����Щ����Ȩֵ��С�ıߣ������ܹ��ɻ�·��������vj���뼯��U��
//����(ui,vj)���뼯��D�У����isVisited[vj]=1
//��4���ظ����裨2��ֱ��U��V��ȣ������ж��㶼�����Ϊ���ʹ�����ʱD����n-1����
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

    //��дprim�㷨
    void prim(Graph graph,int v){
        //��Ǵ˶����Ѿ����ʹ�
        graph.visit(v);
        //h1��h2��¼����������±�
        int h1=-1;
        int h2=-1;
        int minWeight=10000;
        //N�����㣬N-1����
        for(int i=1;i<graph.getNumOfVertex();++i){

            //ȷ��ÿһ�����ɵ���ͼ���ĸ����ľ������
            for(int j=0;j<graph.getNumOfVertex();++j){//j����ʾ�����ʹ��Ľ��
                for(int k=0;k<graph.getNumOfVertex();++k){//k����ʾδ�����ʹ��Ľ��
                    if(graph.beVisited(j)==1&&graph.beVisited(k)==0&&
                    graph.getWeight(j,k)<minWeight){
                        minWeight=graph.getWeight(j,k);
                        h1=j;
                        h2=k;
                    }
                }
            }
            cout<<"��<"<<graph.getValue(h1)<<","<<graph.getValue(h2)<<"> Ȩֵ��"<<minWeight<<endl;
            graph.visit(h2);
            minWeight=10000;
        }

    }
};
int main(){
    Graph graph(7);
    char data[7]={'A','B','C','D','E','F','G'};
    char*ptr1=data;
    //������ʾ���㲻��ͨ
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

