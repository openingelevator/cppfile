#include<iostream>
#include<string>
using namespace std;
class Emp{
public:
    Emp(int id,string name){
        this->m_id=id;
        this->m_name=name;
        this->next=nullptr;
    }
    int m_id;
    string m_name;
    Emp* next;
};
class EmployeeLinkedList{
public:
    //指向第一个雇员
    Emp*head=nullptr;
    //添加雇员到链表
    //添加雇员时，id是自增长，id的分配总是从小到大
    //因此将该雇员加到本链表的最后即可
    void add(Emp* node){
        //如果添加第一个雇员
        if (head==nullptr)
        {
            head=node;
            return;
        }
        //如果不是添加第一个雇员
        Emp* cur=head;
        while(true){
            if(cur->next==nullptr){
                break;
            }
            cur=cur->next;
        }
        cur->next=node;
    }
    //遍历链表的雇员信息
    void showList(int index){
        if(head==nullptr){
            cout<<"第"<<index<<"条链表为空"<<endl;
            return;
        }
        cout<<"第"<<index<<"链表的信息为 ";
        Emp*cur=head;
        while(true){
            cout<<"=>id="<<cur->m_id<<" name="<<cur->m_name<<"  ";
            if(cur->next==nullptr){
                break;
            }
            cur=cur->next;
        }
        cout<<endl;
    }
    //根据id查找雇员
    //找到返回emp，没有找到则返回nullptr
    Emp* findEmpById(int id){
        //判断链表是否为空
        if(head==nullptr){
            cout<<"链表为空"<<endl;
            return nullptr;
        }
        Emp*cur=head;
        while(true){
            if(cur->m_id==id){
                break;
            }
            if(cur->next==nullptr){//说明遍历链表没有找到该雇员
                cur=nullptr;
                break;
            }
            cur=cur->next;
        }
        return cur;
    }
};
//创建哈希表，管理多条链表
class HashTable{
public:
    EmployeeLinkedList* list;
    int tableSize;
    HashTable(int size){
        this->list=new EmployeeLinkedList[size];
        //初始化每一个链表
        // for(int i=0;i<size;i++){
        //     this->list[i]=EmployeeLinkedList();
        // }
        this->tableSize=size;
    }
    //添加雇员
    void Add(Emp*node){
        //根据员工的id得到该员工应该添加到哪条链表
        int employeeHashNo=hashFun(node->m_id);
        //将node添加到对应的链表中
        this->list[employeeHashNo].add(node);
    }
    //编写散列函数
    int hashFun(int id){
        return id%tableSize;
    }
    //遍历哈希表
    void showHashTable(){
        for(int i=0;i<tableSize;i++){
            this->list[i].showList(i+1);
        }
    }
    //查找雇员
    void findEmp(int id){
        //使用散列函数决定到哪条链表查找
        int employeeHashNo=hashFun(id);
        Emp*node=this->list[employeeHashNo].findEmpById(id);
        if(node!=nullptr){
            cout<<"在第"<<employeeHashNo+1<<"条链表中找到该雇员"<<endl;
        }else{
            cout<<"在哈希表中没有找到该雇员"<<endl;
        }
    }
};
int main(){
    HashTable* ht=new HashTable(7);
    int choice = 0;
	while (true){
		cout << "1：添加雇员" << endl;
		cout << "2：显示雇员" << endl;
		cout << "3：退出系统" << endl;
        cout << "4：查找雇员" << endl;
		cout << "请输入你的选择" << endl;
		cin >> choice;
		switch (choice){
		case 1:{
            cout<<"输入要添加雇员的id"<<endl;
            int id;
            cin>>id;
            cout<<"输入要添加雇员的姓名"<<endl;
            string name;
            cin>>name;
            ht->Add(new Emp(id,name));
            }
			break;
		case 2:
			ht->showHashTable();
			break;
		case 3:
			exit(1);
			break;
        case 4:{
            cout<<"请输入要查找雇员的id"<<endl;
            int id;
            cin>>id;
            ht->findEmp(id);
            }
            break;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
    system("pause");
    return 0;
}