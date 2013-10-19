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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode newhead(0), *tail = &newhead;
        while (l1 || l2){
            if (l1 && (!l2 || l1->val < l2->val)){
                tail = tail->next = l1;
                l1 = l1->next;
            }else{
                tail = tail->next = l2;
                l2 = l2->next;
            }
        }
        tail->next = NULL;
        return newhead.next;
    }
};
