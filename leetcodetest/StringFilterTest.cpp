#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int num;
    cin >> num; // 注意 while 处理多个 case
    vector<string>result;
    for (int i = 0; i < num; i++) {
        string temp;
        string res;
        int flag = false;
        cin >> temp;
        stack<int>st;
        st.push(0);
        for (int j = 1; j < temp.size(); j++) {
            int top = st.top();
            if (temp[top] == temp[j]) {
                if (top > 0 && temp[top] == temp[top - 1]) {
                    flag=true;
                    continue;
                }
                if (flag) {
                  if(j+1<temp.size()&&temp[j]!=temp[j+1]){
                    flag = false;
                  }
                  continue;
                } else {
                    flag = true;
                }
                st.push(j);
            } else {
                st.push(j);
                if (j + 1 < temp.size() && temp[j] != temp[j + 1]) {
                    flag = false;
                }
            }
        }
        deque<int>index;
        while (!st.empty()) {
            index.push_front(st.top());
            st.pop();
        }
        // for (auto i : index) {
        //     cout << i << " ";
        // }
        for(int k=0;k<index.size();k++){
            res+=temp[index[k]];
        }
        result.push_back(res);
    }
    for(auto s:result){
      cout<<s<<endl;
    }
    system("pause");
    return 0;
}
// 64 位输出请用 printf("%lld")