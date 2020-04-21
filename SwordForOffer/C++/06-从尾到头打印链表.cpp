/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *p = head;
        stack<int> stk;
        vector<int> result;
        while (p != NULL) {
            stk.push(p -> val);
            p = p -> next;
        }
        int len = stk.size();
        for (int i = 0; i < len; i++) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};

