#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include<chrono>
using namespace std;
const int SIZE1 = 100;
const int SIZE2 = 1000;
const int SIZE3 = 10000;
typedef chrono::high_resolution_clock Clock;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
//插入排序
void insertionSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        for (int j = i; j > 0; --j)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}
void insertionSort(vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        for (int j = i; j > left; --j)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

//冒泡排序
void bubbleSort(vector<int> &arr)
{
    for (int i = arr.size() - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//选择排序
void selectSort(vector<int> &arr)
{
    for (int i = arr.size() - 1; i > 0; --i)
    {
        int maxValue = 0;
        int maxIndex = 0;
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] > maxValue)
            {
                maxValue = arr[j];
                maxIndex = j;
            }
        }
        swap(arr[i], arr[maxIndex]);
    }
}

// arr待调整的数组，i表示非叶子结点在数组中的索引，length表示对多少个元素继续调整
void adjustHeap(vector<int> &arr, int i, int length)
{
    int temp = arr[i]; //先取出当前元素的值保存在临时变量
    //开始调整
    for (int k = i * 2 + 1; k < length; k = k * 2 + 1)
    {
        if (k + 1 < length)
        {
            //说明左子结点的值小于右子结点的值
            if (arr[k] < arr[k + 1])
                k++;
        }
        if (arr[k] > temp)
        { 
            //如果子结点大于父结点
            arr[i] = arr[k];
            i = k;
        }
        else
        {
            break;
        }
    }
    //当循环结束后，我们已经将以i为父结点的树的最大值放在了堆顶上
    arr[i] = temp;
}
void heapSort(vector<int> &arr)
{
    //构建大顶堆
    for (int i = arr.size() / 2; i >= 0; i--)
    {
        adjustHeap(arr, i, arr.size());
    }
    for (int j = arr.size() - 1; j > 0; j--)
    {
        //交换
        swap(arr[0], arr[j]);
        adjustHeap(arr, 0, j);
        //     for(auto i:arr){
        //     cout<<i<<",";
        // }
    }
}

//快速排序
int medianThree(vector<int> &arr, int left, int right)
{
    int median = (left + right) / 2;
    if (arr[median] < arr[left])
    {
        swap(arr[left], arr[median]);
    }
    if (arr[right] < arr[left])
    {
        swap(arr[right], arr[left]);
    }
    if (arr[right] < arr[median])
    {
        swap(arr[right], arr[median]);
    }
    swap(arr[median], arr[right - 1]);
    return arr[right - 1];
}
void quickSort(vector<int> &arr, int left, int right)
{
    if (left + 10 <= right)
    {
        const int &pivot = medianThree(arr, left, right);
        int i = left;
        int j = right - 1;
        while (true)
        {
            while (arr[++i] < pivot)
            {
            }
            while (arr[--j] > pivot)
            {
            }
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
            else
            {
                break;
            }
        }
        swap(arr[i], arr[right - 1]);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    }
    else
    {
        insertionSort(arr, left, right);
    }
}

//归并排序
void merge(vector<int> &arr, vector<int> &temp, int left, int right)
{
    int mid = (left + right) / 2;
    int i = left;
    int j = mid + 1;
    int target = left;
    //对两个有序区间进行合并
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[target] = arr[i];
            i++;
        }
        else
        {
            temp[target] = arr[j];
            j++;
        }
        target++;
    }
    //左半边排序完成，直接把辅助数组里面的内容拷贝到原数组中
    if (i > mid)
    {
        for (int k = left; k < target; k++)
        {
            arr[k] = temp[k];
        }
    }
    //右半边排序完成，先把左半边较大的数拷贝到原数组的最右端
    //再将辅助数组里面的内容拷贝到原数组，完成两个有序区间的合并
    if (j > right)
    {
        int p = mid;
        int q = right;
        while (p >= i)
        {
            arr[q] = arr[p];
            p--;
            q--;
        }
        for (int k = left; k < target; k++)
        {
            arr[k] = temp[k];
        }
    }
}
void mergeSort(vector<int> &arr, vector<int> &temp, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, right);
}

//基数排序
int maxDigit(const vector<int> &arr)
{
    int len = arr.size();
    int digit = 1;
    int p = 10;
    for (int i = 0; i < len; ++i)
    {
        while (arr[i] > p)
        {
            digit++;
            p *= 10;
        }
    }
    return digit;
}
void radixSort(vector<int> &arr)
{
    int digit = maxDigit(arr);
    int size = arr.size();
    int k = 0;
    int radix = 1;
    vector<int> cnt(10);
    vector<int> temp(size);
    for (int i = 0; i < digit; ++i)
    {
        fill(cnt.begin(), cnt.end(), 0);
        for (int j = 0; j < size; ++j)
        {
            k = (arr[j] / radix) % 10;
            cnt[k]++;
        }
        for (int j = 1; j < 10; ++j)
        {
            cnt[j] = cnt[j] + cnt[j - 1];
        }
        for (int j = size - 1; j >= 0; --j)
        {
            k = (arr[j] / radix) % 10;
            temp[cnt[k] - 1] = arr[j];
            cnt[k]--;
        }
        copy(temp.begin(), temp.end(), arr.begin());
        radix *= 10;
    }
}

int main()
{
    time_t begin1, end1;
    time_t begin2, end2;
    time_t begin3, end3;
    vector<int> v1(SIZE1);
    vector<int>temp1(SIZE1);
    vector<int> v2(SIZE2);
    vector<int>temp2(SIZE2);
    vector<int> v3(SIZE3);
    vector<int>temp3(SIZE3);
    for (int i = 0; i < SIZE1; ++i)
    {
        v1[i] = rand() % 200;
         temp1[i]=0;
        // cout<<v1[i]<<",";
        // if((i+1)%10==0)cout<<endl;
    }
    for (int i = 0; i < SIZE2; ++i)
    {
        v2[i] = rand() % 2000;
        temp2[i]=0;
        // cout<<v2[i]<<",";
        // if((i+1)%10==0)cout<<endl;
    }
    for (int i = 0; i < SIZE3; ++i)
    {
        v3[i] = rand() % 20000;
        temp3[i]=0;
        // cout<<v3[i]<<",";
        // if((i+1)%10==0)cout<<endl;
    }
    // int choice = 0;
    // while (true)
    // {
    //     cout << "0:请选择所要测试的排序算法" << endl;
    //     cout << "1:插入排序" << endl;
    //     cout << "2:冒泡排序" << endl;
    //     cout << "3:选择排序" << endl;
    //     cout << "4:堆排序" << endl;
    //     cout << "5:快速排序" << endl;
    //     cout << "6:归并排序" << endl;
    //     cout << "7:基数排序" << endl;
    //     cout << "8:退出程序" << endl;
    //     cout << "请输入你的选择" << endl;
    //     cin >> choice;
    //     switch (choice)
    //     {
    //     case 1:
    //         {
    //             begin1=clock();
    //             insertionSort(v1);
    //             end1=clock();
    //             cout<<"100组数据使用插入排序运行时间为"<<end1-begin1<<"ms"<<endl;
    //             begin2=clock();
    //             insertionSort(v2);
    //             end2=clock();
    //             cout<<"1000组数据使用插入排序运行时间为"<<end2-begin2<<"ms"<<endl;
    //             begin3=clock();
    //             insertionSort(v3);
    //             end3=clock();
    //             cout<<"10000组数据使用插入排序运行时间为"<<end3-begin3<<"ms"<<endl;
    //         }
    //         break;
    //     case 2:
    //         {
    //             begin1=clock();
    //             bubbleSort(v1);
    //             end1=clock();
    //             cout<<"100组数据使用冒泡排序运行时间为"<<end1-begin1<<"ms"<<endl;
    //             begin2=clock();
    //             bubbleSort(v2);
    //             end2=clock();
    //             cout<<"1000组数据使用冒泡排序运行时间为"<<end2-begin2<<"ms"<<endl;
    //             begin3=clock();
    //             bubbleSort(v3);
    //             end3=clock();
    //             cout<<"10000组数据使用冒泡排序运行时间为"<<end3-begin3<<"ms"<<endl;
    //         }
    //         break;
    //     case 3:
    //         {
    //             begin1=clock();
    //             selectSort(v1);
    //             end1=clock();
    //             cout<<"100组数据使用选择排序运行时间为"<<end1-begin1<<"ms"<<endl;
    //             begin2=clock();
    //             selectSort(v2);
    //             end2=clock();
    //             cout<<"1000组数据使用选择排序运行时间为"<<end2-begin2<<"ms"<<endl;
    //             begin3=clock();
    //             selectSort(v3);
    //             end3=clock();
    //             cout<<"10000组数据使用选择排序运行时间为"<<end3-begin3<<"ms"<<endl;
    //         }
    //     break;
    //     case 4:
    //         {
    //             begin1=clock();
    //             heapSort(v1);
    //             end1=clock();
    //             cout<<"100组数据使用堆排序运行时间为"<<end1-begin1<<"ms"<<endl;
    //             begin2=clock();
    //             heapSort(v2);
    //             end2=clock();
    //             cout<<"1000组数据使用堆排序运行时间为"<<end2-begin2<<"ms"<<endl;
    //             begin3=clock();
    //             heapSort(v3);
    //             end3=clock();
    //             cout<<"10000组数据使用堆排序运行时间为"<<end3-begin3<<"ms"<<endl;
    //         }
    //     break;
    //     case 5:
    //         {
    //             begin1=clock();
    //             quickSort(v1,0,SIZE1-1);
    //             end1=clock();
    //             cout<<"100组数据使用快速排序运行时间为"<<end1-begin1<<"ms"<<endl;
    //             begin2=clock();
    //             quickSort(v2,0,SIZE2-1);
    //             end2=clock();
    //             cout<<"1000组数据使用快速排序运行时间为"<<end2-begin2<<"ms"<<endl;
    //             begin3=clock();
    //             quickSort(v3,0,SIZE3-1);
    //             end3=clock();
    //             cout<<"10000组数据使用快速排序运行时间为"<<end3-begin3<<"ms"<<endl;
    //         }
    //     break;
    //     case 6:
    //         {
    //             begin1=clock();
    //             mergeSort(v1,temp1,0,SIZE1-1);
    //             end1=clock();
    //             cout<<"100组数据使用归并排序运行时间为"<<end1-begin1<<"ms"<<endl;
    //             begin2=clock();
    //              mergeSort(v2,temp2,0,SIZE2-1);
    //             end2=clock();
    //             cout<<"1000组数据使用归并排序运行时间为"<<end2-begin2<<"ms"<<endl;
    //             begin3=clock();
    //             mergeSort(v3,temp3,0,SIZE3-1);
    //             end3=clock();
    //             cout<<"10000组数据使用归并排序运行时间为"<<end3-begin3<<"ms"<<endl;
    //         }
    //     break;
    //     case 7:
    //         {
    //             begin1=clock();
    //             radixSort(v1);
    //             end1=clock();
    //             cout<<"100组数据使用基数排序运行时间为"<<end1-begin1<<"ms"<<endl;
    //             begin2=clock();
    //             radixSort(v2);
    //             end2=clock();
    //             cout<<"1000组数据使用基数排序运行时间为"<<end2-begin2<<"ms"<<endl;
    //             begin3=clock();
    //             radixSort(v3);
    //             end3=clock();
    //             cout<<"10000组数据使用基数排序运行时间为"<<end3-begin3<<"ms"<<endl;
    //         }
    //     break;
    //     case 8:
    //         exit(0);
    //     break;
    //     default:
    //         break;
    //     }
    //     system("pause");
    //     system("cls");
    // }
    system("pause");
    return 0;
}