/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {       
        ListNode *w = head;
        ListNode *r = head;

        while(r != NULL && r->next != NULL) {
            w = w->next;
            r = r->next->next;
            if(w == r)
                return true;
        }

        return false;
    }
};