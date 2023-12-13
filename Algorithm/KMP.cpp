#include<iostream>
#include<string>
using namespace std;

// ģʽ�����ı�����ƥ��
// �����ı�������Ϊn,ģʽ������Ϊm,����ƥ��ģʽ��ʱ�临�Ӷ�ΪO(mn)
// �۲챩��ƥ��Ĺ��̣���aabaabaafƥ��ģʽ��aabaafΪ��
// ����ƥ��Ĺ����У�ÿ��ƥ��ʧ�ܺ󣬶���ģʽ���Ŀ�ͷ����ƥ���ı�����һ��λ�õ��ַ�
// ���У����Թ۲쵽����fƥ��ʧ��ʱ���ı������Ѿ�ƥ���aa��ģʽ�Ӵ�����ô��ʱ�������ģʽ���Ŀ�ͷ��ʼƥ��
// ͬ���ģ������ı�����ƥ��ʧ��ʱҲ�Ǵ�ʧ�ܵ�λ������ƥ��ģʽ�Ӵ�

// ��ô����Ĺؼ������ڣ����ȷ��ģʽ�����¿�ʼƥ���λ��
// �ع�һ�����ǵ��뷨��������Ҫ�ҳ��Ѿ�ƥ����Ŀ��Ը��õ�ģʽ�Ӵ�aa
// ���ڰ���ʧ��λ��f���Ӵ���˵������ǰ׺�Ѿ���ƥ��ɹ�����
// ������ĺ�׺�д�����ǰ׺��ȵĲ��֣���ô��׺����һ���ַ��Ϳ�����Ϊģʽ�����¿�ʼƥ���λ��
// ע�⣬������Ҫ�ҳ��������ȵ�ǰ��׺�����������ģ���ζ���в����Ѿ�ƥ�����ģʽ�Ӵ������ԣ��п��ܵ���ƥ���ʧ��

// ����ǰ׺��
void genNext(int*next, const string&s){
  int j=-1;
  next[0]=j;
  for(int i=1;i<s.size();i++){
    while(j>=0&&s[i]!=s[j+1]){
      j = next[j];
    }
    if(s[i]==s[j+1]){
      j++;
    }
    next[i]=j;
  }
}

int strStr(string haystack,string needle){
  if(needle.size()==0){
    return 0;
  }
  int next[needle.size()];
  genNext(next, needle);
  int j=-1;
  for(int i=0;i<haystack.size();i++){
    while(j>=0&&haystack[i]!=needle[j+1]){
      j=next[j];
    }
    if(haystack[i]==needle[j+1]){
      j++;
    }
    if(j==needle.size()-1){
      return (i-needle.size()+1);
    }
  }
  return -1;
}


int main(){
  string haystack = "aabaabaaf";
  string needle = "aabaaf";
  cout<<"ģʽ���������ı����е��±�Ϊ"<<strStr(haystack,needle)<<endl;
  system("pause");
  return 0;
}