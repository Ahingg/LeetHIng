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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1;

        // pake pointer atau double next
        // next jadi pointer, next->next jadi checker
        ListNode* temp = head;
        int minAns = 1e9;
        int i = 1;
        while(temp->next->next != nullptr) {
            int val = temp->next->val;
            if((val > temp->val && val > temp->next->next->val) || (val < temp->val && val < temp->next->next->val) ) {
                if(first == -1) first = i;
                if(last != -1) minAns = min(i - last, minAns);
                // cout << last << " " << i << endl;
                last = i;
            }
            temp = temp->next;
            i++;
        }
        if(first == -1 || last == -1 || minAns == 1e9)  return {-1, -1};
        return {minAns, last-first};
    }
};