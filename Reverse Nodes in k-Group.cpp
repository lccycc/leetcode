
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *newhead = new ListNode(0);
        newhead->next = head;
        ListNode *p = newhead, *q;
        while (true){
            int cnt = 0;
            for (q = p; q->next != NULL && cnt < k; q = q->next){
                cnt++;
            }
            if (cnt < k){
                break;
            }
            ListNode *f = p->next, *g = q->next;
            q = p->next;
            while (cnt--){
                ListNode *tmp = f->next;
                f->next = g;
                g = f;
                f = tmp;
            }
            p->next = g;
            p = q;
        }
        head = newhead->next;
        free(newhead);
        return head;
    }
};
