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
    //����Ԫ���Ƿ������������
    bool searchNode(int value)
    {
		Node* temp = head;
		bool flag = false;//��ʶ�ڵ��Ƿ��ҵ�
		while (true)
		{
            //����Ϊ�գ��ڵ㲻����
			if (temp->next == nullptr)
			{
				break;
			}
            //�ҵ�ָ��ֵ�Ľڵ�
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
        //�жϽ���Ƿ����
        if(searchNode(value))
        {
            cout<<"�����Ѵ��ڣ��޷��������"<<endl;
            return false;
        }
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
        return true;
	}
	bool deleteNode(int value)
	{
		Node*temp=head;
        bool flag= searchNode(value);
		if (flag)
		{
            //�ƶ�tempָ��ʹ��ָ���ɾ������ǰһ�����
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
            //����ɾ���ڵ��ǰһ�����ָ���ɾ���ڵ�ĺ�һ�����
			Node* node = temp->next;
			temp->next = temp->next->next;
			delete node;
            return true;
		}
		else
		{
			cout << "δ�ҵ���ɾ���Ľڵ�" << endl;
            return false;
		}
	}

	//��ʾ����
	void showList()
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
	}
    //��ȡ������Ч���ĸ���
    int getLength()
    {
	if (head->next == nullptr)//������
	{
		return 0;
	}
	int length = 0;
	//��ͳ��ͷ�ڵ�
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
    //����һ����������в���
    SingleLinkedList l1;
    int choice;
	while (true)
	{
		cout << "1����ʾ��ӡ������" << endl;
		cout << "2���˳�����" << endl;
		cout << "3��������ݵ�����" << endl;
		cout << "4�����������Ƴ�����" << endl;
		cout << "5�������������Ƿ����ָ������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "��������Ϊ" << endl;
			l1.showList();
			cout << endl;
			break;
		case 2:
			exit(0);
			break;
		case 3:
			cout << "������Ҫ��ӵ����ݸ���" << endl;
			int count;
			cin >> count;
            cout<<"����������"<<endl;
            for(int i=0;i<count;i++)
			{
                int num;
                cin>>num;
                l1.addNode(num);
            }
			break;
		case 4:
			cout << "������Ҫɾ��������" << endl;
			int num1;
			cin >> num1;
			l1.deleteNode(num1);
			break;
		case 5:
			cout << "������Ҫ���ҵ�����" << endl;
			int num2;
			cin >> num2;
			if(l1.searchNode(num2))
            {
                cout<<"�����д��ڴ˽��"<<endl;
            }
            else
            {
                cout<<"�����в����ڴ˽ڵ�"<<endl;
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