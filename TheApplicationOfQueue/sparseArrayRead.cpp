#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	fstream ifs;
	ifs.open("map.txt", ios::in|ios::out);
	if (!ifs.is_open())
	{
		cerr << "文件未打开" << endl;
		return -1;
	}
	cout << ifs.tellg() << endl;
	int sum = 0;
	int num;
	while (ifs >> num)
	{
		sum++;
	}
	/*cout << sum;*/
	cout << ifs.tellg() << endl;

	//https://blog.csdn.net/hou09tian/article/details/112763917?ops_request_misc=&request_id=&biz_id=102&utm_term=%E5%B0%86%E8%BE%93%E5%85%A5%E8%BE%93%E5%87%BA%E6%B5%81%E7%9A%84%E7%8A%B6%E6%80%81%E8%AE%BE%E7%BD%AE%E4%B8%BAgoodbit&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-112763917.142^v32^pc_rank_34,185^v2^control&spm=1018.2226.3001.4187
	//当首次读文件读到文件尾时，需要将eof状态清除并设置为ios::goodbit状态才可以重新将文件指针移动到开头
	ifs.clear();
	ifs.seekg(0, ios::beg);
	cout << ifs.tellg() << endl;


	int** sparseArray = new int* [sum/3];
	for (int i = 0; i < sum/3; i++)
	{
		*(sparseArray + i) = new int[3];
	}

	for (int i = 0; i < sum / 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ifs >> sparseArray[i][j];
		}
	
	}

	for (int i = 0; i < sum/3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << sparseArray[i][j] << " ";
		}
		cout << endl;
	}


	for (int i = 0; i < 3; i++)
	{
		delete[] * (sparseArray + i);
	}
	delete[]sparseArray;
	ifs.close();
	return 0;
}