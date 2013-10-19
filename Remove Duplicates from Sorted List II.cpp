class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode newhead(0), *p = &newhead;
        newhead.next = head;
        while (p->next){
            if (p->next->next && p->next->val == p->next->next->val){
                while (p->next->next &&
                    p->next->val == p->next->next->val){
                    p->next->next = p->next->next->next;
                }
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        return newhead.next;
    }
};
