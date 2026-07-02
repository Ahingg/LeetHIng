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
    ListNode* deleteMiddle(ListNode* head) {
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
        ListNode *slow = nullptr;
        for(int i = (n/2) - 1; i >= 0; i--){
            slow = curr;
            curr = curr->next;
        }
        
        if(n == 1) return head = nullptr;
        if(n == 2) {
            head->next = nullptr;
            return head;
        }

        slow->next = curr->next;
        curr->next = nullptr;
        // free(curr);
        return head;
    }
};