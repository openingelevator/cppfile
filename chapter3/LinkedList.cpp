#include<iostream>
using namespace std;

class Node
{
public:
	Node(int hno)
		:num(hno), next(nullptr)
	{
	}
	int num;
	Node* next;
};
class SingleLinkedList
{
private:
	Node* head = new Node(0);
public:
	Node* getHead()
	{
		return head;
	}
    //测试元素是否包含在链表中
    bool searchNode(int value)
    {
		Node* temp = head;
		bool flag = false;//标识节点是否找到
		while (true)
		{
            //链表为空，节点不存在
			if (temp->next == nullptr)
			{
				break;
			}
            //找到指定值的节点
			if (temp->next->num == value)
			{
				flag = true;
				break;
			}
			temp = temp->next;
		}
        return flag;
    }

	bool addNode(int value)
	{
        //判断结点是否存在
        if(searchNode(value))
        {
            cout<<"数据已存在，无法正常添加"<<endl;
            return false;
        }
		//不考虑编号顺序时
		Node* temp = head;
		//找到链表的最后一个节点
		while (true)
		{
			//找到链表的最后
			if (temp->next == NULL)
			{
				break;
			}
			//未找到链表的最后，则将temp后移
			temp = temp->next;
		}
	    //然后将最后节点的next域指向新的节点
		temp->next = new Node(value);
        return true;
	}
	bool deleteNode(int value)
	{
		Node*temp=head;
        bool flag= searchNode(value);
		if (flag)
		{
            //移动temp指针使其指向待删除结点的前一个结点
            while (true)
		    {
			if (temp->next == nullptr)
			{
				break;
			}
			if (temp->next->num == value)
			{
				break;
			}
			temp = temp->next;
		    }
            //将待删除节点的前一个结点指向待删除节点的后一个结点
			Node* node = temp->next;
			temp->next = temp->next->next;
			delete node;
            return true;
		}
		else
		{
			cout << "未找到待删除的节点" << endl;
            return false;
		}
	}

	//显示链表
	void showList()
	{
		if (head->next == nullptr)
		{
			cout << "链表为空" << endl;
			return;
		}
		Node* temp = head->next;
		while (true)
		{
			//判断是否到链表最后
			if (temp == nullptr)
			{
				break;
			}
			//输出节点信息
			cout << temp->num << " ";
			temp = temp->next;
		}
	}
    //获取链表有效结点的个数
    int getLength()
    {
	if (head->next == nullptr)//空链表
	{
		return 0;
	}
	int length = 0;
	//不统计头节点
	Node* cur = head->next;
	while (true)
	{
		if (cur == nullptr)
		{
			break;
		}
		cur = cur->next;
		length++;
	}
	return length;
   }
};
int main()
{
    //创建一个单链表进行测试
    SingleLinkedList l1;
    int choice;
	while (true)
	{
		cout << "1、显示打印单链表" << endl;
		cout << "2、退出程序" << endl;
		cout << "3、添加数据到链表" << endl;
		cout << "4、从链表中移除数据" << endl;
		cout << "5、查找链表中是否存在指定数据" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "链表数据为" << endl;
			l1.showList();
			cout << endl;
			break;
		case 2:
			exit(0);
			break;
		case 3:
			cout << "请输入要添加的数据个数" << endl;
			int count;
			cin >> count;
            cout<<"请输入数据"<<endl;
            for(int i=0;i<count;i++)
			{
                int num;
                cin>>num;
                l1.addNode(num);
            }
			break;
		case 4:
			cout << "请输入要删除的数据" << endl;
			int num1;
			cin >> num1;
			l1.deleteNode(num1);
			break;
		case 5:
			cout << "请输入要查找的数据" << endl;
			int num2;
			cin >> num2;
			if(l1.searchNode(num2))
            {
                cout<<"链表中存在此结点"<<endl;
            }
            else
            {
                cout<<"链表中不存在此节点"<<endl;
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