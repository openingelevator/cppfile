/*
 * @Author: 郑岱锋 
 * @Date: 2022-09-24 12:14:29 
 * @Last Modified by:   郑岱锋 
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
		cout << "1：显示容器内的内容" << endl;
		cout << "2：退出程序" << endl;
		cout << "3：批量添加数据到列表" << endl;
		cout << "4：移除列表中的数据" << endl;
        cout << "5：在列表特定位置插入数据" << endl;
        cout << "6：输出列表特定位置元素" << endl;
        cout << "7：输出特定元素位置"<<endl;
        cout << "8：显示列表的元素个数"<<endl; 
		cout << "请输入你的选择" << endl;
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
            cout << "请输入要添加的数据个数" << endl;
            int num=0;
            cin>>num;
            for(int i=0;i<num;i++)
            {
                cout<<"请输入学号"<<endl;
                string id;
                cin>>id;
                container.append(id);
            }
            }
			break;
		case 4:
            {
			cout<<"请输入要移除元素的位置"<<endl;
            int pos=0;
            cin>>pos;
            container.remove(pos);
            }
			break;
        case 5:
			{
            cout<<"请输入要插入元素的位置"<<endl;
            int pos1=0;
            cin>>pos1;
            cout<<"请输入要插入的元素"<<endl;
            string elem;
            cin>>elem;
            container.insert(pos1,elem);
            }
			break;
        case 6:
            {
                cout<<"请输入要显示元素的位置"<<endl;
                int pos2=0;
                cin>>pos2;
                container.find(pos2);
            }
            break;
        case 7:
            {
                cout<<"请输入要显示位置的元素"<<endl;
                string str;
                cin>>str;
                container.at(str);
            }
            break;
        case 8:
            {
                cout<<"列表元素的个数为"<<container.length()<<endl;;
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