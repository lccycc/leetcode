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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL) return head;
        ListNode h(0);
        for (ListNode* p = head, *tmp; p; p = tmp){
            tmp = p->next;
            for (auto q = &h; q; q = q->next){
                if (q->next == NULL || q->next->val >= p->val){
                    p->next = q->next;
                    q->next = p;
                    break;
                }
            }
        }
        return h.next;
    }
};
