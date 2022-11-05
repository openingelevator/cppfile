#include<iostream> 
#include <fstream> 
using namespace std;
 
int main() 
{
    //一、打开jpg文件
    // 1. 打开图片文件
    ifstream is("test.png", ifstream::in | ios::binary);
    // 2. 计算图片长度
    is.seekg(0, is.end);
    int length = is.tellg();
    cout << length <<endl;
    is.seekg(0, is.beg);
    // 3. 创建内存缓存区
    char * buffer = new char[length];
    // 4. 读取图片
    is.read(buffer, length);
    // 到此，图片已经成功的被读取到内存（buffer）中
    
 
   //二、另存为 223.jpg
   std::string  strFile ;
    for (size_t i = 0; i < length; i++)
    {
        strFile += buffer[i];
    }
    cout<<strFile<<endl;
   //1.打开保存文件，没有自动创建
    // ofstream fout("D:\\23.jpg" , ios::binary); 
    // if (!fout)
    //     return -1;
    // if (!fout)
    // {
    //     cout << "文件不能打开" << endl;
    // }
    // else
    // {
    //     //2.输出到磁盘文件
    //     cout << "文件大小：" << strFile.size()<< endl;
    //     fout.write(strFile.c_str(), strFile.size());
    //     fout.close(); 
    // }
    delete[] buffer;
    buffer =NULL;
    system("pause");
    return 0;
}
