//�շ�������
//������ַ���Ϊ i like like java do you like a java
//ͳ�Ƹ����ַ����ֵĴ��� d:1 y:1 j:2 v:2 o:2 l:4 k:4 e:4 i:5 a:5 :9
//�����ַ����ֵĴ�������һ�źշ�����
//���ݺշ������������ַ����룬�����·����0�����ҵ�·��Ϊ1�����Եõ�ǰ׺����
//��������: o:1000 u:10010 d:100110 y:100111 i:101
//a:110 k:1110 e:1111 j:0000 v:0001 l:001  :01
//�շ������������򷽷���ͬ�������ظ�ֵ����λ�ò�ͬ������ʹ�ù��������ĺշ�������̬��һ��
#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<algorithm>
#include<unordered_map>
#include<iomanip>
#include<cmath>
using namespace std;
class Node{
public:
    Node(char dat,int val){
        this->data=dat;
        this->weight=val;
        this->left=nullptr;
        this->right=nullptr;
    }
    int weight;//���Ȩֵ
    char data;
    Node*left;
    Node*right;
    void printInfo(){
        cout<<"Node[char="<<data<<",weight="<<weight<<"] \n";
    }
    void preOrder(){
        this->printInfo();
        //�ݹ���������ǰ�����
        if(this->left!=nullptr){
            this->left->preOrder();
        }
        //�ݹ���������ǰ�����
        if(this->right!=nullptr){
            this->right->preOrder();
        }
    }
};
class Cmp{
public:
    bool operator()(Node* n1,Node* n2){
        return n1->weight<=n2->weight;
    }
};

void PreOrder(Node*root){
    if(root!=nullptr){
        root->preOrder();
    }else{
        cout<<"�շ�����Ϊ��"<<endl;
    }
}

vector<Node*>getNodes(const vector<char>&bytes){
    vector<Node*>nodes;
    //ͳ��ÿ���ַ����ֵĴ���
    unordered_map<char,int>counts;
    for(char i:bytes){
        counts[i]++;
    }
    //��ÿһ����ֵ��ת��Node���󣬲����뵽nodes����
    for(auto entry:counts){
        nodes.push_back(new Node(entry.first,entry.second));
    }
    return nodes;
}

Node* CreateHuffmanTree(vector<Node*>&arr){
    deque<Node*>nodes;
    for(auto it:arr){
        nodes.push_back(new Node(it->data,it->weight));
    }
    while(nodes.size()>1){
    //����
    sort(nodes.begin(),nodes.end(),Cmp());
    //ȡ�����ڵ�Ȩֵ��С�����ö�����
    Node*leftNode=nodes.at(0);
    Node*rightNode=nodes.at(1);
    //����һ���µĶ�����
    Node* parent=new Node('+',leftNode->weight+rightNode->weight);
    parent->right=rightNode;
    parent->left=leftNode;
    //��������ɾ��������Ķ�����
    nodes.pop_front();
    nodes.pop_front();
    //��parent�����������
    nodes.push_back(parent);
    }
    return nodes.at(0);
}

//���ɺշ�������Ӧ�ĺշ��������
//�������node����Ҷ�ӽ��ĵĺշ�������õ��������뵽�շ���������
//node ������ code ·�������ӽ����0�����ӽ����1
static unordered_map<char,string>huffmanCode;
static string strBuilder;
void getCodes(Node*node,string code,string&temp){
    string temp2=temp;
    temp2.append(code);
    if(node!=nullptr){
        //�жϵ�ǰnode��Ҷ�ӽ�㻹�Ƿ�Ҷ�ӽ��
        if(node->data=='+'){//��Ҷ�ӽ��
            //�ݹ鴦��
            //����ݹ�
            getCodes(node->left,"0",temp2);
            //���ҵݹ�
            getCodes(node->right,"1",temp2);
        }else{//˵����һ��Ҷ�ӽ��
            huffmanCode[node->data]=temp2;
        }
    }
}
char strTochar(string str){
    int len=str.length();
    char ans;
    int temp=0;
    for(int i=0;i<len;i++){
        temp=temp*2+str[i]-'0';
    }
    if(temp>=128){
        temp-=256;
    }
    ans=(char)(temp);
    return ans;
}
//���ַ�����Ӧ��bytes���飬ͨ�����ɵĺշ������������һ���շ�������ѹ�����byte
vector<char>zip(vector<char>bytes,unordered_map<char,string>huffmancode){
    string str;
    for(char c:bytes){
        str+=huffmanCode[c];
    }
    // cout<<str<<endl;
    // cout<<str.length()<<endl;
    //����Ӧ�ַ���ת��byte����
    int len=(str.length()%8==0)?str.length()/8:str.length()/8+1;
    //����һ���洢ѹ�����byte����
    vector<char>temp(len);
    int index=0;
    for(int i=0;i<str.length();i+=8){
        string byte;
        if(i+8>str.length()){
            byte=str.substr(i);
        }else{
            byte=str.substr(i,8);
        }
        char ch=strTochar(byte);
        temp[index]=ch;
        // cout<<(int)ch<<" "<<byte<<endl;
        index++;
    }
    // for(auto i:temp){
    //     cout<<(int)i<<endl;
    // }
    return temp;
}
vector<char>huffmanZip(string originStr){
    vector<char>contentByte;
    for(auto item:originStr){
        contentByte.push_back(item);
    }
    vector<Node*>temp=getNodes(contentByte);
    Node* root=CreateHuffmanTree(temp);
    // unordered_map<char,int>counts;
    // for(char i:contentByte){
    //     counts[i]++;
    // }
    // for(auto i:counts){
    //     cout<<"�ַ�"<<i.first<<"���ִ���Ϊ"<<i.second<<endl;
    // }
    // PreOrder(root);
    // cout<<endl;
    getCodes(root,"",strBuilder);
    for(auto i:huffmanCode){
        cout<<i.first<<": "<<i.second<<endl;
    }
    vector<char>transByte=zip(contentByte,huffmanCode);
    return transByte;
}
int main(){
    string str="i like like like java do you like a java";
    vector<char>byte=huffmanZip(str);
    for(auto i:byte){
        cout<<(int)i<<endl;
    }
    system("pause");
    return 0;
}