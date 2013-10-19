class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        for (ListNode *p = head; p && p->next != NULL; p = p->next){
            while (p->next != NULL && p->next->val == p->val){
                p->next = p->next->next;
            }
        }
        return heada;
    }
};
