/*
 * @Author: ֣᷷� 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by:   ֣᷷� 
 * @SID:202130462264
 * @Last Modified time: 2022-09-24 12:14:29 
 */
#include"MyArray.hpp"
#include<iostream>
#include<string>
using namespace std;
void init(myArray<string>&container)
{
    string IdNum[5]={"20213046","20213023","20214352","20214055","20214155"};
    for(int i=0;i<5;i++)
    {
        container.append(IdNum[i]);
    }
}
int main()
{
    myArray<string>container;
    init(container);
    int choice=0;
    while (true)
	{
		cout << "1����ʾ�����ڵ�����" << endl;
		cout << "2���˳�����" << endl;
		cout << "3������������ݵ��б�" << endl;
		cout << "4���Ƴ��б��е�����" << endl;
        cout << "5�����б��ض�λ�ò�������" << endl;
        cout << "6������б��ض�λ��Ԫ��" << endl;
        cout << "7������ض�Ԫ��λ��"<<endl;
        cout << "8����ʾ�б��Ԫ�ظ���"<<endl; 
		cout << "���������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			container.print();
			break;
		case 2:
			exit(1);
			break;
		case 3:
			{
            cout << "������Ҫ��ӵ����ݸ���" << endl;
            int num=0;
            cin>>num;
            for(int i=0;i<num;i++)
            {
                cout<<"������ѧ��"<<endl;
                string id;
                cin>>id;
                container.append(id);
            }
            }
			break;
		case 4:
            {
			cout<<"������Ҫ�Ƴ�Ԫ�ص�λ��"<<endl;
            int pos=0;
            cin>>pos;
            container.remove(pos);
            }
			break;
        case 5:
			{
            cout<<"������Ҫ����Ԫ�ص�λ��"<<endl;
            int pos1=0;
            cin>>pos1;
            cout<<"������Ҫ�����Ԫ��"<<endl;
            string elem;
            cin>>elem;
            container.insert(pos1,elem);
            }
			break;
        case 6:
            {
                cout<<"������Ҫ��ʾԪ�ص�λ��"<<endl;
                int pos2=0;
                cin>>pos2;
                container.find(pos2);
            }
            break;
        case 7:
            {
                cout<<"������Ҫ��ʾλ�õ�Ԫ��"<<endl;
                string str;
                cin>>str;
                container.at(str);
            }
            break;
        case 8:
            {
                cout<<"�б�Ԫ�صĸ���Ϊ"<<container.length()<<endl;;
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