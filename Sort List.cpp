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
    ListNode *sortList(ListNode *head) {
        if (head == NULL) return NULL;
        int val = head->val;
        ListNode h1(0), h2(0), h3(0), *t1 = &h1, *t2 = &h2, *t3 = &h3;
        for (auto p = head; p; p = p->next){
            if (p->val == val){
                t2 = t2->next = p;
            }else if (p->val < val){
                t1 = t1->next = p;
            }else{
                t3 = t3->next = p;
            }
        }
        t1->next = t2->next = t3->next = NULL;
        h1.next = sortList(h1.next);
        for (t1 = &h1; t1->next; t1 = t1->next);
        t1->next = h2.next;
        t2->next = sortList(h3.next);
        return h1.next;
    }
};
