#include<iostream>
using namespace std;
//递归注意事项
//执行一个方法时，就创建一个新的受保护的独立空间
//方法的局部变量是独立的，不会相互影响
//递归必须向退出递归的条件逼近
//当一个方法执行完之后，或者遇到return就会返回，遵循谁调用，就将结果返回给谁 
//如果方法中使用的是引用类型变量，就会共享该引用类型的数据

//map表示地图，i,j表示位置，从此位置能找到通路则返回真，否则返回假
bool setWay(int map[8][7], int i, int j)
{
	//表示找到终点
	if(map[6][5]==2)
	{
		return true;
	}
	else
	{
			if (map[i][j] == 0)//表示此点未访问
			{
				//假定该点能走通
				map[i][j] = 2;
				//向下走
				if (setWay(map, i+1, j))
				{
					return true;
				}//向右走
				else if (setWay(map, i, j+1))
				{
					return true;
				}//向上走
				else if (setWay(map, i - 1, j))
				{
					return true;
				}//向左走
				else if (setWay(map, i, j - 1))
				{
					return true;
				}
				else
				{
					//说明该点走不通
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
	//二维数组模拟迷宫
	int map[8][7] = {};
	//使用1表示墙，0表示该点未访问过，记map[6][5]为终点，2表示通路，3表示该点已经走过但是走不通
	//迷宫简易策略：下->右->上->左
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
	//设置额外的墙
	map[3][1] = map[3][2] = 1;

	//使用递归回溯来给小球找路
	cout << "地图的情况" << endl;
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
