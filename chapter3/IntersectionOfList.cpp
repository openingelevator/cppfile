#include<iostream>
using namespace std;

class Node
{
public:
	Node(int no)
		:num(no), next(nullptr)
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
	void addNode(Node* node)
	{
		Node* temp = head;
		bool flag = false;
		while (true)
		{
			if (temp->next == nullptr)
			{
				break;
			}
			else if (temp->next->num > node->num)
			{
				break;
			}
			else if (temp->next->num == node->num)
			{
				//����Ѵ���
				flag = true;
				break;
			}
			temp = temp->next;
		}

		if (flag == true)
		{
			cout << "׼������Ľڵ����Ѵ��ڣ��޷��������" << endl;
		}
		else
		{
			//���뵽������
			node->next = temp->next;
			temp->next = node;
		}
	}

};
//��ʾ����
void showList(Node* head)
{
		if (head->next == nullptr)
		{
			cout << "����Ϊ��" << endl;
			return;
		}
		Node* temp = head->next;
		while (true)
		{
			//�ж��Ƿ��������
			if (temp == nullptr)
			{
				break;
			}
			//����ڵ���Ϣ
			cout << temp->num << " ";
			temp = temp->next;
		}
        cout<<endl;
}
Node* InterSectionOfLists(Node* l1,Node* l2)
{
    Node* temp1=l1->next;
    Node* temp2=l2->next;
    Node* newhead=new Node(0);
    Node* cur=newhead;
    while(temp1!=nullptr)
    {
        while(temp2!=nullptr)
        {
            if(temp2->num==temp1->num)
            {
                cur->next=new Node(temp2->num);
                cur=cur->next;
                break;
            }//���������£��ڴ˽ڵ����ֵС�ڴ����ҵ�����ڵ���ֵʱ����ֹͣ����
            else if(temp2->num>temp1->num)
            {
                break;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return newhead;
}
int main()
{
    SingleLinkedList l1;
    SingleLinkedList l2;
    l1.addNode(new Node(1));
    l1.addNode(new Node(2));
    l1.addNode(new Node(4));
    cout<<"����1Ϊ"<<endl;
    showList(l1.getHead());
    cout<<"����2Ϊ"<<endl;
    l2.addNode(new Node(4));
    l2.addNode(new Node(3));
    l2.addNode(new Node(1));
    l2.addNode(new Node(5));
    showList(l2.getHead());
    Node* head=InterSectionOfLists(l1.getHead(),l2.getHead());
    cout<<"ȡ�����������Ϊ"<<endl;
    showList(head);
    system("pause");
    return 0;
}