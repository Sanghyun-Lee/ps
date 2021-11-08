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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode *point1 = dummy;
        ListNode *point2 = dummy;
        
        for(int i = 0; i <= n; i++) {
            point2 = point2->next;
        }
        
        while(point2 != NULL) {
            point1 = point1->next;
            point2 = point2->next;
        }
        point1->next = point1->next->next;

        return dummy->next;
    }
};