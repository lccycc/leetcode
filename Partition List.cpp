
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode l(0), r(0), *p = &l, *q = &r;
        while (head){
            if (head->val < x){
                p = p->next = head;
            }else{
                q = q->next = head;
            }
            head = head->next;
        }
        p->next = r.next;
        q->next = NULL;
        return l.next;
    }
};
