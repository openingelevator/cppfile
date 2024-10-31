//赫夫曼编码
//传输的字符串为 i like like java do you like a java
//统计各个字符出现的次数 d:1 y:1 j:2 v:2 o:2 l:4 k:4 e:4 i:5 a:5 :9
//按照字符出现的次数构建一颗赫夫曼树
//根据赫夫曼树给各个字符编码，向左的路径是0，向右的路径为1，可以得到前缀编码
//编码如下: o:1000 u:10010 d:100110 y:100111 i:101
//a:110 k:1110 e:1111 j:0000 v:0001 l:001  :01
//赫夫曼树根据排序方法不同，对于重复值排序位置不同，都会使得构建出来的赫夫曼树形态不一样
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
    int weight;//结点权值
    char data;
    Node*left;
    Node*right;
    void printInfo(){
        cout<<"Node[char="<<data<<",weight="<<weight<<"] \n";
    }
    void preOrder(){
        this->printInfo();
        //递归向左子树前序遍历
        if(this->left!=nullptr){
            this->left->preOrder();
        }
        //递归向右子树前序遍历
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
        cout<<"赫夫曼树为空"<<endl;
    }
}

vector<Node*>getNodes(const vector<char>&bytes){
    vector<Node*>nodes;
    //统计每次字符出现的次数
    unordered_map<char,int>counts;
    for(char i:bytes){
        counts[i]++;
    }
    //把每一个键值对转成Node对象，并加入到nodes集合
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
    //排序
    sort(nodes.begin(),nodes.end(),Cmp());
    //取出根节点权值最小的两棵二叉树
    Node*leftNode=nodes.at(0);
    Node*rightNode=nodes.at(1);
    //构建一棵新的二叉树
    Node* parent=new Node('+',leftNode->weight+rightNode->weight);
    parent->right=rightNode;
    parent->left=leftNode;
    //从容器中删除处理过的二叉树
    nodes.pop_front();
    nodes.pop_front();
    //将parent加入二叉树中
    nodes.push_back(parent);
    }
    return nodes.at(0);
}

//生成赫夫曼树对应的赫夫曼编码表
//将传入的node结点的叶子结点的的赫夫曼编码得到，并放入到赫夫曼集合中
//node 传入结点 code 路径，左子结点是0，右子结点是1
static unordered_map<char,string>huffmanCode;
static string strBuilder;
void getCodes(Node*node,string code,string&temp){
    string temp2=temp;
    temp2.append(code);
    if(node!=nullptr){
        //判断当前node是叶子结点还是非叶子结点
        if(node->data=='+'){//非叶子结点
            //递归处理
            //向左递归
            getCodes(node->left,"0",temp2);
            //向右递归
            getCodes(node->right,"1",temp2);
        }else{//说明是一个叶子结点
            huffmanCode[node->data]=temp2;
        }
    }
}
short strTochar(string str){
    int len=str.length();
    short ans;
    int temp=0;
    for(int i=0;i<len;i++){
        temp=temp*2+str[i]-'0';
    }
    if(temp>=128){
        temp-=256;
    }
    ans=temp;
    return ans;
}
//将字符串对应的bytes数组，通过生成的赫夫曼编码表，返回一个赫夫曼编码压缩后的byte
vector<short>zip(vector<char>bytes,unordered_map<char,string>huffmancode){
    string str;
    for(char c:bytes){
        str+=huffmanCode[c];
    }
    cout<<str<<endl;
    // cout<<str.length()<<endl;
    //将对应字符串转成byte数组
    int len=(str.length()%8==0)?str.length()/8:str.length()/8+1;
    //创建一个存储压缩后的byte数组
    vector<short>temp(len+1);
    fill(temp.begin(),temp.end(),0);
    int index=0;
    for(int i=0;i<str.length();i+=8){
        string byte;
        if(i+8>str.length()){
            byte=str.substr(i);
            short bias=i+8-str.length();
            temp[index+1]=bias;
        }else{
            byte=str.substr(i,8);
        }
        short ch=strTochar(byte);
        temp[index]=ch;
        // cout<<(int)ch<<" "<<byte<<endl;
        index++;
    }
    // for(auto i:temp){
    //     cout<<(int)i<<endl;
    // }
    return temp;
}
vector<short>huffmanZip(string originStr){
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
    //     cout<<"字符"<<i.first<<"出现次数为"<<i.second<<endl;
    // }
    // PreOrder(root);
    // cout<<endl;
    getCodes(root,"",strBuilder);
    for(auto i:huffmanCode){
        cout<<i.first<<": "<<i.second<<endl;
    }
    vector<short>transByte=zip(contentByte,huffmanCode);
    return transByte;
}
//数据解压
//将压缩后的编码数组转成赫夫曼编码对应的二进制的字符串
//将整形转为二进制字符串，bias为最后一个字段补足到8位的位数
string intToBinaryString(int num,int bias){
    string ans(8-bias,'0');
    if(num<0){
        num+=256;
    }
    int temp;
    int index=ans.length()-1;
    while(num>0){
        temp=num%2;
        num/=2;
        ans[index]=temp+'0';
        index--;
    }
    // cout<<ans<<endl;
    return ans;
}
//完成对压缩数据的解码
vector<char>decode(vector<short>huffmanBytes,unordered_map<char,string>huffmancode){
    auto ite=huffmanBytes.end()-1;
    short lastBitBias=*ite;
    // cout<<*ite<<endl;
    int trueLen=huffmanBytes.size()-1;
    // cout<<trueLen<<endl;
    string binaryStr;
    int tempVal=0;
    for(int i=0;i<trueLen;++i){
        tempVal=huffmanBytes[i];
        // cout<<tempVal<<endl;
        if(i==trueLen-1){
           binaryStr+=intToBinaryString(tempVal,lastBitBias);
        }else{
            binaryStr+=intToBinaryString(tempVal,0);
        }
    }
    // cout<<binaryStr<<endl;
    //将赫夫曼编码表进行调换
    unordered_map<string,char>Map;
    for(auto entry:huffmanCode){
        Map[entry.second]=entry.first;
    }
    // for(auto i:Map){
    //     cout<<i.first<<"="<<i.second<<endl;
    // }
    vector<char>ans;
    int i=0;
    while(i<binaryStr.length()){
        int count=1;
        while(true){
            string key=binaryStr.substr(i,count);
            auto tempIte=Map.find(key);
            if(tempIte!=Map.end()){
                ans.push_back(tempIte->second);
                break;
            }else{
                count++;
            }
            if(i+count>binaryStr.length()){
                break;
            }
        }
        i+=count;
    }
    return ans;
}

int main(){
    string str="i like like like java do you like a java";
    vector<short>byte=huffmanZip(str);
    // for(auto i:byte){
    //     cout<<i<<endl;
    // }
    vector<char>finalAns=decode(byte,huffmanCode);
    for(auto i:finalAns){
        cout<<i;
    }
    cout<<endl;
    system("pause");
    return 0;
}