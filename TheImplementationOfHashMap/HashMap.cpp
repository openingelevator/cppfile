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
    //ָ���һ����Ա
    Emp*head=nullptr;
    //��ӹ�Ա������
    //��ӹ�Աʱ��id����������id�ķ������Ǵ�С����
    //��˽��ù�Ա�ӵ����������󼴿�
    void add(Emp* node){
        //�����ӵ�һ����Ա
        if (head==nullptr)
        {
            head=node;
            return;
        }
        //���������ӵ�һ����Ա
        Emp* cur=head;
        while(true){
            if(cur->next==nullptr){
                break;
            }
            cur=cur->next;
        }
        cur->next=node;
    }
    //��������Ĺ�Ա��Ϣ
    void showList(int index){
        if(head==nullptr){
            cout<<"��"<<index<<"������Ϊ��"<<endl;
            return;
        }
        cout<<"��"<<index<<"�������ϢΪ ";
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
    //����id���ҹ�Ա
    //�ҵ�����emp��û���ҵ��򷵻�nullptr
    Emp* findEmpById(int id){
        //�ж������Ƿ�Ϊ��
        if(head==nullptr){
            cout<<"����Ϊ��"<<endl;
            return nullptr;
        }
        Emp*cur=head;
        while(true){
            if(cur->m_id==id){
                break;
            }
            if(cur->next==nullptr){//˵����������û���ҵ��ù�Ա
                cur=nullptr;
                break;
            }
            cur=cur->next;
        }
        return cur;
    }
};
//������ϣ�������������
class HashTable{
public:
    EmployeeLinkedList* list;
    int tableSize;
    HashTable(int size){
        this->list=new EmployeeLinkedList[size];
        //��ʼ��ÿһ������
        // for(int i=0;i<size;i++){
        //     this->list[i]=EmployeeLinkedList();
        // }
        this->tableSize=size;
    }
    //��ӹ�Ա
    void Add(Emp*node){
        //����Ա����id�õ���Ա��Ӧ����ӵ���������
        int employeeHashNo=hashFun(node->m_id);
        //��node��ӵ���Ӧ��������
        this->list[employeeHashNo].add(node);
    }
    //��дɢ�к���
    int hashFun(int id){
        return id%tableSize;
    }
    //������ϣ��
    void showHashTable(){
        for(int i=0;i<tableSize;i++){
            this->list[i].showList(i+1);
        }
    }
    //���ҹ�Ա
    void findEmp(int id){
        //ʹ��ɢ�к��������������������
        int employeeHashNo=hashFun(id);
        Emp*node=this->list[employeeHashNo].findEmpById(id);
        if(node!=nullptr){
            cout<<"�ڵ�"<<employeeHashNo+1<<"���������ҵ��ù�Ա"<<endl;
        }else{
            cout<<"�ڹ�ϣ����û���ҵ��ù�Ա"<<endl;
        }
    }
};
int main(){
    HashTable* ht=new HashTable(7);
    int choice = 0;
	while (true){
		cout << "1����ӹ�Ա" << endl;
		cout << "2����ʾ��Ա" << endl;
		cout << "3���˳�ϵͳ" << endl;
        cout << "4�����ҹ�Ա" << endl;
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice){
		case 1:{
            cout<<"����Ҫ��ӹ�Ա��id"<<endl;
            int id;
            cin>>id;
            cout<<"����Ҫ��ӹ�Ա������"<<endl;
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
            cout<<"������Ҫ���ҹ�Ա��id"<<endl;
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