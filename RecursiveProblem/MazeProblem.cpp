#include<iostream>
using namespace std;
//�ݹ�ע������
//ִ��һ������ʱ���ʹ���һ���µ��ܱ����Ķ����ռ�
//�����ľֲ������Ƕ����ģ������໥Ӱ��
//�ݹ�������˳��ݹ�������ƽ�
//��һ������ִ����֮�󣬻�������return�ͻ᷵�أ���ѭ˭���ã��ͽ�������ظ�˭ 
//���������ʹ�õ����������ͱ������ͻṲ����������͵�����

//map��ʾ��ͼ��i,j��ʾλ�ã��Ӵ�λ�����ҵ�ͨ·�򷵻��棬���򷵻ؼ�
bool setWay(int map[8][7], int i, int j)
{
	//��ʾ�ҵ��յ�
	if(map[6][5]==2)
	{
		return true;
	}
	else
	{
			if (map[i][j] == 0)//��ʾ�˵�δ����
			{
				//�ٶ��õ�����ͨ
				map[i][j] = 2;
				//������
				if (setWay(map, i+1, j))
				{
					return true;
				}//������
				else if (setWay(map, i, j+1))
				{
					return true;
				}//������
				else if (setWay(map, i - 1, j))
				{
					return true;
				}//������
				else if (setWay(map, i, j - 1))
				{
					return true;
				}
				else
				{
					//˵���õ��߲�ͨ
					map[i][j] = 3;
					return false;
				}
			}
			else
			{
				return false;
			}
	}

}
int main()
{
	//��ά����ģ���Թ�
	int map[8][7] = {};
	//ʹ��1��ʾǽ��0��ʾ�õ�δ���ʹ�����map[6][5]Ϊ�յ㣬2��ʾͨ·��3��ʾ�õ��Ѿ��߹������߲�ͨ
	//�Թ����ײ��ԣ���->��->��->��
	for (int row = 0; row < 8; row++)
	{
		map[row][0] = 1;
		map[row][6] = 1;
	}
	for (int col = 0; col < 7; col++)
	{
		map[0][col] = 1;
		map[7][col] = 1;
	}
	//���ö����ǽ
	map[3][1] = map[3][2] = 1;

	//ʹ�õݹ��������С����·
	cout << "��ͼ�����" << endl;
	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 7; j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	setWay(map, 1, 1);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
