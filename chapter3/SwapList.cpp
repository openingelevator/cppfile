#include<iostream>
using namespace std;
class Node
{
public:
	Node(int hno)
		:num(hno), next(nullptr),pre(nullptr)
	{
	}
	int num;
	Node* next;
    Node* pre;
};
// Node* swapPairs(Node* head) {
//         //�ؼ����裬ʹ�ú����������Ĳ���һ��
//         Node* temp=new Node(0);
//         temp->next=head;
//         Node* pre=temp;
//         Node* post=temp->next;
//         while(pre->next!=nullptr&&post!=nullptr&&post->next!=nullptr)
//         {
//             Node*temp1=post->next;
//             pre->next=post->next;
//             post->next=temp1->next;
//             temp1->next=post;
//             //��pre��post������
//             pre=pre->next->next;
//             post=pre->next;
//         }
//         return temp->next;
// }
Node* swapPairs2(Node *head)
{
    Node* before=head;
    Node* after=head->next;
    while(before->next!=nullptr&&after!=nullptr&&after->next!=nullptr)
    {
        Node* temp1=after->next;
        before->next=temp1;
        temp1->pre=before;

        after->next=temp1->next;
        if(temp1->next!=nullptr)
        {
            temp1->next->pre=after;
        }

        temp1->next=after;
        after->pre=temp1;

        after=after->next;
        before=before->next->next;
    }
    return head;
}
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
void addNode(int value,Node*head)
{
 
		//�����Ǳ��˳��ʱ
		Node* temp = head;
		//�ҵ���������һ���ڵ�
		while (true)
		{
			//�ҵ���������
			if (temp->next == NULL)
			{
				break;
			}
			//δ�ҵ�����������temp����
			temp = temp->next;
		}
	    //Ȼ�����ڵ��next��ָ���µĽڵ�
		temp->next = new Node(value);

}
int main()
{
    Node* head=new Node(0);
    addNode(1,head);
    addNode(4,head);
    addNode(3,head);
    addNode(5,head);
    addNode(2,head);
    cout<<"ԭ��������"<<endl;
    showList(head);
    cout<<"���������������"<<endl;
    showList(swapPairs2(head));
     system("pause");
     return 0;
}