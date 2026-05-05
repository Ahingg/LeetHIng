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
    ListNode* rotateRight(ListNode* head, int k) {
        int cnt = 0;
        ListNode *curr = head;
        ListNode *tail = nullptr;
        while(curr != nullptr) {
            cnt++;
            curr = curr->next;
            if(curr != nullptr && curr->next == nullptr) tail = curr;
        }
        if(!cnt) return head;
        k %= cnt;
        // cout << k << endl;
        if(k == 0) return head;
        else {
            curr = head;
            for(int i = 0; i < cnt - k - 1; i++) curr = curr->next;
            // else 
            // if(cnt == 2) for(int i = 0; i < cnt - k - 1; i++) curr = curr->next;
            // curr->next becomlptr;
            ListNode* tmp = tail;
            tmp->next = head;
            tail = curr;
            head = curr->next;
            tail->next = nullptr;
        }

        return head;
    }
};