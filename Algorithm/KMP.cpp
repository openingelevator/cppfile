#include<iostream>
#include<string>
using namespace std;

// 模式串与文本串的匹配
// 假设文本串长度为n,模式串长度为m,暴力匹配模式的时间复杂度为O(mn)
// 观察暴力匹配的过程，以aabaabaaf匹配模式串aabaaf为例
// 暴力匹配的过程中，每次匹配失败后，都从模式串的开头重新匹配文本串下一个位置的字符
// 其中，可以观察到，在f匹配失败时，文本串中已经匹配过aa的模式子串，那么此时就无需从模式串的开头开始匹配
// 同样的，对于文本串，匹配失败时也是从失败的位置重新匹配模式子串

// 那么问题的关键就在于，如何确定模式串重新开始匹配的位置
// 回顾一下我们的想法，我们想要找出已经匹配过的可以复用的模式子串aa
// 对于包含失败位置f的子串来说，它的前缀已经是匹配成功的了
// 如果它的后缀中存在与前缀相等的部分，那么后缀的下一个字符就可以作为模式串重新开始匹配的位置
// 注意，我们需要找出的是最长相等的前后缀，如果不是最长的，意味着有部分已经匹配过的模式子串被忽略，有可能导致匹配的失败

// 制作前缀表
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
  cout<<"模式串出现在文本串中的下标为"<<strStr(haystack,needle)<<endl;
  system("pause");
  return 0;
}