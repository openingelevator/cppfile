#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return head;
        stack<ListNode*> st;
        ListNode* cur = head;
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->next;
        }
        cur = st.top();
        head = cur;
        st.pop();
        while (!st.empty()) {
            cur->next = st.top();
            st.pop();
            cur = cur->next;
        }
        cur->next=nullptr;
        return head;
    }
};
int main()
{
    ListNode*head=new ListNode(1);
    head->next=new ListNode(2);
    Solution s=Solution();
    s.reverseList(head);
    system("pause");
    return 0;
}