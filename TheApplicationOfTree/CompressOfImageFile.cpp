#include<iostream> 
#include <fstream> 
using namespace std;
 
int main() 
{
    //һ����jpg�ļ�
    // 1. ��ͼƬ�ļ�
    ifstream is("test.png", ifstream::in | ios::binary);
    // 2. ����ͼƬ����
    is.seekg(0, is.end);
    int length = is.tellg();
    cout << length <<endl;
    is.seekg(0, is.beg);
    // 3. �����ڴ滺����
    char * buffer = new char[length];
    // 4. ��ȡͼƬ
    is.read(buffer, length);
    // ���ˣ�ͼƬ�Ѿ��ɹ��ı���ȡ���ڴ棨buffer����
    
 
   //�������Ϊ 223.jpg
   std::string  strFile ;
    for (size_t i = 0; i < length; i++)
    {
        strFile += buffer[i];
    }
    cout<<strFile<<endl;
   //1.�򿪱����ļ���û���Զ�����
    // ofstream fout("D:\\23.jpg" , ios::binary); 
    // if (!fout)
    //     return -1;
    // if (!fout)
    // {
    //     cout << "�ļ����ܴ�" << endl;
    // }
    // else
    // {
    //     //2.����������ļ�
    //     cout << "�ļ���С��" << strFile.size()<< endl;
    //     fout.write(strFile.c_str(), strFile.size());
    //     fout.close(); 
    // }
    delete[] buffer;
    buffer =NULL;
    system("pause");
    return 0;
}
