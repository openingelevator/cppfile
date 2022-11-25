#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//pseudocode
	// ��һ������󲿷�Ԫ��Ϊ0������Ϊͬһ��ֵ������ʱ������ʹ��ϡ���������������
	// ����ʽΪ����¼������һ���м��м��У��ж��ٸ���ͬ��ֵ
	// �Ѿ��в�ֵͬ��Ԫ�ص����м�ֵ��¼��һ��С��ģ�������У��Ӷ���С����Ĺ�ģ
	//���������̲���ϡ������(sparseArray)�洢

	//����ԭʼ��ά����
	int** chessArray = new int*[11];
	for (int i = 0; i < 11; i++)
	{
		*(chessArray + i) = new int [11];
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			chessArray[i][j]=0;
		}
	}
	//��ά���鸳ֵ
	chessArray[1][2] = 1;
	chessArray[2][3] = 2;
	chessArray[4][5] = 1;

	//��ά����תϡ������
    //������ά���飬�õ���Ч���ݵĸ���sum
	int sum = 0;
	for(int i=0;i<11;i++)
		for (int j = 0; j < 11; j++)
		{
			if (chessArray[i][j] != 0)
				sum += 1;
		}

    //����sum���Դ���ϡ������sparseArray[sum+1][3]
	int** sparseArray = new int* [sum+1];
	for (int i = 0; i < sum+1; i++)
	{
		*(sparseArray + i) = new int[3];
	}
    //����ά�������Ч���ݴ��뵽ϡ������
	//ϡ�������һ�и�ֵ
	sparseArray[0][0] = 11;
	sparseArray[0][1] = 11;
	sparseArray[0][2] = sum;
	//������ά���飬������Ԫ�ش�ŵ�ϡ��������
	int count = 0;
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
		{
			if (chessArray[i][j] != 0)
			{
				++count;
				sparseArray[count][0] = i;
				sparseArray[count][1] = j;
				sparseArray[count][2] = chessArray[i][j];
			}
		}
	//��ϡ������д�����
	ofstream ofs;
	ofs.open("map.txt", ios::out);
	if (!ofs.is_open())
	{
		cerr << "�ļ��޷���";
		return -1;
	}
	//��ӡϡ������
	cout << "ת��Ϊϡ�������" << endl;
	for (int i = 0; i < sum + 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ofs << sparseArray[i][j]<< " ";
			cout << sparseArray[i][j]<<" ";
		}
		cout << endl;
	}
	ofs.close();


	//ϡ������ת��ά����
    //�ȶ�ȡϡ������ĵ�һ��
	int row = sparseArray[0][0];
	int col = sparseArray[0][1];
    //���ݵ�һ�е����ݴ���ԭʼ�Ķ�ά����chessArray[][]
	int** originalArray = new int* [row];
	for (int i = 0; i < row; i++)
	{
		*(originalArray + i) = new int[col];
	}
	for(int i=0;i<row;i++)
		for (int j = 0; j < col; j++)
		{
			originalArray[i][j] = 0;
		}
    //�ٶ�ȡϡ��������е����ݲ�����ԭʼ�Ķ�ά���鼴��
	for (int i = 1; i < sparseArray[0][2] + 1; i++)
	{
		originalArray[sparseArray[i][0]][sparseArray[i][1]] = sparseArray[i][2];
	}
	//��ӡԭ��������
	cout << "�ָ��������Ϊ" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout<<originalArray[i][j]<<" ";
		}
		cout << endl;
	}

	//�ͷŶ������ڴ�
	for (int i = 0; i < 11; i++)
	{
		delete[] * (chessArray + i);
		delete[] * (originalArray + i);
	}
	for (int i = 0; i < 3; i++)
	{
		delete[] * (sparseArray + i);
	}
	delete[]sparseArray;
	delete[]chessArray;
	delete[]originalArray;
	return 0;
}