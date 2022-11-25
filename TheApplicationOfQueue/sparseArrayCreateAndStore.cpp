#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	//pseudocode
	// 当一个数组大部分元素为0，或者为同一个值的数组时，可以使用稀疏数组来存该数组
	// 处理方式为：记录该数组一共有几行几列，有多少个不同的值
	// 把具有不同值的元素的行列及值记录在一个小规模的数组中，从而缩小程序的规模
	//五子棋棋盘采用稀疏数组(sparseArray)存储

	//创建原始二维数组
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
	//二维数组赋值
	chessArray[1][2] = 1;
	chessArray[2][3] = 2;
	chessArray[4][5] = 1;

	//二维数组转稀疏数组
    //遍历二维数组，得到有效数据的个数sum
	int sum = 0;
	for(int i=0;i<11;i++)
		for (int j = 0; j < 11; j++)
		{
			if (chessArray[i][j] != 0)
				sum += 1;
		}

    //根据sum可以创建稀疏数组sparseArray[sum+1][3]
	int** sparseArray = new int* [sum+1];
	for (int i = 0; i < sum+1; i++)
	{
		*(sparseArray + i) = new int[3];
	}
    //将二维数组的有效数据存入到稀疏数组
	//稀疏数组第一行赋值
	sparseArray[0][0] = 11;
	sparseArray[0][1] = 11;
	sparseArray[0][2] = sum;
	//遍历二维数组，将非零元素存放到稀疏数组中
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
	//将稀疏数组写入磁盘
	ofstream ofs;
	ofs.open("map.txt", ios::out);
	if (!ofs.is_open())
	{
		cerr << "文件无法打开";
		return -1;
	}
	//打印稀疏数组
	cout << "转化为稀疏数组后" << endl;
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


	//稀疏数组转二维数组
    //先读取稀疏数组的第一行
	int row = sparseArray[0][0];
	int col = sparseArray[0][1];
    //根据第一行的数据创建原始的二维数组chessArray[][]
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
    //再读取稀疏数组后几行的数据并赋给原始的二维数组即可
	for (int i = 1; i < sparseArray[0][2] + 1; i++)
	{
		originalArray[sparseArray[i][0]][sparseArray[i][1]] = sparseArray[i][2];
	}
	//打印原来的数组
	cout << "恢复后的数组为" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout<<originalArray[i][j]<<" ";
		}
		cout << endl;
	}

	//释放堆区的内存
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