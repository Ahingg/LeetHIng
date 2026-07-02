/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> q;
        int n = 0;
        ListNode *h = head;
        while(h != nullptr) {
            n++;
            if(h->next == nullptr) {
                break;
            }
            h = h->next;
        }
        ListNode *curr = head;
        for(int i = (n-1)/2; i >= 0; i--){
            q.push(curr->val);
            curr = curr->next;
        }
        // cout << curr->val << endl;
        int res = -1;
        while(!q.empty()) {
            auto x = q.top();
            q.pop();
            res = max(res, x + curr->val);
            curr = curr->next;
        }
        return res;
    }
};