#include<iostream>
#include<vector>
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

//Kruskal�㷨
//����Ȩֵ��С����ѡ��n-1���ߣ�����֤��n-1���߲����ɻ�·
//���ȹ���һ��ֻ����n������ɭ�֣�Ȼ������Ȩֵ��С������ͨ����ѡ��߼��뵽ɭ���У���ʹɭ�ֲ�������·��ֱ��ɭ�ֱ��һ����Ϊֹ
class EData{
public:
    char start;//�ߵ�һ����
    char end;//�ߵ���һ����
    int weight;//�ߵ�Ȩֵ
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
//���붥���ֵ���ض�Ӧ�±��Ҳ�������-1
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

//��ȡ�±�Ϊi�Ķ�����յ㣬�����ж�����������յ��Ƿ���ͬ
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

    void kruskal(Graph graph){
        int numOfEdges=graph.getNumOfEdges();
        vector<int>ends(numOfEdges,0);//���ڱ���������С��������ÿ�����������С�������е��յ�
        //����������飬����������ɵ���С������
        vector<EData>rets;
        //��ȡͼ�����бߵļ���
        vector<EData>edges=getEdges(graph);
        //���ձߵ�Ȩֵ��С��������
        sortEdges(edges);
        //����edges���飬������ӵ���С���������ж�׼������ı��Ƿ��γ��˻�·�����û�У������rets�������ܼ���
        for(int i=0;i<numOfEdges;++i){
            //��ȡ����i���ĵ�һ�����㣨��㣩
            int p1=getPosition(graph,edges[i].start);
            int p2=getPosition(graph,edges[i].end);

            //��ȡp1����������е���С��������Ӧ���յ�
            int m=getEnd(ends,p1);
             //��ȡp2������ڵ�ǰ����С��������Ӧ���յ�
            int n=getEnd(ends,p2);

            //�ж��Ƿ񹹳ɻ�·
            if(m!=n){//�����ɻ�·
                ends[m]=n;//����m��������С�������Ķ���
                rets.push_back(edges[i]);
            }
        }
        //�����С������
        cout<<"��С������Ϊ"<<endl;
        for(auto i:rets){
            i.to_string();
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
    MinTree mintree;
    mintree.creatGraph(graph,7,ptr1,ptr2);
    graph.printGraph();
    cout<<endl;
    // mintree.prim(graph,0);
    // vector<EData>edges=getEdges(graph);
    // cout<<"����ǰ"<<endl;
    // for(auto i:edges){
    //     i.to_string();
    // }
    // sortEdges(edges);
    // cout<<"�����"<<endl;
    // for(auto i:edges){
    //     i.to_string();
    // }
    mintree.kruskal(graph);
    system("pause");
    return 0;
}